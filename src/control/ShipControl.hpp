#ifndef SHIPCONTROL_H
#define SHIPCONTROL_H

#include "../view/Layer.hpp"
#include "../model/Ship.hpp"

#include "BulletControl.hpp"

/**
 * @brief Creates and controls the ship
 */
class ShipControl {
private:
    // The ship being controlled
    Ship ship;

    // The layer on which the ship is drawn
    Layer &game_layer;

    // The layer on which the lives of the ship are drawn
    Layer &information_layer;

    // The control for the bullets fired by the ship
    BulletControl &bullet_control;

public:
    /**
     * @param layer The layer on which the ship will be drawn
     */
    ShipControl(Layer &game_layer, Layer &information_layer, BulletControl &bullet_control);

    /**
     * @brief Draws the ship on the game layer
     */
    void draw_ship();

    /**
     * @brief Draws the lives of the ship on the information layer
     */
    void draw_lives();

    /**
     * @brief Handles the left button press event
     */
    void left_button_pressed();

    /**
     * @brief Handles the right button press event
     */
    void right_button_pressed();

    /**
     * @brief Handles the space key press event to shoot
     */
    void space_pressed();

    /**
     * @brief Handles the bullet collision with the ship
     * @throws std::runtime_error if the ship has no lives left
     */
    void check_collisions();
};

#endif