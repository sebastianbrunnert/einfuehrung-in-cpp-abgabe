#ifndef SHIP_HPP
#define SHIP_HPP

/**
 * @brief Represents a ship in the game and manages its state
 */
class Ship {
private:
    // Horizontal position of the ship (the leftmost point of the ship)
    int x;
    // Remaining lives of the ship
    int lives;

public:
    /**
     * @param x Initial horizontal position
     * @param lives Initial number of lives
     * @param width Width of the ship
     * @throws std::out_of_range if x is out of bounds
     * @throws std::invalid_argument if lives is negative
     */
    Ship(int x, int lives);

    /**
     * @return true if the ship can move left, false otherwise
     */
    bool canMoveLeft();

    /**
     * @return true if the ship can move right, false otherwise
     */
    bool canMoveRight();

    /**
     * @brief Moves the ship to the left
     */
    void moveLeft();
    
    /**
     * @brief Moves the ship to the right
     */
    void moveRight();

    /**
     * @brief Fires a bullet from the ship
     */
    void shoot();
    
    /**
     * @brief Alien hits the ship, reduces lives by one
     * @throws std::runtime_error if the ship has no lives left
     */
    void takeHit();

    /**
     * @return The horizontal position of the ship
     */
    int getX() const;

    /**
     * @return The width of the ship
     */
    int getWidth() const;
    
    /**
     * @return The remaining lives of the ship
     */
    int getLives() const;
};

#endif