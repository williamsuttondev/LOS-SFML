#include "TMJParser.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <tinyxml2.h>
#include <filesystem>

TMJParser::TMJParser(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filePath);
    }

    file >> m_root;
    file.close();
    
    std::filesystem::path tmjPath(filePath);
    std::filesystem::path baseDir = tmjPath.parent_path();

    parseTilesets(baseDir);
    parseLayers();
}

const std::vector<sf::Sprite>& TMJParser::getLayerSprites() const {
    return m_layerSprites;
}

void TMJParser::parseTilesets(const std::filesystem::path& baseDir) {
    for (const auto& tileset : m_root["tilesets"]) {
        std::string tsxFilePath = tileset["source"].get<std::string>();
        std::filesystem::path tsxFullPath = baseDir / tsxFilePath;
        std::string imageSource = getTilesetImageSource(tsxFullPath.string());
        
        sf::Texture texture;
        if (!texture.loadFromFile(imageSource)) {
            throw std::runtime_error("Unable to load tileset image: " + imageSource);
        }
        m_tilesetTextures.push_back(std::move(texture));
        
        m_tilesetSources.push_back(imageSource);
        m_firstGids.push_back(tileset["firstgid"].get<int>());
    }
}

void TMJParser::parseLayers() {
    int layerIndex = 0;
    for (const auto& layer : m_root["layers"]) {
        if (layer["type"].get<std::string>() == "tilelayer") {
            parseTileLayer(layer, layerIndex++);
        }
    }
}

void TMJParser::parseTileLayer(const nlohmann::json& layer, int layerIndex) {
    int width = layer["width"].get<int>();
    int height = layer["height"].get<int>();
    const nlohmann::json& data = layer["data"];

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int index = y * width + x;
            int tileID = data[index].get<int>();

            if (tileID == 0) {
                continue;
            }

            std::string tilesetSource = getTilesetSource(tileID);
            const sf::Texture& tilesetTexture = m_tilesetTextures[layerIndex];

            int firstGid = m_firstGids[layerIndex];
            int adjustedTileID = tileID - firstGid;
            int columns = tilesetTexture.getSize().x / 32;
            int row = adjustedTileID / columns;
            int col = adjustedTileID % columns;

            sf::Sprite sprite;
            sprite.setTexture(tilesetTexture);
            sprite.setTextureRect(sf::IntRect(col * 32, row * 32, 32, 32));
            sprite.setPosition(static_cast<float>(x * 32), static_cast<float>(y * 32));
            m_layerSprites.push_back(sprite);
        }
    }
}

std::string TMJParser::getTilesetSource(int tileID) {
    for (size_t i = 0; i < m_tilesetSources.size(); ++i) {
        if (tileID >= m_firstGids[i] && (i == m_tilesetSources.size() - 1 || tileID < m_firstGids[i + 1])) {
            return m_tilesetSources[i];
        }
    }
    throw std::runtime_error("Tileset source not found for tileID: " + std::to_string(tileID));
}

std::string TMJParser::getTilesetImageSource(const std::string& tsxFilePath) {
    tinyxml2::XMLDocument doc;
    if (doc.LoadFile(tsxFilePath.c_str()) != tinyxml2::XML_SUCCESS) {
        throw std::runtime_error("Unable to load TSX file: " + tsxFilePath);
    }

    tinyxml2::XMLElement* root = doc.RootElement();
    tinyxml2::XMLElement* imageElement = root->FirstChildElement("image");
    if (!imageElement) {
        throw std::runtime_error("No image element found in TSX file: " + tsxFilePath);
    }

    const char* source = imageElement->Attribute("source");
    if (!source) {
        throw std::runtime_error("No source attribute found in image element of TSX file: " + tsxFilePath);
    }

    std::filesystem::path tsxPath(tsxFilePath);
    std::filesystem::path imagePath = tsxPath.parent_path() / source;

    return imagePath.string();
}