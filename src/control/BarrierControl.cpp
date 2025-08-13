#include "BarrierControl.hpp"
#include "../model/Constants.hpp"

BarrierControl::BarrierControl(Layer &layer, BulletControl &bullet_control) : barrier(constants::BARRIER_X), layer(layer), bullet_control(bullet_control) {}

void BarrierControl::update_barrier() {
    barrier.move();
}

void BarrierControl::draw_barrier() {
    sf::RectangleShape barrierShape(sf::Vector2f(constants::BARRIER_WIDTH, constants::BARRIER_HEIGHT));
    barrierShape.setPosition(sf::Vector2f(barrier.getX(), constants::BARRIER_Y));
    barrierShape.setFillColor(sf::Color::White);
    layer.add_to_layer(barrierShape);
}

void BarrierControl::check_collisions() {
    for (auto& bullet : bullet_control.getBullets()) {
        if (bullet.collidesWithBarrier(barrier)) {
            bullet.change_direction();
        }
    }
}