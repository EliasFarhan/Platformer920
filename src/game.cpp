#include "game.h"

#include "SFML/Window/Event.hpp"
#include "SFML/Graphics/Sprite.hpp"

Game::Game() = default;

void Game::Init()
{
    window_.create(sf::VideoMode(1280, 720), "SAE Platformer");
    wall_.loadFromFile("data/sprites/wall.jpg");
}

void Game::Loop()
{
    while(window_.isOpen())
    {
        sf::Event event;
        while (window_.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window_.close();
        }
        window_.clear();
        sf::Sprite sprite;
        sprite.setTexture(wall_);
        sprite.setOrigin(wall_.getSize().x / 2.0f, wall_.getSize().y / 2.0f);
        const auto center = window_.getSize();
        sprite.setPosition(center.x/2.0f, center.y/2.0f);
        window_.draw(sprite);
        window_.display();
    }
}