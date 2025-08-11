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

int AlienBlockControl::check_collisions() {
    int defeated_aliens = 0;
    for(const auto& alien : alien_block.getAliens()) {
        for(const auto& bullet : bullet_control.getBullets()) {
            if(bullet.collidesWithAlien(alien)) {
                bullet_control.remove_bullet(bullet);
                alien_block.remove_alien(alien);
                defeated_aliens++;
            }
        }
    }
    return defeated_aliens;
}

bool AlienBlockControl::isDefeated() const {
    return alien_block.isDefeated();
}

void AlienBlockControl::reset() {
    alien_block = AlienBlock();
    bullet_control.clear_bullets();
}

void AlienBlockControl::shoot(int prob) {
    for(int i = 0; i < alien_block.getAliens().size(); i++) {
        const Alien& alien = alien_block.getAliens()[i];
        bool canShoot = true;

        // Check if there is an alien below
        for(int j = i + 1; j < alien_block.getAliens().size(); j++) {
            const Alien& below_alien = alien_block.getAliens()[j];
            if(below_alien.getX() == alien.getX()) {
                canShoot = false;
                break; 
            }
        }

        if (canShoot && rand() % 10000 < prob) {
            bullet_control.add_bullet(Bullet(alien.getX() + constants::ALIEN_RADIUS - constants::BULLET_WIDTH / 2,
                                              alien.getY() + constants::ALIEN_RADIUS * 2, true));
        }
    }
}