#include "Barrier.hpp"
#include "Constants.hpp"
#include <stdexcept>

Barrier::Barrier(int x) : x(x) {
    // Validate that the initial position is within bounds
    if (x < 0 || x > constants::VIEW_WIDTH - constants::BARRIER_WIDTH) {
        throw std::out_of_range("Barrier position out of bounds");
    }
}

void Barrier::move() {
    if (movingRight) {
        x += constants::BARRIER_SPEED;
        if (x + constants::BARRIER_SPEED > constants::VIEW_WIDTH - constants::BARRIER_WIDTH) {
            movingRight = false;
        }
    } else {
        x -= constants::BARRIER_SPEED;
        if (x - constants::BARRIER_SPEED < 0) {
            movingRight = true;
        }
    }
}

int Barrier::getX() const {
    return x;
}