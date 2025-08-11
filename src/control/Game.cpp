#include "Game.hpp"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

#include "../model/Constants.hpp"

Game::Game() 
    : window(sf::VideoMode({constants::VIEW_WIDTH, constants::VIEW_HEIGHT}), "Space Invaders"),
      view(sf::FloatRect(sf::Vector2f({0, 0}), sf::Vector2f({constants::VIEW_WIDTH, constants::VIEW_HEIGHT}))),
      game_layer(window),
      information_layer(window),
      bullet_control(game_layer),
      ship_control(game_layer, information_layer, bullet_control),
      alien_block_control(game_layer, bullet_control) 
{
    window.setFramerateLimit(constants::FRAME_RATE);

    game_layer.set_view(view);
    information_layer.set_view(view);
}

void Game::start() {
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time elapsed_time = clock.restart();

        if (!input()) {
            update(elapsed_time.asSeconds());
            draw();
        }
    }
}

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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
        ship_control.left_button_pressed();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
        ship_control.right_button_pressed();
    }

    return false;
}

void Game::update(float time_passed) {
    // If game is over, stop updating
    if (is_game_over) {
        return;
    }


    // Move the aliens in the proper speed
    static int frame_count = 0;
    static float speed = 4.f;
    frame_count++;
    if (frame_count >= constants::FRAME_RATE / speed) {
        alien_block_control.move();
        frame_count = 0;
    }

    // Update bullets
    bullet_control.update_bullets();

    // Check for collisions

    // Update points
    points = points + alien_block_control.check_collisions();
    try {
        ship_control.check_collisions();
    } catch (const std::runtime_error& e) {
        // If ship is hit and has no lives, game is over
        is_game_over = true;
    }

    // Shoot bullets from the alien block
    static int shoot_prob = 5;
    alien_block_control.shoot(shoot_prob);

    // Increase speed if alien block and shooting probabilty is defeated
    if(alien_block_control.isDefeated()) {
        alien_block_control.reset();
        speed = speed * 1.3f;
        shoot_prob = shoot_prob + 3;
    }
}

void Game::draw_informations() {
    sf::Font font;
    if (!font.openFromFile("assets/fonts/DejaVuSansMono.ttf")) {
        throw std::runtime_error("Failed to load font");
    }

    if (is_game_over) {
        sf::Text game_over_text(font, "Game Over", 50);
        game_over_text.setFillColor(sf::Color::White);
        game_over_text.setStyle(sf::Text::Bold);

        sf::FloatRect go_text_bounds = game_over_text.getLocalBounds();
        game_over_text.setOrigin({go_text_bounds.size.x / 2.f, go_text_bounds.size.y / 2.f});
        game_over_text.setPosition({constants::VIEW_WIDTH / 2.f, constants::VIEW_HEIGHT / 2.f});

        information_layer.add_to_layer(game_over_text);
    }

    sf::Text points_text(font, "Punkte: " + std::to_string(points), 16);
    points_text.setFillColor(sf::Color::White);

    sf::FloatRect points_bounds = points_text.getLocalBounds();
    points_text.setOrigin({points_bounds.size.x, points_bounds.size.y / 2.f});
    points_text.setPosition({constants::VIEW_WIDTH - 10, 10});
    information_layer.add_to_layer(points_text);
}

void Game::draw() {
    window.clear();

    game_layer.clear();
    information_layer.clear();

    ship_control.draw_ship();
    bullet_control.draw_bullets();
    alien_block_control.draw_alien_block();
    ship_control.draw_lives();

    draw_informations();

    game_layer.draw();
    information_layer.draw();

    window.display();
}
