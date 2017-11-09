//
// Created by Sondre on 19.10.2017.
//

#include "Object.h"

Object::Object(){

};

Object::Object(int x, int y, float health, float maxHealth, sf::Color color, int height, int width){
    this->maxHealth = maxHealth;
    this->health = health;
    this->rect.setPosition(x,y);
    this->rect.setSize(sf::Vector2f(height, width));
    this->rect.setFillColor(color);
}

Object::Object(int x, int y, float health, float maxHealth, sf::Texture* texture, int height, int width){
    this->maxHealth = maxHealth;
    this->health = health;
    this->rect.setPosition(x,y);
    this->rect.setTexture(texture);
    this->rect.setSize(sf::Vector2f(height, width));
}

sf::RectangleShape Object::getShape(){
    return Object::rect;
}

void Object::move(){
    this->rect.setPosition(rect.getPosition().x + velocity.x, rect.getPosition().y + velocity.y);
}

void Object::takeDamage(int damage){
    if(this->health < damage){
        this->health = 0;
    }
    else
        this->health -= damage;

    if(this->health == 0){
        this->destroy();
    }
}

void Object::Heal(int amount){
    this->health += amount;
}

void Object::destroy(){

}