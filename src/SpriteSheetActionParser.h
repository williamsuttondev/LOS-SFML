#pragma once

#include "SFML/Graphics.hpp"
#include "AnimatedSpriteConfig.h"
#include <vector>
#include <fstream>

/**
 * @class SpriteSheetActionParser
 * @brief A singleton class used to parse configuration files for animated sprites.
 *
 * This class reads a configuration file and parses it into a vector of 
 * AnimatedSpriteConfig objects. The configuration file typically contains
 * details about the frames, animations, and other properties of a sprite sheet.
 */
class SpriteSheetActionParser {
public:
    /**
     * @brief Gets the single instance of the SpriteSheetActionParser.
     * 
     * This method ensures that only one instance of the SpriteSheetActionParser
     * exists within the program (singleton pattern).
     *
     * @return SpriteSheetActionParser& A reference to the single instance of the parser.
     */
    static SpriteSheetActionParser& getInstance();

    /**
     * @brief Parses the configuration file into a vector of AnimatedSpriteConfig objects.
     *
     * The method reads a configuration file specified by the filename parameter
     * and converts its contents into a vector of AnimatedSpriteConfig objects,
     * which can be used to control animations and frames in a sprite sheet.
     *
     * @param filename The path to the configuration file to be parsed.
     * @return std::vector<AnimatedSpriteConfig> A vector of parsed configuration objects.
     */
    std::vector<AnimatedSpriteConfig> parseConfig(std::string_view filename);

private:
    /**
     * @brief Default constructor.
     *
     * The constructor is private to prevent direct instantiation of the class
     * and enforce the singleton pattern.
     */
    SpriteSheetActionParser() {}

    /**
     * @brief Destructor.
     *
     * The destructor is private to prevent direct deletion of the instance.
     */
    ~SpriteSheetActionParser() {}

    /**
     * @brief Copy constructor (deleted).
     *
     * The copy constructor is deleted to prevent copying of the singleton instance.
     */
    SpriteSheetActionParser(const SpriteSheetActionParser&) = delete;

    /**
     * @brief Assignment operator (deleted).
     *
     * The assignment operator is deleted to prevent assignment of the singleton instance.
     *
     * @return SpriteSheetActionParser& A reference to the object being assigned (deleted).
     */
    SpriteSheetActionParser& operator=(const SpriteSheetActionParser&) = delete;
};