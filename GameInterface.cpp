//
// Created by Sondre on 19.10.2017.
//

#include "GameInterface.h"
#include <iostream>

// Declare and load a font
sf::Font font;
sf::Text* moneyLabel = new sf::Text("0$", font);
Object* healthBar_ptr;
Object* primary_weapon_ptr;
Object* secondary_weapon_1_ptr;
Object* secondary_weapon_2_ptr;


GameInterface::GameInterface(){
    sf::Texture* hud_main_ptr = &hud_main;
    sf::Texture* hp_bar_ptr = &hp_bar;
    sf::Texture* energy_bar_ptr = &energy_bar;
    sf::Texture* frames_ptr = &frames;

    sf::Texture* priWeapon_tx_ptr = &priWeapon;
    sf::Texture* secWeapon_1_tx_ptr = &secWeapon_1;
    sf::Texture* secWeapon_2_tx_ptr = &secWeapon_2;

    hud_main.loadFromFile("Assets/HUD-Main.png");
    hp_bar.loadFromFile("Assets/health-bar.png");
    energy_bar.loadFromFile("Assets/energy-bar.png");
    frames.loadFromFile("Assets/bar-frames.png");
    priWeapon.loadFromFile("Assets/placeholder.png");
    secWeapon_1.loadFromFile("Assets/placeholder.png");
    secWeapon_2.loadFromFile("Assets/placeholder.png");

    //781
    moneyLabel->setPosition(20,8);
    primary_weapon_ptr = new Object(1108,713, 0, 0, priWeapon_tx_ptr, 68, 68); //68x68
    secondary_weapon_1_ptr = new Object(1048,738, 0, 0, secWeapon_1_tx_ptr, 42, 42);
    secondary_weapon_2_ptr = new Object(987,738, 0, 0, secWeapon_2_tx_ptr, 42, 42);
    Object* e1 = new Object(0,0, 0, 0, hud_main_ptr, 1200, 800);
    healthBar_ptr = new Object(10,731, 0, 0, hp_bar_ptr, 191, 16);
    Object* e3 = new Object(10,777, 0, 0, energy_bar_ptr, 191, 16);
    Object* e4 = new Object(8,729, 0, 0,  frames_ptr, 195, 66);

    font.loadFromFile("Fonts/neuropol.ttf");
    UI_Objects.push_back(e1);
    UI_Objects.push_back(healthBar_ptr);
    UI_Objects.push_back(e3);
    UI_Objects.push_back(e4);
    UI_Objects.push_back(primary_weapon_ptr);
    UI_Objects.push_back(secondary_weapon_1_ptr);
    UI_Objects.push_back(secondary_weapon_2_ptr);
    texts.push_back(moneyLabel);
}

std::list<Object*> GameInterface::GetObjects(){
    return UI_Objects;
}

std::list<sf::Text*> GameInterface::GetLabels(){
    return texts;
}

void GameInterface::update(){

}

void GameInterface::setHealthPercentage(float percentage){
    healthBar_ptr->rect.setScale(percentage/100, 1.0);
}


void GameInterface::setMoney(int money){
    moneyLabel->setString(std::to_string(money) + "$");
}

void setWeapon(int index, Object* newWeapon){
    if(index == 0)
    {
        primary_weapon_ptr = newWeapon;
    }
    else if(index > 0)
    {
        //secondary_weapons_ptr[index-1] = newWeapon;
    }
}