//
// Created by Johnny on 4/8/2021 using John's Hero.c as a template
//

#include "Dragon.h"
#include "Hero.h"
#include "Terrain.h"
#include <math.h>
#include <iostream>

Dragon::Dragon() {
    // don't use this
}

Dragon::Dragon(Hero *hero, Terrain *terrain) {
    setPosition(0, 200);
    //dragonMovementState = up; // not needed right now
    this->hero = hero;
    this->terrain = terrain;
    movementIteration = 0;
    height = 250;
    width = 200;
    resetShootValues();
    timer = sf::Clock();
}

Dragon::Dragon(float x, float y, Hero *hero, Terrain *terrain) {
    this->hero = hero;
    this->terrain = terrain;
    setPosition(x, y);
}

void Dragon::update(float time){
    // update projectiles - all of the shooting AI is handled through DragonAI.cpp
    int iter = 0;
    // iterate through projectiles for updates
    for (auto i = projectileList.begin(); i < projectileList.end(); i++) {
        projectileList.at(iter).move();
        if (projectileList.at(iter).handleCollision(terrain, hero->getHitbox())) projectileList.erase(i);
        else if (projectileList.at(iter).getPosition().x < 0) {
            projectileList.erase(i);
        }
        iter++;
    }
    //std::cout << "movement iteration: "<<movementIteration<<"\n";
}


void Dragon::shoot() {
    if (timer.getElapsedTime().asMilliseconds() >= projectileDelay) {
        projectileList.emplace_back(Projectile(position.x+160, position.y+110, 50, projectileAngle, projectileSpeed, RIGHT, 50, 50));
        timer.restart();
    }
    
}

void Dragon::setProjectileAngle(float angle) {
    projectileAngle = angle;
}

float Dragon::getDelay() {
    return projectileDelay;
}

void Dragon::setDelay(float delay) {
    projectileDelay = delay;
}

sf::Vector2<float> Dragon::getPosition() {
    return position;
}

void Dragon::setPosition(float x, float y) {
    position = sf::Vector2<float>(x,y);
}

void Dragon::setProjectileSpeed(float speed) {
    projectileSpeed = speed;
}

void Dragon::resetShootValues() {
  timer.restart();
  projectileAngle = 0; // base angle (between -1 and 1)
  projectileSpeed = 4; // base speed constant
  projectileDamage = 1; // base damage
  projectileDelay = 2000; // base fire delay, in milliseconds
}

Hitbox Dragon::getHitbox() {
    return Hitbox(position.x, position.y, width, height);
}
