#include "Ship.hpp"
#include "Constants.hpp"
#include <stdexcept>

// Constructor with input validation
Ship::Ship(int x, int lives) : x(x), lives(lives) {
    // Validate that ship position is within view boundaries
    if (x < 0 || x > constants::VIEW_WIDTH - constants::SHIP_WIDTH) {
        throw std::out_of_range("Ship position out of bounds");
    }
    // Ensure lives count is not negative
    if (lives < 0) {
        throw std::invalid_argument("Lives cannot be negative");
    }
}

bool Ship::canMoveLeft() {
    // Check if the ship can move left without going out of bounds
    return x - constants::SHIP_SPEED >= 0;
}

bool Ship::canMoveRight() {
    // Check if the ship can move right without going out of bounds
    return x <= constants::VIEW_WIDTH - constants::SHIP_WIDTH - constants::SHIP_SPEED;
}

void Ship::moveLeft() {
    // Only move if not at the leftmost position
    if (canMoveLeft()) {
        x -= constants::SHIP_SPEED;
    }
}

void Ship::moveRight() {
    // Only move if not at the rightmost position
    if (canMoveRight()) {
        x += constants::SHIP_SPEED;
    }
}

void Ship::shoot() {
    // TODO: Implement shooting logic
}

void Ship::takeHit() {
    // Decrease lives only if ship has lives remaining
    if (lives == 1) {
        // Ship is destroyed, handle accordingly
        throw std::runtime_error("Ship has no lives left");
    } else {
        lives -= 1;
    }
}

int Ship::getX() const {
    return x;
}

int Ship::getLives() const {
    return lives;
}