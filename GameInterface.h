//
// Created by Sondre on 19.10.2017.
//

#ifndef LAZCORN_GAMEINTERFACE_H
#define LAZCORN_GAMEINTERFACE_H

#include "machine.h"
#include "Object.h"
#include <list>

class GameInterface {
public:
    GameInterface();
    void update();
    std::list<Object*> UI_Objects;
    std::list<sf::Text*> texts;
    std::list<Object*> GetObjects();
    std::list<sf::Text*> GetLabels();
    sf::Texture hud_main;
    sf::Texture hp_bar;
    sf::Texture energy_bar;
    sf::Texture frames;

    sf::Texture priWeapon;
    sf::Texture secWeapon_1;
    sf::Texture secWeapon_2;

    void setHealthPercentage(float percentage);

    void setMoney(int money);
};


#endif //LAZCORN_GAMEINTERFACE_H
