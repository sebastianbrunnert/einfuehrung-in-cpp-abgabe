#include "AlienBlock.hpp"
#include "Constants.hpp"
#include <stdexcept>

AlienBlock::AlienBlock() {
    // Initialize the alien block with a grid of aliens
    for(int i = 0; i < constants::ALIEN_ROWS; i++) {
        for(int j = 0; j < constants::ALIEN_COLUMNS; j++) {            
            Alien alien(
                j * (constants::ALIEN_RADIUS*2 + constants::ALIEN_GAP),
                (i+1) * (constants::ALIEN_RADIUS*2 + constants::ALIEN_GAP)
            );
            aliens.push_back(alien);
        }
    }
}

void AlienBlock::move() {
    // Check if each alien can move in the current direction
    for (auto& alien : aliens) {
        if((movingRight && !alien.canMoveRight()) || (!movingRight && !alien.canMoveLeft())) {
            // If any alien cannot move in the current direction, change direction and move down
            movingRight = !movingRight;
            for(auto& alien : aliens) {
                alien.moveDown();
            }
            return;
        }
    }

    // Move all aliens in the current direction
    for(auto& alien : aliens) {
        if(movingRight) {
            alien.moveRight();
        } else {
            alien.moveLeft();
        }
    }
}

bool AlienBlock::isDefeated() const {
    return aliens.empty();
}

const std::vector<Alien>& AlienBlock::getAliens() {
    return aliens;
}

void AlienBlock::remove_alien(const Alien &alien) {
    // Remove the alien from the block
    aliens.erase(std::remove(aliens.begin(), aliens.end(), alien), aliens.end());
}