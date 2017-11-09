//
// Created by BearMace on 06/11/2017.
//

#include <experimental/random>
#include "enemyShips.h"


sf::Texture* enemy_texture_ptr;
int * enemy_target_ptr;


enemyShips::enemyShips(int x, int y, int health,int target) {
    enemy_texture_ptr = &enemy_texture;
    enemy_target_ptr = &target;
    enemy_texture.loadFromFile("Assets/Enemy_Ship_fighter_2.png");
    this->rect.setTexture(enemy_texture_ptr);
    this->rect.setPosition(x,y);
    this->health = health;
    this->rect.setSize(sf::Vector2f(100,100));
    this->rect.setScale(1.f,-1.f);
}

enemyShips::enemyShips() {
    this->rect.setPosition(0,0);
    this->health = this->maxHealth;
}

int enemyShips::enemymovement(enemyShips* eneobj, float time,pathPoints* PP)
{
    eneobj->Direction.x = PP->targetPoints[eneobj->target].x-eneobj->rect.getPosition().x;
    eneobj->Direction.y = PP->targetPoints[eneobj->target].y-eneobj->rect.getPosition().y;

    float hyp = sqrt(eneobj->Direction.x*eneobj->Direction.x+eneobj->Direction.y*eneobj->Direction.y);

    eneobj->Direction.x   /=  hyp;
    eneobj->Direction.y   /=  hyp;

    //x += dirX*speed*delta;

    eneobj->velocity.x = eneobj->Direction.x*speed*time;
    eneobj->velocity.y = eneobj->Direction.y*speed*time;


    //std::cout<<"ships x velocity: "<<eneobj->velocity.x<<std::endl;
    //std::cout<<"ships y velocity: "<<eneobj->velocity.y<<std::endl;



    int i = int(eneobj->rect.getPosition().x+0.5);
    int y = int(eneobj->rect.getPosition().y +0.5);

    std::cout<<"ship coordinates x: "<<i<<std::endl;
    std::cout<<"ship coordinates y: "<<y<<std::endl;

    if(i == PP->targetPoints[eneobj->target].x  &&  y   ==  PP->targetPoints[eneobj->target].y)
    {
        //target  =   rand()%4;
        eneobj->target = std::experimental::randint(0, 7);


        std::cout<<"target"<<target<<std::endl;
        //=3;
    }
    if(eneobj->target == 3)
    {
        eneobj->destroyed = true;
    }
}
