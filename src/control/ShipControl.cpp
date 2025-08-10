#include "ShipControl.hpp"
#include "../model/Constants.hpp"
#include "../model/Bullet.hpp"

// Constructor: Initialize ship at middle of the screen with 3 lives
ShipControl::ShipControl(Layer &game_layer, Layer &information_layer, BulletControl &bullet_control) : ship(constants::VIEW_WIDTH / 2 - constants::SHIP_WIDTH / 2, 3), game_layer(game_layer), information_layer(information_layer), bullet_control(bullet_control) {

}

void ShipControl::draw_ship() {
    // Draw the ship as a rectangle
    sf::RectangleShape shipRect;
    shipRect.setOrigin({0, 0});
    shipRect.setSize(sf::Vector2f(constants::SHIP_WIDTH, constants::SHIP_HEIGHT));
    shipRect.setPosition(sf::Vector2f(ship.getX(), constants::SHIP_Y));
    shipRect.setFillColor(sf::Color::White);
    
    game_layer.add_to_layer(shipRect);
}

void ShipControl::draw_lives() {
    // Draw the lives as circles
    for (int i = 0; i < ship.getLives(); ++i) {
        sf::CircleShape circle;
        circle.setRadius(5);
        circle.setFillColor(sf::Color::Red);
        circle.setPosition(sf::Vector2f(10 + i * 15, 10));
        
        information_layer.add_to_layer(circle);
    }
}

void ShipControl::left_button_pressed() {
    ship.moveLeft();
}

void ShipControl::right_button_pressed() {
    ship.moveRight();
}

void ShipControl::space_pressed() {
    static sf::Clock time_since_last_shot;
    static bool first_shot = true;
    
    // Allow the first shot immediately, then request delay
    if (first_shot || time_since_last_shot.getElapsedTime().asMilliseconds() > constants::BULLET_FIRE_RATE) {
        bullet_control.add_bullet(Bullet(ship.getX() + constants::SHIP_WIDTH / 2 - constants::BULLET_WIDTH / 2, constants::SHIP_Y - constants::BULLET_HEIGHT, false));
        time_since_last_shot.restart();
        first_shot = false;
    }
}

void ShipControl::check_collisions() {
    for (const auto& bullet : bullet_control.getBullets()) {
        if (bullet.collidesWithShip(ship)) {
            bullet_control.remove_bullet(bullet);
            ship.takeHit();
        }
    }
}