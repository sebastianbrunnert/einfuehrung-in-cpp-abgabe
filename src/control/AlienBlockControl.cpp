#include "AlienBlockControl.hpp"
#include "../model/Constants.hpp"

AlienBlockControl::AlienBlockControl(Layer &layer, BulletControl &bullet_control) : alien_block(), layer(layer), bullet_control(bullet_control) {}

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

void AlienBlockControl::check_collisions() {
    for(const auto& alien : alien_block.getAliens()) {
        for(const auto& bullet : bullet_control.getBullets()) {
            if(bullet.collidesWithAlien(alien)) {
                bullet_control.remove_bullet(bullet);
                alien_block.remove_alien(alien);
            }
        }
    }
}

bool AlienBlockControl::isDefeated() const {
    return alien_block.isDefeated();
}

void AlienBlockControl::reset() {
    alien_block = AlienBlock();
    bullet_control.clear_bullets();
}