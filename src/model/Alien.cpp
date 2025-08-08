#include "Alien.hpp"
#include "Constants.hpp"
#include <stdexcept>

int Alien::next_id = 0;

// Constructor with input validation
Alien::Alien(int x, int y) : x(x), y(y) {
    // Validate that alien position is within view boundaries
    if (x < 0 || y < 0 || x > constants::VIEW_WIDTH - constants::ALIEN_RADIUS*2 || y > constants::VIEW_HEIGHT - constants::ALIEN_RADIUS*2) {
        throw std::out_of_range("Alien position out of bounds");
    }

    // Assign a unique ID to the alien
    id = next_id++;
}

bool Alien::canMoveDown() {
    // Check if the alien can move down without going out of bounds
    return y <= constants::VIEW_HEIGHT - constants::ALIEN_RADIUS*4 - constants::ALIEN_GAP;
}

bool Alien::canMoveLeft() {
    // Check if the alien can move left without going out of bounds
    return x >= constants::ALIEN_GAP;
}

bool Alien::canMoveRight() {
    // Check if the alien can move right without going out of bounds
    return x <= constants::VIEW_WIDTH - constants::ALIEN_RADIUS*2 - constants::ALIEN_GAP;
}

void Alien::moveLeft() {
    // Only move if not at the leftmost position
    if(canMoveLeft()) {
        x -= constants::ALIEN_GAP;
    } else {
        // If moving left would go out of bounds, throw an exception
        throw std::out_of_range("Alien cannot move left, out of bounds");
    }
}

void Alien::moveRight() {
    // Only move if not at the rightmost position
    if(canMoveRight()) {
        x += constants::ALIEN_GAP;
    } else {
        // If moving right would go out of bounds, throw an exception
        throw std::out_of_range("Alien cannot move right, out of bounds");
    }
}

void Alien::moveDown() {
    // Only move if not at the bottommost position
    if(canMoveDown()) {
        y += constants::ALIEN_GAP + constants::ALIEN_RADIUS*2;
    } else {
        // If moving down would go out of bounds, throw an exception
        throw std::out_of_range("Alien cannot move down, out of bounds");
    }
}

int Alien::getX() const {
    return x;
}

int Alien::getY() const {
    return y;
}

bool Alien::operator==(const Alien& other) const {
    return id == other.id;
}