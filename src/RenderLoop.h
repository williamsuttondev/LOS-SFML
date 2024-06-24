#pragma once
#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"
#include "SceneObject.h"

/**
 * @class RenderLoop
 * @brief Manages the main render loop, handling events, updating logic, and rendering frames.
 *
 * This class is responsible for managing the main render loop at a specified frames per second (FPS).
 * It handles user inputs, updates the game state, and renders the frames to the screen.
 */
class RenderLoop {
public:
    /**
     * @brief Construct a new RenderLoop object with a specified frame rate.
     *
     * @param fps The frames per second rate at which the render loop runs.
     */
    RenderLoop(unsigned int fps);

    /**
     * @brief Destroy the RenderLoop object.
     */
    ~RenderLoop();

    /**
     * @brief Starts the render loop, keeping the application running until a termination event occurs.
     */
    void run();

    void addObject(SceneObject* obj);

    std::vector<SceneObject*>& getSceneObjects();

private:
    /**
     * @brief Handles user input events.
     *
     * This method processes all user-generated events such as keyboard and mouse inputs.
     */
    void handleEvents();

    /**
     * @brief Updates the game state.
     *
     * This method updates the game logic and state during each frame.
     */
    void update();

    /**
     * @brief Renders the current frame.
     *
     * This method renders the current state of the game to the screen.
     */
    void render();

    sf::RenderWindow m_window;      ///< The render window where the game is displayed.
    sf::Event m_event;              ///< The event used to capture window events.
    sf::Time m_frameTime;           ///< Time duration of each frame to maintain constant FPS.
    sf::Time m_engineTime;
    std::vector<SceneObject*> m_sceneObjects;
};