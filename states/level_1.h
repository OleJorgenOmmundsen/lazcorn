//
// Created by Sondre on 19.10.2017.
//

#ifndef LAZCORN_LEVEL_1_H
#define LAZCORN_LEVEL_1_H

#include "../state.h"
#include "../Object.h"
#include "../enemyShips.h"
#include "../GameInterface.h"
#include "level_base.h"

class level_1 : public State{
public:
    level_1();
    void GoNext(Machine &machine, sf::RenderWindow* window) override;
    void Ship_wave();
    sf::Texture player_tx;
    std::list<Object*> Level_Objects;
    std::list<enemyShips*> Enemy_Objects;
    GameInterface ui;

    sf::Clock clock;

    void MoveUp();

    void MoveDown();

    void MoveRight();

    void MoveLeft();
};


#endif //LAZCORN_LEVEL_1_H
