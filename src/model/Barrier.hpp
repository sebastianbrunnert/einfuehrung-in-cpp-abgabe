#ifndef BARRIER_HPP
#define BARRIER_HPP

/**
 * @brief Represents the interactive barrier 
 */
class Barrier {
private:
    // Horizontal position of the barrier (the leftmost point of the barrier)
    int x;
    // The current moving direction of the barrier
    bool movingRight = false;

public:
    /**
     * @param x Initial horizontal position
     */
    Barrier(int x);

    /**
     * @brief Moves the alien to the left
     * @throws std::out_of_range if the alien would move out of bounds
     */
    void move();

    /**
     * @return The horizontal position of the barrier
     */
    int getX() const;
};

#endif
