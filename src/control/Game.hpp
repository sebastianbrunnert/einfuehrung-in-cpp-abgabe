#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "../view/Layer.hpp"
#include "ShipControl.hpp"
#include "AlienBlockControl.hpp"
#include "BulletControl.hpp"

// Game class
class Game {

public:
    //initialize the game (window and controls)
    Game();

    // start the game
    void start();

private:
    // processes user input, returns true if window has been closed
    bool input();

    // updates all game elements
    void update(float time_passed);

    // draws the scene
    void draw();

    sf::RenderWindow window;

    // view area and layers
    sf::View view;
    Layer game_layer;
    Layer information_layer;

    // Controls for different parts of the game
    BulletControl bullet_control;
    ShipControl ship_control;
    AlienBlockControl alien_block_control;

    bool is_game_over = false;
};

#endif