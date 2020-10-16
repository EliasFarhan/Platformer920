#include "game.h"

#include "SFML/Window/Event.hpp"

Game::Game() = default;

void Game::Init()
{
    window_.create(sf::VideoMode(1280, 720), "SAE Platformer");
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
        window_.display();
    }
}

void Game::Destroy()
{
}
