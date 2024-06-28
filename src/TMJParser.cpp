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
    
    // Extract base directory from the TMJ file path
    std::filesystem::path tmjPath(filePath);
    std::filesystem::path baseDir = tmjPath.parent_path();

    parseTilesets(baseDir);
    parseLayers();
}

const std::vector<sf::Image>& TMJParser::getLayerImages() const {
    return m_layerImages;
}

void TMJParser::parseTilesets(const std::filesystem::path& baseDir) {
    for (const auto& tileset : m_root["tilesets"]) {
        std::string tsxFilePath = tileset["source"].get<std::string>();
        std::filesystem::path tsxFullPath = baseDir / tsxFilePath;
        std::string imageSource = getTilesetImageSource(tsxFullPath.string());
        m_tilesetSources.push_back(imageSource);
        m_firstGids.push_back(tileset["firstgid"].get<int>());
    }
}

void TMJParser::parseLayers() {
    for (const auto& layer : m_root["layers"]) {
        if (layer["type"].get<std::string>() == "tilelayer") {
            parseTileLayer(layer);
        }
    }
}

void TMJParser::parseTileLayer(const nlohmann::json& layer) {
    int width = layer["width"].get<int>();
    int height = layer["height"].get<int>();
    const nlohmann::json& data = layer["data"];

    // Create a large image for the entire layer
    sf::Image layerImage;
    layerImage.create(width * 32, height * 32, sf::Color::Transparent);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int index = y * width + x;
            int tileID = data[index].get<int>();

            if (tileID == 0) {
                continue; // Already transparent, no need to set explicitly
            }

            // Determine the source of the tileset for this tile
            std::string tilesetSource = getTilesetSource(tileID);
            sf::Image tileImage = loadTileImage(tilesetSource, tileID);

            // Draw the tile onto the layer image
            layerImage.copy(tileImage, x * 32, y * 32);
        }
    }

    m_layerImages.push_back(layerImage);
}


std::string TMJParser::getTilesetSource(int tileID) {
    for (size_t i = 0; i < m_tilesetSources.size(); ++i) {
        if (tileID >= m_firstGids[i] && (i == m_tilesetSources.size() - 1 || tileID < m_firstGids[i + 1])) {
            return m_tilesetSources[i];
        }
    }
    throw std::runtime_error("Tileset source not found for tileID: " + std::to_string(tileID));
}

sf::Image TMJParser::loadTileImage(const std::string& tilesetSource, int tileID) {
    sf::Image tileset;
    if (!tileset.loadFromFile(tilesetSource)) {
        throw std::runtime_error("Unable to load tileset: " + tilesetSource);
    }

    // Calculate the position of the tile in the tileset
    int firstGid = 1; // Default to 1 if not found (shouldn't typically happen)
    for (size_t i = 0; i < m_firstGids.size(); ++i) {
        if (m_tilesetSources[i] == tilesetSource) {
            firstGid = m_firstGids[i];
            break;
        }
    }

    int adjustedTileID = tileID - firstGid;
    int columns = tileset.getSize().x / 32;
    int row = adjustedTileID / columns;
    int col = adjustedTileID % columns;

    sf::Image tile;
    tile.create(32, 32, sf::Color::Transparent); // Ensure transparency
    tile.copy(tileset, 0, 0, sf::IntRect(col * 32, row * 32, 32, 32), true);

    return tile;
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

    // Get the base directory of the TSX file
    std::filesystem::path tsxPath(tsxFilePath);
    std::filesystem::path imagePath = tsxPath.parent_path() / source;

    return imagePath.string();
}