#pragma once 

#include <SFML/Graphics.hpp>
#include <json.hpp>
#include <string>
#include <vector>

class TMJParser {
public:
    TMJParser(const std::string& filePath);
    const std::vector<std::vector<sf::Image>>& getLayerImages() const;

private:
    nlohmann::json m_root;
    std::vector<std::string> m_tilesetSources;
    std::vector<int> m_firstGids;
    std::vector<std::vector<sf::Image>> m_layerImages;

    void parseTilesets(const std::filesystem::path& baseDir);
    void parseLayers();
    void parseTileLayer(const nlohmann::json& layer);
    std::string getTilesetSource(int tileID);
    sf::Image loadTileImage(const std::string& tilesetSource, int tileID);
    std::string getTilesetImageSource(const std::string& tsxFilePath);
};