#ifndef SHIPCONTROL_H
#define SHIPCONTROL_H

#include "../view/Layer.hpp"
#include "../model/Ship.hpp"

/**
 * @brief Creates and controls the ship
 */
class ShipControl {
private:
    // The ship being controlled
    Ship ship;

    // The layer on which the ship is drawn
    Layer &layer;

public:
    /**
     * @param layer The layer on which the ship will be drawn
     */
    ShipControl(Layer &layer);

    /**
     * @brief Draws the ship on the layer
     */
    void draw_ship();

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
};

#endif