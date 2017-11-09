//
// Created by Sondre on 19.10.2017.
//

#include "level_1.h"
#include "../player.h"
#include "../pathPoints.h"
#include "../enemyShips.h"
#include <list>
#include <iostream>




player* Player;
enemyShips* Enemy;
pathPoints* PP;

float deltaTime;
int level_Clock = 0;


void level_1::Ship_wave()
{
    std::cout << "I am doing something" << std::endl;
    Enemy  = new enemyShips(200,500,100,0);
    level_1::Enemy_Objects.push_back(Enemy);
}




level_1::level_1(){
    Player = new player(300,200, 100);
    Enemy  = new enemyShips(300,500,100,0);
    Enemy_Objects.push_back(Enemy);
    Enemy = new enemyShips(500,800,100,1);
    Enemy_Objects.push_back(Enemy);
    //creating ponits for movement by enemys:
    PP = new pathPoints;
    PP->initTargetPoints();


    std::cout<<"breakpoint\n";

}


void level_1::GoNext(Machine &machine, sf::RenderWindow* window){

    deltaTime = clock.getElapsedTime().asSeconds();
    clock.restart();



    //Ship_wave();

    Player->ProcessEvents(window);
    Player->move();


    window->clear();

    /*for(Object* obj : Level_Objects)
    {
       window->draw(obj->getShape());
    }*/


    for(enemyShips* eneobj:Enemy_Objects)
    {
        eneobj->enemymovement(eneobj,deltaTime,PP);
        if(eneobj->destroyed){
            Enemy_Objects.remove(eneobj);
        }
        window->draw(eneobj->getShape());
        eneobj->move();
    }



    //gameInterface.health -= 10;


    if(Player->health > 0)
        Player->takeDamage(1);

    ui.setHealthPercentage(Player->health / Player->maxHealth * 100.0f);
    ui.setMoney(100);
    ui.update();

    window->draw(Player->getShape());


    for (Object* uiobject : ui.GetObjects())
    {
        window->draw(uiobject->getShape());
    }

    for (sf::Text* txt : ui.GetLabels())
    {
        window->draw(*txt);
    }

    window->display();
}