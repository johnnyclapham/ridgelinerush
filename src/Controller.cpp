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

Controller::Controller(Hero *hero) {
    playerHero = hero;
}

void Controller::update(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        (*playerHero).jump();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        (*playerHero).driftLeft();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        (*playerHero).driftRight();
    }
}



