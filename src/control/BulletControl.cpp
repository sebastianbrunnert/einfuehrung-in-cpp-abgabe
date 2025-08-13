#include "BulletControl.hpp"
#include "../model/Constants.hpp"

BulletControl::BulletControl(Layer &layer) : layer(layer) {

}

void BulletControl::add_bullet(Bullet bullet) {
    bullets.push_back(bullet);
}

void BulletControl::draw_bullets() {
    // For each bullet, draw it as a rectangle
    for (const auto& bullet : bullets) {
        sf::RectangleShape bulletRect;
        bulletRect.setOrigin({0, 0});
        bulletRect.setSize(sf::Vector2f(constants::BULLET_WIDTH, constants::BULLET_HEIGHT));
        bulletRect.setPosition(sf::Vector2f(bullet.getX(), bullet.getY()));
        bulletRect.setFillColor(sf::Color::Red);
        layer.add_to_layer(bulletRect);
    }
}

void BulletControl::update_bullets() {
    // Update each bullets position and remove bullets that are out of bounds
    for (auto b = bullets.begin(); b != bullets.end();) {
        b->update();
        if (b->isOutOfBounds()) {
            b = bullets.erase(b);
        } else {
            b++;
        }
    }
}

const std::vector<Bullet>& BulletControl::getBullets() const {
    return bullets;
}

std::vector<Bullet>& BulletControl::getBullets() {
    return bullets;
}

void BulletControl::remove_bullet(const Bullet &bullet) {
    bullets.erase(std::remove(bullets.begin(), bullets.end(), bullet), bullets.end());
}

void BulletControl::clear_bullets() {
    bullets.clear();
}