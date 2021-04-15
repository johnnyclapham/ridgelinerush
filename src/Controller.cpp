//
// Created by John on 3/28/2021.
//

#include "Controller.h"
#include <math.h>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

Controller::Controller() {
}

Controller::Controller(Hero *hero, Launcher *launcher) {
    playerHero = hero;
    weaponLauncher = launcher;
}

void Controller::update(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        (*playerHero).jump();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if((*playerHero).getFloorType() != NO_COLLISION){
           (*playerHero).walk(LEFT);
        } else {
            (*playerHero).driftLeft();
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if((*playerHero).getFloorType() != NO_COLLISION){
           (*playerHero).walk(RIGHT);
        } else {
            (*playerHero).driftRight();
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        (*weaponLauncher).shoot();
    }
}



