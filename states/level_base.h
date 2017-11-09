//
// Created by Sondre on 19.10.2017.
//

#ifndef LAZCORN_LEVEL_BASE_H
#define LAZCORN_LEVEL_BASE_H

#include "SFML/Graphics.hpp"
#include "../pathPoints.h"
#include <experimental/random>

class level_base{
public:
    bool loadBackground(sf::Texture);

protected:
    sf::Texture background;
    //GameInterface gameInterface;

};


#endif //LAZCORN_LEVEL_BASE_H
