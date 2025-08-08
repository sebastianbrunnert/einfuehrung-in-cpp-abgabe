#include "Bullet.hpp"
#include "Alien.hpp"
#include "Ship.hpp"
#include "Constants.hpp"
#include <stdexcept>

int Bullet::next_id = 0;

Bullet::Bullet(int x, int y) : x(x), y(y) {
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
    // Move the bullet upwards
    y -= constants::BULLET_SPEED;
}

bool Bullet::collidesWithShip(const Ship& ship) const {
    return (x >= ship.getX() && x <= ship.getX() + constants::SHIP_WIDTH &&
            y >= constants::SHIP_Y && y <= constants::SHIP_Y + constants::SHIP_HEIGHT);
}

bool Bullet::collidesWithAlien(const Alien& alien) const {
    return (x >= alien.getX() && x <= alien.getX() + constants::ALIEN_RADIUS*2 &&
            y >= alien.getY() && y <= alien.getY() + constants::ALIEN_RADIUS*2);
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