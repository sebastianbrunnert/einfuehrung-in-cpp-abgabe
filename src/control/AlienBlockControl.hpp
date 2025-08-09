#ifndef ALIENBLOCKCONTROL_H
#define ALIENBLOCKCONTROL_H

#include "../view/Layer.hpp"
#include "../model/AlienBlock.hpp"
#include "../model/Bullet.hpp"
#include "BulletControl.hpp"

/**
 * @brief Creates and controls an alien blocks
 */
class AlienBlockControl {
private:
    // The alien block being controlled
    AlienBlock alien_block;

    // The layer on which the alien block is drawn
    Layer &layer;

    // The control for the bullets
    BulletControl &bullet_control;

public:
    /**
     * @param layer The layer on which the alien block will be drawn
     * @param bullet_control The control for the bullets
     */
    AlienBlockControl(Layer &layer, BulletControl &bullet_control);

    /**
     * @brief Draws the alien block on the layer
     */
    void draw_alien_block();

    /**
     * @brief Moves the alien block
     */
    void move();

    /**
     * @brief Handles the bullet collision with the alien block
     */
    void check_collisions();

    /**
     * @brief Return true if the alien block is defeated
     */
    bool isDefeated() const;

    /**
     * @brief Resets the alien block to its initial state
     */
    void reset();

    /**
     * @brief Makes the alien block shoot a bullet
     */
    void shoot();
};

#endif