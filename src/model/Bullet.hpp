#ifndef BULLET_HPP
#define BULLET_HPP

#include "Alien.hpp"
#include "Ship.hpp"
#include "Barrier.hpp"

/**
 * @brief Represents a bullet in the game and manages its state
 */
class Bullet {
private:
    // Unique identifier for the bullet
    int id;
    // Horizontal position of the bullet (the leftmost point of the bullet)
    int x;
    // Vertical position of the alien (the topmost point of the bullet)
    int y;
    // Is it a bullet by alien or by ship?
    bool is_from_alien;

    // Static variable to generate unique IDs for bullets
    static int next_id;

public:
    /**
     * @param x Initial horizontal position
     * @param y Initial vertical position
     * @param is_from_alien Is the bullet from an alien?
     * @throws std::out_of_range if x is out of bounds
     */
    Bullet(int x, int y, bool is_from_alien);

    /**
     * @param ship The ship to check collision with
     * @return true if the bullet collides with the ship, false otherwise
     */
    bool collidesWithShip(const Ship& ship) const;

    /**
     * @param alien The alien to check collision with
     * @return true if the bullet collides with the alien, false otherwise
     */
    bool collidesWithAlien(const Alien& alien) const;

    /**
     * @param barrier The barrier to check collision with
     * @return true if the bullet collides with the barrier, false otherwise
     */
    bool collidesWithBarrier(const Barrier& barrier) const;
    
    /**
     * @brief Changes the bullet's direction (for barrier bouncing)
     */
    void change_direction();

    /**
     * @return true if the bullet is out of bounds, false otherwise
     */
    bool isOutOfBounds() const;

    /**
     * @brief Updates the position of the bullet
     */
    void update();

    /**
     * @return The horizontal position of the bullet
     */
    int getX() const;

    /**
     * @return The vertical position of the bullet
     */
    int getY() const;

    /**
     * @return True if this bullet is equal to another bullet, false otherwise (based on ID)
     */
    bool operator==(const Bullet& other) const;
};

#endif