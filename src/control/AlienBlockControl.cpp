#include "AlienBlockControl.hpp"
#include "../model/Constants.hpp"

AlienBlockControl::AlienBlockControl(Layer &layer) : alien_block(), layer(layer) {}

void AlienBlockControl::draw_alien_block() {
    for (const auto& alien : alien_block.getAliens()) {
        sf::CircleShape alienShape;
        alienShape.setRadius(constants::ALIEN_RADIUS);
        alienShape.setFillColor(sf::Color::Green);
        alienShape.setPosition(sf::Vector2f(alien.getX(), alien.getY()));
        alienShape.setOrigin({0,0});
        layer.add_to_layer(alienShape);
    }
}

void AlienBlockControl::move() {
    alien_block.move();
}