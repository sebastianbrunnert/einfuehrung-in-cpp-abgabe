#ifndef BULLET_HPP
#define BULLET_HPP

#include "Alien.hpp"
#include "Ship.hpp"

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

    // Static variable to generate unique IDs for bullets
    static int next_id;

public:
    /**
     * @param x Initial horizontal position
     * @param y Initial vertical position
     * @throws std::out_of_range if x is out of bounds
     */
    Bullet(int x, int y);

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