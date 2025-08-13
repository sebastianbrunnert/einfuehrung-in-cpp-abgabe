#ifndef BARRIERCONTROL_H
#define BARRIERCONTROL_H

#include "../model/Barrier.hpp"
#include "../view/Layer.hpp"
#include "BulletControl.hpp"

/**
 * @brief Manages the barrier
 */
class BarrierControl {
private:
    Barrier barrier;

    // The layer on which the bullets are drawn
    Layer &layer;

    // The control for the bullets fired by ship and aliens
    BulletControl &bullet_control;

public:
    /**
     * @param layer The layer on which the barrier will be drawn
     * @param bullet_control The control for the bullets fired by ship and aliens
     */
    BarrierControl(Layer &layer, BulletControl &bullet_control);

    /**
     * @brief Updates the position of the barrier
     */
    void update_barrier();

    /**
     * @brief Draws the barrier on the layer
     */
    void draw_barrier();

    /**
     * @brief Handles the bullet collision with the barrier
     */
    void check_collisions();
};

#endif