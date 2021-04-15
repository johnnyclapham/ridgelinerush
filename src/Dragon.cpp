//
// Created by Johnny on 4/8/2021 using John's Hero.c as a template
//

#include "Dragon.h"
#include <math.h>
#include <iostream>


Dragon::Dragon() {
    setPosition(0, 0);
    //dragonMovementState = up; // not needed right now
    movementIteration = 0;
    height = 60;
    width = 56;
    timer = sf::Clock();
    resetShootValues();
}

Dragon::Dragon(float x, float y) {
    setPosition(x, y);
}

void Dragon::update(float time){
    //100 cycles move up
    if (movementIteration<=99){
      //decrease y position of dragon
      setPosition(position.x, position.y-0.5*time);
      movementIteration+=1;

    //100 cycles move down
  } else if (movementIteration>=100 && movementIteration<=199) {
      //increase y position of dragon
      setPosition(position.x, position.y+0.5*time);
      movementIteration+=1;
    }
    //after 200 cycles reset ticker
    else if (movementIteration>=200){
      movementIteration=0;
    }
    int iter = 0;
    // iterate through projectiles for updates
    for (auto i = projectileList.begin(); i < projectileList.end(); i++) {
        projectileList.at(iter).move();
        projectileList.at(iter).handleCollision();
        if (projectileList.at(iter).getPosition().x < 0) {
            projectileList.erase(i);
        }
        iter++;
    }
    shoot();
    //std::cout << "movement iteration: "<<movementIteration<<"\n";
}


void Dragon::shoot() {
    if (timer.getElapsedTime().asMilliseconds() >= projectileDelay) {
        projectileList.emplace_back(Projectile(position.x+160, position.y+110, 50, projectileAngle, projectileSpeed, RIGHT));
        timer.restart();
    }
}

sf::Vector2<float> Dragon::getPosition() {
    return position;
}

void Dragon::setPosition(float x, float y) {
    position = sf::Vector2<float>(x,y);
}

void Dragon::resetShootValues() {
  timer.restart();
  projectileAngle = 0; // base angle (between -1 and 1)
  projectileSpeed = 1; // base speed constant
  projectileDamage = 1; // base damage
  projectileDelay = 2000; // base fire delay, in milliseconds
}
