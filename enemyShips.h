//
// Created by BearMace on 06/11/2017.
//

#ifndef LAZCORN_ENEMYSHIPS_H
#define LAZCORN_ENEMYSHIPS_H


#include "Object.h"
#include "pathPoints.h"
#include <cmath>
#include <iostream>
class enemyShips    :   public Object
{
public:
    enemyShips();
    enemyShips(int x, int y, int health,int target);
    int target;
    bool destroyed = false;
    void ProcessEvents(sf::RenderWindow* window);
    sf::Texture enemy_texture;

    //enemy movement
    int enemymovement(enemyShips* enemy,float time,pathPoints* PP);

};


#endif //LAZCORN_ENEMYSHIPS_H
