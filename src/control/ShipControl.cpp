#include "ShipControl.hpp"
#include "../model/Constants.hpp"

// Constructor: Initialize ship at middle of the screen with 3 lives
ShipControl::ShipControl(Layer &layer) : ship(constants::VIEW_WIDTH / 2 - constants::SHIP_WIDTH / 2, 3), layer(layer) {

}

void ShipControl::draw_ship() {
    // Draw the ship as a rectangle
    sf::RectangleShape shipRect;
    shipRect.setOrigin({0, 0});
    shipRect.setSize(sf::Vector2f(constants::SHIP_WIDTH, constants::SHIP_HEIGHT));
    shipRect.setPosition(sf::Vector2f(ship.getX(), constants::VIEW_HEIGHT - constants::SHIP_HEIGHT - 10));
    shipRect.setFillColor(sf::Color::White);
    
    layer.add_to_layer(shipRect);
}

void ShipControl::left_button_pressed() {
    ship.moveLeft();
}

void ShipControl::right_button_pressed() {
    ship.moveRight();
}

void ShipControl::space_pressed() {
    ship.shoot();
}
