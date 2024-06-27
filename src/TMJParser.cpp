#include "TMJParser.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <tinyxml2.h>
#include <json.hpp>


TMJParser::TMJParser(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filePath);
    }

    file >> m_root;
    file.close();
    parseTilesets();
    parseLayers();
}

const std::vector<std::vector<sf::Image>>& TMJParser::getLayerImages() const {
    return m_layerImages;
}

void TMJParser::parseTilesets() {
    for (const auto& tileset : m_root["tilesets"]) {
        std::string tsxFilePath = tileset["source"].get<std::string>();
        std::string imageSource = getTilesetImageSource(tsxFilePath);
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
    std::vector<sf::Image> images;

    for (size_t i = 0; i < data.size(); ++i) {
        int tileID = data[i].get<int>();
        if (tileID == 0) {
            // Empty tile, create a blank image
            sf::Image image;
            image.create(32, 32, sf::Color::Transparent);
            images.push_back(image);
        } else {
            // Calculate which tileset the tileID belongs to
            std::string tilesetSource = getTilesetSource(tileID);
            sf::Image image = loadTileImage(tilesetSource, tileID);
            images.push_back(image);
        }
    }

    m_layerImages.push_back(images);
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
    int columns = tileset.getSize().x / 32;
    int row = (tileID - 1) / columns;
    int col = (tileID - 1) % columns;

    sf::Image tile;
    tile.create(32, 32);
    tile.copy(tileset, 0, 0, sf::IntRect(col * 32, row * 32, 32, 32));
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

    return std::string(source);
}
