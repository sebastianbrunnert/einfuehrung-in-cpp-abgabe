#include "Bullet.hpp"
#include "Alien.hpp"
#include "Ship.hpp"
#include "Constants.hpp"
#include <stdexcept>
#include <cstdio>

int Bullet::next_id = 0;

Bullet::Bullet(int x, int y, bool is_from_alien) : x(x), y(y), is_from_alien(is_from_alien) {
    // Validate that bullet position is within view boundaries
    if (isOutOfBounds()) {
        throw std::out_of_range("Bullet position out of bounds");
    }

    // Assign a unique ID to the bullet
    id = next_id++;
}

bool Bullet::isOutOfBounds() const {
    return x < 0 || x > constants::VIEW_WIDTH || y < 0 || y > constants::VIEW_HEIGHT;
}

void Bullet::update() {
    // Move the bullet in the appropriate direction
    if(is_from_alien) {
        y += constants::BULLET_SPEED;
    } else {
        y -= constants::BULLET_SPEED;
    }
}

bool Bullet::collidesWithShip(const Ship& ship) const {
    // Only alien bullets can hit the ship
    if (!is_from_alien) return false;

    // Check if bullet rectangle overlaps with ship rectangle
    return (x < ship.getX() + constants::SHIP_WIDTH &&
            x + constants::BULLET_WIDTH > ship.getX() &&
            y < constants::SHIP_Y + constants::SHIP_HEIGHT &&
            y + constants::BULLET_HEIGHT > constants::SHIP_Y);
}

bool Bullet::collidesWithAlien(const Alien& alien) const {
    // Only ship bullets can hit aliens
    if (is_from_alien) return false;
    
    // Check if bullet rectangle overlaps with alien circle (treated as square for simplicity)
    return (x < alien.getX() + constants::ALIEN_RADIUS * 2 &&
            x + constants::BULLET_WIDTH > alien.getX() &&
            y < alien.getY() + constants::ALIEN_RADIUS * 2 &&
            y + constants::BULLET_HEIGHT > alien.getY());
}

bool Bullet::collidesWithBarrier(const Barrier& barrier) const {
    return (x < barrier.getX() + constants::BARRIER_WIDTH &&
            x + constants::BULLET_WIDTH > barrier.getX() &&
            y < constants::BARRIER_Y + constants::BARRIER_HEIGHT &&
            y + constants::BULLET_HEIGHT > constants::BARRIER_Y);
}

void Bullet::change_direction() {
    is_from_alien = !is_from_alien;
}

int Bullet::getX() const {
    return x;
}

int Bullet::getY() const {
    return y;
}

bool Bullet::operator==(const Bullet& other) const {
    return id == other.id;
}