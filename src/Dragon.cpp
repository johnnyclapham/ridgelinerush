//
// Created by Johnny on 4/8/2021 using John's Hero.c as a template
//

#include "Dragon.h"
#include "Hero.h"
#include "Terrain.h"
#include <SFML/Audio.hpp>
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
    timesKilled = 0;
    health = 5;
    height = 250;
    width = 200;
    resetShootValues();
    timer = sf::Clock();
    respawnTimer = sf::Clock();
    visible = true;
}

Dragon::Dragon(float x, float y, Hero *hero, Terrain *terrain) {
    this->hero = hero;
    this->terrain = terrain;
    setPosition(x, y);
}

void Dragon::update(float time){
    if (!visible && respawnTimer.getElapsedTime().asMilliseconds() > 5000) visible = true;
    // update projectiles - all of the shooting AI is handled through DragonAI.cpp
    int iter = 0;
    // iterate through projectiles for updates
    for (auto i = projectileList.begin(); i < projectileList.end(); i++) {
        projectileList.at(iter).move();
        if (projectileList.at(iter).handleCollision(terrain, hero->getHitbox()) == HERO){
            hero->modifyHealth(-1*projectileList.at(iter).damage);
            heroHit();
            if (hero->getHealth() == 0) hero->die();
            projectileList.erase(i);
        } else if (projectileList.at(iter).getPosition().x < 0 || projectileList.at(iter).handleCollision(terrain, hero->getHitbox()) == TERRAIN) {
            projectileList.erase(i);
        }
        iter++;
    }
    //std::cout << "movement iteration: "<<movementIteration<<"\n";
}


void Dragon::shoot() {
    projectileList.emplace_back(Projectile(position.x+160, position.y+110, 1, projectileAngle, projectileSpeed, RIGHT, 50, 50));
    fireSound();
}

void Dragon::fireSound() {
    std::string path = "assets/sounds/dragon_fire.wav";
    if (!buffer.loadFromFile(path)) {
        path = "../" + path;
        std::cout << "Error with standard path. Now loading   : " << path << " \n";
    }
    buffer.loadFromFile(path);
    sound.setBuffer(buffer);
    sound.setVolume(5);
    sound.setPitch(.6);
    sound.play();
}

void Dragon::heroHit() {
    std::string path = "assets/sounds/dragon_fire.wav";
    if (!heroHitBuffer.loadFromFile(path)) {
        path = "../" + path;
        std::cout << "Error with standard path. Now loading   : " << path << " \n";
    }
    heroHitBuffer.loadFromFile(path);
    heroHitSound.setBuffer(heroHitBuffer);
    heroHitSound.setVolume(2);
    heroHitSound.setPitch(1.1);
    heroHitSound.play();
}

void Dragon::setProjectileAngle(float angle) {
    projectileAngle = angle;
}

float Dragon::getDelay() {
    return projectileDelay;
}

void Dragon::hit() {
    health--;
    if (!health) {
        std::cout << "DRAGON KILLED" << std::endl;
        // despawn dragon temporarily
        timesKilled++;
        visible = false;
        respawnTimer.restart();
        health = 5;
        setPosition(0, 200);
    }
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
    if (visible) return Hitbox(position.x, position.y, width, height);
    else return Hitbox(WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0); // return bottom corner, for no hitbox
}

bool Dragon::isVisible() {
    return visible;
}