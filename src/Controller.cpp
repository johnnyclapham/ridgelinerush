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
    if (sf::Keyboard::isKeyPressed(mvmt_up))
    {
        (*playerHero).jump();
    }

    if (sf::Keyboard::isKeyPressed(mvmt_left))
    {
        (*playerHero).driftLeft();
    }

    if (sf::Keyboard::isKeyPressed(mvmt_right))
    {
        (*playerHero).driftRight();
    }
}

sf::Keyboard::Key Controller::getMvmtUpKey() { return mvmt_up; }

sf::Keyboard::Key Controller::getMvmtLeftKey() { return mvmt_left; }

sf::Keyboard::Key Controller::getMvmtRightKey() { return mvmt_right; }

sf::Keyboard::Key Controller::getAttackKey() { return attack; }

sf::Keyboard::Key Controller::getPauseKey() { return pause; }

void Controller::setMvmtUpKey(sf::Keyboard::Key k) { mvmt_up = k; }

void Controller::setMvmtLeftKey(sf::Keyboard::Key k) { mvmt_left = k; }

void Controller::setMvmtRightKey(sf::Keyboard::Key k) { mvmt_right = k; }

void Controller::setAttackKey(sf::Keyboard::Key k) { attack = k; }

void Controller::setPauseKey(sf::Keyboard::Key k) { pause = k; }


