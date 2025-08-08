#include <vector>
#include "Alien.hpp"

#ifndef ALIENBLOCK_HPP
#define ALIENBLOCK_HPP

/**
 * @brief Represent the block of aliens in the game and manages its states
 */
class AlienBlock {
private:
    // The current moving direction of the block
    bool movingRight = true;
    // The collection of aliens in the block
    std::vector<Alien> aliens = {};

public:
    AlienBlock();

    /**
     * @brief Moves the whole blocks of aliens to the current direction
     */
    void move();

    void remove_alien(const Alien &alien);

    /**
     * @return Whether there are any aliens left in the block
     */
    bool isDefeated() const;

    /**
     * @return The collection of aliens in the block
     */
    const std::vector<Alien>& getAliens();
};

#endif