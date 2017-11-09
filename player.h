//
// Created by Sondre on 23.10.2017.
//

#ifndef LAZCORN_PLAYER_H
#define LAZCORN_PLAYER_H


#include "Object.h"

class player : public Object{
public:
    player();
    player(int x, int y, int health);
    void ProcessEvents(sf::RenderWindow* window);
    sf::Texture player_texture;
};


#endif //LAZCORN_PLAYER_H
