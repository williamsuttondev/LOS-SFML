#pragma once

#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

class TMJParser {
public:
    TMJParser(const std::string& filePath);
    const std::vector<sf::Sprite>& getLayerSprites() const;

private:
    nlohmann::json m_root;
    std::vector<std::string> m_tilesetSources;
    std::vector<int> m_firstGids;
    std::vector<sf::Texture> m_tilesetTextures;
    std::vector<sf::Sprite> m_layerSprites;

    void parseTilesets(const std::filesystem::path& baseDir);
    void parseLayers();
    void parseTileLayer(const nlohmann::json& layer, int layerIndex);
    std::string getTilesetSource(int tileID);
    std::string getTilesetImageSource(const std::string& tsxFilePath);
};