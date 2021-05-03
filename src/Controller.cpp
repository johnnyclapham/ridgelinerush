//
// Created by John on 3/28/2021.
//

#include "Controller.h"
#include <math.h>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Settings.h"

Controller::Controller() {
}

Controller::Controller(Hero *hero, Launcher *launcher) {
    playerHero = hero;
    weaponLauncher = launcher;
}

void Controller::update(){
    if (sf::Keyboard::isKeyPressed(mvmt_up))
    {
        (*playerHero).jump();
    }

    if (sf::Keyboard::isKeyPressed(mvmt_left))
    {
        if((*playerHero).getFloorType() != NO_COLLISION){
           (*playerHero).walk(LEFT);
        } else {
            (*playerHero).driftLeft();
        }
    }

    if (sf::Keyboard::isKeyPressed(mvmt_right))
    {
        if((*playerHero).getFloorType() != NO_COLLISION){
           (*playerHero).walk(RIGHT);
        } else {
            (*playerHero).driftRight();
        }
    }

    if (sf::Keyboard::isKeyPressed(mvmt_down))
    {
        if((*playerHero).getFloorType() == NO_COLLISION){
            (*playerHero).fastFall();
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        (*weaponLauncher).shoot();
    }
}

sf::Keyboard::Key Controller::getMvmtUpKey() { return mvmt_up; }

sf::Keyboard::Key Controller::getMvmtLeftKey() { return mvmt_left; }

sf::Keyboard::Key Controller::getMvmtRightKey() { return mvmt_right; }

sf::Keyboard::Key Controller::getMvmtDownKey() { return mvmt_down; }

sf::Keyboard::Key Controller::getAttackKey() { return attack; }

sf::Keyboard::Key Controller::getPauseKey() { return pause; }

void Controller::setMvmtUpKey(sf::Keyboard::Key k) { mvmt_up = k; }

void Controller::setMvmtLeftKey(sf::Keyboard::Key k) { mvmt_left = k; }

void Controller::setMvmtRightKey(sf::Keyboard::Key k) { mvmt_right = k; }

void Controller::setMvmtDownKey(sf::Keyboard::Key k) { mvmt_down = k; }

void Controller::setAttackKey(sf::Keyboard::Key k) { attack = k; }

void Controller::setPauseKey(sf::Keyboard::Key k) { pause = k; }


