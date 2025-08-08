#ifndef ALIEN_HPP
#define ALIEN_HPP

/**
 * @brief Represents a single alien in the game and manages its state
 */
class Alien {
private:
    // Unique identifier for the alien
    int id;
    // Horizontal position of the alien (the leftmost point of the alien)
    int x;
    // Vertical position of the alien (the topmost point of the alien)
    int y;

    // Static variable to generate unique IDs for aliens
    static int next_id;

public:
    /**
     * @param x Initial horizontal position
     * @param y Initial vertical position
     * @throws std::out_of_range if x is out of bounds
     */
    Alien(int x, int y);

    /**
     * @return true if the alien can move down, false otherwise
     */
    bool canMoveDown();

    /**
     * @return true if the alien can move left, false otherwise
     */
    bool canMoveLeft();

    /**
     * @return true if the alien can move right, false otherwise
     */
    bool canMoveRight();

    /**
     * @brief Moves the alien to the left
     * @throws std::out_of_range if the alien would move out of bounds
     */
    void moveLeft();
    
    /**
     * @brief Moves the alien to the right
     * @throws std::out_of_range if the alien would move out of bounds
     */
    void moveRight();

    /**
     * @brief Moves the alien down
     * @throws std::out_of_range if the alien would move out of bounds
     */
    void moveDown();

    /**
     * @return The horizontal position of the alien
     */
    int getX() const;

    /**
     * @return The vertical position of the alien
     */
    int getY() const;

    /**
     * @return True if this alien is equal to another alien, false otherwise (based on ID)
     */
    bool operator==(const Alien& other) const;
};

#endif