//
// Created by Sondre on 23.10.2017.
//

#include "player.h"

sf::Texture* player_texture_ptr;

player::player(int x, int y, int health) {
    player_texture_ptr = &player_texture;
    player_texture.loadFromFile("Assets/player.png");
    this->rect.setTexture(player_texture_ptr);
    this->rect.setPosition(x,y);
    this->health = health;
    this->rect.setSize(sf::Vector2f(100,100));
    //this->rect.setSize(sf::Vector2f(player_texture_ptr->getSize().x, player_texture_ptr->getSize().y));
}

player::player() {
    this->rect.setPosition(0,0);
    this->health = this->maxHealth;
}

void player::ProcessEvents(sf::RenderWindow* window){
    sf::Event event;


    while (window->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        this->velocity.y += -2;
                        break;

                    case sf::Keyboard::Down:
                        this->velocity.y += 2;
                        break;

                    case sf::Keyboard::Right:
                        this->velocity.x += 2;
                        break;

                    case sf::Keyboard::Left:
                        this->velocity.x += -2;
                        break;

                }

                break;
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        this->velocity.y = 0;
                        break;

                    case sf::Keyboard::Down:
                        this->velocity.y = 0;
                        break;

                    case sf::Keyboard::Right:
                        this->velocity.x = 0;
                        break;

                    case sf::Keyboard::Left:
                        this->velocity.x = 0;
                        break;

                }

                break;
            case sf::Event::Closed:
                window->close();

                break;

        }
    }
}
