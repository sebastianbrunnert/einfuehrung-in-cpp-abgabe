#ifndef ALIENBLOCKCONTROL_H
#define ALIENBLOCKCONTROL_H

#include "../view/Layer.hpp"
#include "../model/AlienBlock.hpp"

/**
 * @brief Creates and controls an alien blocks
 */
class AlienBlockControl {
private:
    // The alien block being controlled
    AlienBlock alien_block;

    // The layer on which the alien block is drawn
    Layer &layer;

public:
    /**
     * @param layer The layer on which the alien block will be drawn
     */
    AlienBlockControl(Layer &layer);

    /**
     * @brief Draws the alien block on the layer
     */
    void draw_alien_block();

    /**
     * @brief Moves the alien block
     */
    void move();
};

#endif