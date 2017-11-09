//
// Created by Sondre on 19.10.2017.
//

#ifndef LAZCORN_OBJECT_H
#define LAZCORN_OBJECT_H

#include "SFML/Graphics.hpp"

class Object{
public:
    Object();

    sf::Vector2f velocity = sf::Vector2f(0, 0);
    sf::Vector2f Direction = sf::Vector2f(0,0);
    float speed =200;
    float health;
    float maxHealth;
    sf::RectangleShape rect;
    Object(int x, int y, float health, float maxHealth, sf::Color color, int height, int width);
    Object(int x, int y, float health, float maxHealth, sf::Texture* texture, int height, int width);
    sf::RectangleShape getShape();
    void move();


    void takeDamage(int damage);

    void Heal(int amount);

    void destroy();
};


#endif //LAZCORN_OBJECT_H
