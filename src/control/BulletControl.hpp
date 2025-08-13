#ifndef BULLETCONTROL_H
#define BULLETCONTROL_H

#include "../model/Bullet.hpp"
#include <vector>
#include "../view/Layer.hpp"

/**
 * @brief Manages the bullets fired by the ship and the aliens
 */
class BulletControl {
private:
    // List of bullets currently in play
    std::vector<Bullet> bullets;

    // The layer on which the bullets are drawn
    Layer &layer;

public:
    /**
     * @param layer The layer on which the bullets will be drawn
     */
    BulletControl(Layer &layer);

    /**
     * @brief Adds a new bullet to the list
     * @param bullet The bullet to be added
     */
    void add_bullet(Bullet bullet);

    /**
     * @brief Removes a bullet from the list
     * @param bullet The bullet to be removed
     */
    void remove_bullet(const Bullet &bullet);

    /**
     * @brief Clears all bullets from the list
     */
    void clear_bullets();

    /**
     * @brief Updates the position of all bullets and removes those that are out of bounds
     */
    void update_bullets();

    /**
     * @brief Draws all bullets on the layer
     */
    void draw_bullets();

    /**
     * @return Reference to the vector of bullets
     */
    const std::vector<Bullet>& getBullets() const;
    
    /**
     * @return Mutable reference to the vector of bullets
     */
    std::vector<Bullet>& getBullets();
};

#endif