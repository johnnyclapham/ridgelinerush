//
// Created by John on 3/28/2021.
//

#include "Hero.h"
#include <math.h>
#include <iostream>
#include "Terrain.h"
#include "Column.h"
#include <cstddef>

Hero::Hero() {
    setPosition(900, 0);
    velocity = sf::Vector2<float>(0, 0);
    playerState = airborne;
    height = 60;
    width = 56;
    health = 100;
    damage = 5;
    topCollisionPt = position+sf::Vector2<float>(width/2, 0);
    bottomCollisionPt = position+sf::Vector2<float>(width/2, height);
    leftCollisionPt = position+sf::Vector2<float>(0, 2*height/3);
    rightCollisionPt = position+sf::Vector2<float>(width, 2*height/3);
    powerup = Powerup();
}

Hero::Hero(float x, float y) {
    setPosition(x, y);
}

void Hero::update(float time, Terrain terrain){
    if(playerState == airborne){
       velocity += sf::Vector2<float>(0, .0035*time);
    }
    topCollisionPt = position+sf::Vector2<float>(width/2, 0);
    bottomCollisionPt = position+sf::Vector2<float>(width/2, height);
    leftCollisionPt = position+sf::Vector2<float>(0, 2*height/3);
    rightCollisionPt = position+sf::Vector2<float>(width, 2*height/3);
    changePosition(velocity, terrain);
    setPosition(position.x-time, position.y+time);
}

void Hero::changePosition(sf::Vector2<float> change, Terrain terrain) {
    sf::Vector2<float> newPosition = checkCollision(change, terrain);
    setPosition(newPosition);
}

void Hero::setPosition(float x, float y) {
    position = sf::Vector2<float>(x,y);
}

void Hero::setPosition(sf::Vector2<float> newPosition) {
    position = newPosition;
}

void Hero::jump(){
    //std::cout << position.x<< std::endl;
    if(playerState == ground){
        playerState = airborne;
        velocity.y -= .2;
    }
}

void Hero::driftLeft(){
    //std::cout << position.x<< std::endl;
    if(playerState == airborne){
        velocity.x -= .00008;
    }
}

void Hero::driftRight(){
    //std::cout << position.x<< std::endl;
    if(playerState == airborne){
        velocity.x += .00008;
    }
}

void Hero::applyPowerup() {
    switch (powerup.getPowerupType()) {
        case PT::damage_boost: damage *= 2;
        case PT::health_boost: if (health < 150) { health += 20; }
        case PT::jump_boost: velocity.y *= 2;
        case PT::speed_boost: velocity.x *= 2;
        default: return;
    }
} // need to implement timer in game loop for next sprint

sf::Vector2<float> Hero::getPosition() { return position; }

int Hero::getHealth() { return health; }

int Hero::getDamage() { return damage; }

// Takes the current terrain, current position of the hero, and the proposed new position of the hero and returns
// The position of where the hero should be with collision taken into account. Modifies state of hero in accordance
// with the surface he is colliding into.
sf::Vector2<float> Hero::checkCollision(sf::Vector2<float> change, Terrain terrain){
    std::vector<Column> columnList = terrain.columnList;
    std::vector<Obstacle> obstacleList = terrain.obstacleList;

    std::vector<sf::Vector2<float>> originalPt = {topCollisionPt, bottomCollisionPt, leftCollisionPt, rightCollisionPt};
    std::vector<sf::Vector2<float>> step1 = {topCollisionPt+(0.33f*change), bottomCollisionPt+(0.33f*change), leftCollisionPt+(0.33f*change), rightCollisionPt+(0.33f*change)};
    std::vector<sf::Vector2<float>> step2 = {topCollisionPt+(0.66f*change), bottomCollisionPt+(0.66f*change), leftCollisionPt+(0.66f*change), rightCollisionPt+(0.66f*change)};
    std::vector<sf::Vector2<float>> step3 = {topCollisionPt+change, bottomCollisionPt+change, leftCollisionPt+change, rightCollisionPt+change};

    sf::Vector2<float> furthestValidChange =  0.0f*change;
    intersectionType intersection;
    //Keeps track of the most recent collision type we have encountered, so if on the next step we
    //find no collision at all, we know whether to interpret the stop as hitting a wall, floor, etc.
    Collision lastCollision = NO_COLLISION;

    // Check if we can move the full length; if so we don't have to check any further steps
    bool noneIntersect = true;
    Collision collision;
    for(int i = 0; i < columnList.size(); i++){
        collision = columnList[i].intersecting(originalPt, step3);
        if(collision != NO_COLLISION){
            noneIntersect = false;
            lastCollision = collision;
        }
    }
    for(int i = 0; i < obstacleList.size(); i++){
        collision = obstacleList[i].intersecting(originalPt, step3);
        if(obstacleList[i].intersecting(originalPt, step3) != NO_COLLISION){
            noneIntersect = false;
            lastCollision = collision;
        }
    }
    if(noneIntersect){
        return position+change;
    }

    // Since the last step wasn't valid, we check the next to last step
    noneIntersect = true;
    for(int i = 0; i < columnList.size(); i++){
        collision = columnList[i].intersecting(originalPt, step2);
        if(collision != NO_COLLISION){
            noneIntersect = false;
            lastCollision = collision;
        }
    }
    for(int i = 0; i < obstacleList.size(); i++){
        collision = obstacleList[i].intersecting(originalPt, step2);
        if(obstacleList[i].intersecting(originalPt, step2) != NO_COLLISION){
            noneIntersect = false;
            lastCollision = collision;
        }
    }
    if(noneIntersect){
        if(lastCollision == WALL){
            velocity.x = 0;
        } else if (lastCollision == FLOOR){
            std::cout << "floor collision" << std::endl;
            playerState = ground;
            velocity.y = 0;
            velocity.x = 0;
        }
        return position+0.66f*change;
    }

    // Now check the first step since the final two were not valid
    noneIntersect = true;
    for(int i = 0; i < columnList.size(); i++){
        collision = columnList[i].intersecting(originalPt, step1);
        if(collision != NO_COLLISION){
            noneIntersect = false;
            lastCollision = collision;
        }
    }
    for(int i = 0; i < obstacleList.size(); i++){
        collision = obstacleList[i].intersecting(originalPt, step1);
        if(obstacleList[i].intersecting(originalPt, step1) != NO_COLLISION){
            noneIntersect = false;
            lastCollision = collision;
        }
    }
    if(noneIntersect){
        if(lastCollision == WALL){
            velocity.x = 0;
        } else if (collision == FLOOR){
            std::cout << "floor collision" << std::endl;
            playerState = ground;
            velocity.y = 0;
            velocity.x = 0;
        }
        return position+0.33f*change;
    }

    if(lastCollision == WALL){
        velocity.x = 0;
    } else if (lastCollision == FLOOR){
        std::cout << "floor collision" << std::endl;
        playerState = ground;
        velocity.y = 0;
        velocity.x = 0;
    }
    return position;
}

