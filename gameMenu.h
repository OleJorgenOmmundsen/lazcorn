//
// Created by BearMace on 13/10/2017.
//

#ifndef LAZCORN_GAMEMENU_H
#define LAZCORN_GAMEMENU_H

#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3


class gameMenu {

public:
    gameMenu(float width, float height);
    ~gameMenu();

    void draw(sf::RenderWindow* window_ptr);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }

private:
    int selectedItemIndex;
    sf::Font font;
    float fontsize = 100;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

};





#endif //LAZCORN_GAMEMENU_H
