#include "Game.hpp"

#include <SFML/Window/Keyboard.hpp>

#include "../model/Constants.hpp"

Game::Game() : window(sf::VideoMode({constants::VIEW_WIDTH, constants::VIEW_HEIGHT}), "Space Invaders"),
    view(sf::FloatRect(sf::Vector2f({0, 0}), sf::Vector2f({constants::VIEW_WIDTH, constants::VIEW_HEIGHT}))),
    game_layer(window),
    information_layer(window),
    bullet_control(game_layer),
    ship_control(game_layer, bullet_control),
    alien_block_control(game_layer, bullet_control) {
    // limit frame rate
    window.setFramerateLimit(constants::FRAME_RATE);

    // set the view (visible area) for our game
    game_layer.set_view(view);
    information_layer.set_view(view);
}

void Game::start() {
    // The clock is needed to control the speed of movement
    sf::Clock clock;

    while (window.isOpen()) {
        // Restart the clock and save the elapsed time into elapsed_time
        sf::Time elapsed_time = clock.restart();
 
        // handle input, check if window is still open
        if (!input()) {
            // update the scene according to the passed time
            update(elapsed_time.asSeconds());
            // draw the scene
            draw();
        }
    }
}

// returns true, if the window has been closed
bool Game::input() {
    while (std::optional<sf::Event> event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
            return true;
        }

        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->code == sf::Keyboard::Key::Space) {
                ship_control.space_pressed();
            }
        }
    }

    // Use real-time input for continuous movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        ship_control.left_button_pressed();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        ship_control.right_button_pressed();
    }

    return false;
}


void Game::update(float time_passed) {
    // Each 0.25 seconds, move the alien block
    static int frame_count = 0;
    frame_count++;
    if (frame_count >= constants::FRAME_RATE / 4) {
        alien_block_control.move();
        frame_count = 0;
    }

    bullet_control.update_bullets();
    alien_block_control.check_collisions();
    alien_block_control.shoot();

    ship_control.check_collisions();
}

void Game::draw() {
    window.clear();

    game_layer.clear();
    information_layer.clear();

    ship_control.draw_ship();
    bullet_control.draw_bullets();
    alien_block_control.draw_alien_block();
    
    game_layer.draw();
    information_layer.draw();

    window.display();
}
