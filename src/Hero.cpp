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
    velocityBuffer = sf::Vector2<float>(0, 0);
    positionBuffer = sf::Vector2<float>(0, 0);
    facingDirection = RIGHT;
    playerState = airborne;
    floorType = NO_COLLISION;
    height = HERO_HEIGHT;
    width = HERO_WIDTH;
    health = 10;
    maxHealth = 10;
    damage = 5;
    powerup = Powerup();
    timer = 0;
    dead = false;
    topLeftCollisionPt = position+sf::Vector2<float>(20, 20);
    topRightCollisionPt = position+sf::Vector2<float>(width-20, 20);
    bottomLeftCollisionPt = position+sf::Vector2<float>(20, height);
    bottomRightCollisionPt = position+sf::Vector2<float>(width-20, height);
    s.read();
}

Hero::Hero(float x, float y) {
    setPosition(x, y);
}

void Hero::update(float time, Terrain terrain){
    if(playerState == airborne){
       velocity += sf::Vector2<float>(0, .2*time);
    }

    velocity += velocityBuffer; //*time;
    positionBuffer = positionBuffer*time;
    topLeftCollisionPt = position+sf::Vector2<float>(20, 5);
    topRightCollisionPt = position+sf::Vector2<float>(width-20, 5);
    bottomLeftCollisionPt = position+sf::Vector2<float>(20, height);
    bottomRightCollisionPt = position+sf::Vector2<float>(width-20, height);
    changePosition(velocity*time+positionBuffer, terrain); // changePosition(velocity+positionBuffer, terrain);
    setPosition(position.x-time, position.y+time);
    velocityBuffer = sf::Vector2<float>(0, 0);
    positionBuffer = sf::Vector2<float>(0, 0);
    //applyPowerup(); //moved
    // if ( (position.x < powerup.getXPos() + 2) &&
    //       (position.x < powerup.getXPos() - 2) &&
    //       (position.y < powerup.getYPos() + 2) &&
    //       (position.y < powerup.getYPos() - 2) ) {

    //new collision detection below
    if ((position.x < powerup.getXPos()+50 ) &&
        ((position.x + 50 > powerup.getXPos())) &&
        (position.y<powerup.getYPos()+50) &&
        (position.y + 50 > powerup.getYPos()))
        {

        if (powerup.getBuffer() == 1) {
          powerup.setPowerupType("damage boost");
          std::cout << "\nPowerup Consumed (Damage): "<<powerup.getBuffer()<<"\n";

         }
        if (powerup.getBuffer() == 2) {
          powerup.setPowerupType("health boost");
          std::cout << "\nPowerup Consumed (Health): "<<powerup.getBuffer()<<"\n";

         }
        if (powerup.getBuffer() == 3) {
          powerup.setPowerupType("jump boost");
          std::cout << "\nPowerup Consumed (jump): "<<powerup.getBuffer()<<"\n";

         }
        if (powerup.getBuffer() == 4) {
          powerup.setPowerupType("speed boost");
          std::cout << "\nPowerup Consumed (speed): "<<powerup.getBuffer()<<"\n";

         }
         applyPowerup();
         setPowerupPos(10,WINDOW_HEIGHT-60); // Move powerup to UI space
    }
    // std::cout << "powerupX: "<<powerup.getXPos();
    // std::cout << "powerupY: "<<powerup.getYPos()<<"\n";
    // std::cout << "heroX: "<<position.x;
    // std::cout << "heroY: "<<position.y << "\n";
    if (getPowerup() != "no boost") {
        timer += time;
        if (time > 10000000) { powerup.setPowerupType("no boost"); timer = 0; }

        //applyPowerup(); //Causes many bad things
    }

    //applyPowerup();

    //check if hero is too high
    if (position.y<=-100){
      //velocity.y *= -1;
      position.y = -99;
      std::cout << "\n\nToo high!\n\n";
    }

    //check if hero is off right of screen
    if (position.x>=WINDOW_WIDTH){
      position.x -= 10;
      std::cout << "\n\nToo wide!\n\n";
    }

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

bool Hero::isAirborne() { return (playerState == airborne); }

void Hero::jump(){
    if(playerState == ground){
        playerState = airborne;
        floorType = NO_COLLISION;
        velocityBuffer.y -= 10.5;
    }
}

void Hero::driftLeft(){
    //std::cout << position.x<< std::endl;
    if(playerState == airborne && velocity.x > -6){
        velocityBuffer.x -= .02;
    }
    facingDirection = LEFT;
}

void Hero::driftRight(){
    //std::cout << position.x<< std::endl;
    if(playerState == airborne && velocity.x < 6){
        velocityBuffer.x += .02;
    }
    facingDirection = RIGHT;
}

void Hero::fastFall(){

    std::cout << "fast fall" << std::endl;
    if(playerState == airborne && velocity.y < 3){
        velocityBuffer.y += 4;
    }
}

void Hero::walk(Direction direction){
    if(direction == LEFT){
        facingDirection = LEFT;
        switch(floorType){
            case LEFT_SLOPE:
                positionBuffer.x -= 3;
                positionBuffer.y += 3;
                break;
            case RIGHT_SLOPE:
                positionBuffer.x += 4;
                positionBuffer.y -= 4;
                break;
            case FLOOR:
                positionBuffer.x -= 5;
        }
    }  else if(direction == RIGHT){
        facingDirection = RIGHT;
        switch(floorType){
            case LEFT_SLOPE:
                positionBuffer.x += 4;
                positionBuffer.y -= 4;
                break;
            case RIGHT_SLOPE:
                positionBuffer.x -= 3;
                positionBuffer.y += 3;
                break;
            case FLOOR:
                positionBuffer.x += 5;
        }
    }
}

void Hero::powerupSound() {
    if (bufferPath == "") {
        std::string path = "assets/sounds/power_up.wav";
        if (!buffer.loadFromFile(path)) {
            path = "../" + path;
        }
        bufferPath = path;
    }
    buffer.loadFromFile(bufferPath);
    sound.setBuffer(buffer);
    sound.setVolume(s.getVolume());
    sound.play();
}

void Hero::applyPowerup() {
    powerupSound();
    switch (powerup.getPowerupType()) {
        case PT::damage_boost:
          std::cout << "Old damage: "<< damage;
          damage *= 1.1;
          std::cout << " New damage: "<< damage<<"\n\n";
          break;

        case PT::health_boost:
          std::cout << "Old health: "<< health;
          health += 2;
          std::cout << " New health: "<< health<<"\n\n";
          break;

        case PT::jump_boost:
          std::cout << "Old velocity.y: "<< velocity.y;
          velocity.y *= 1.1;
          std::cout << " New velocity.y: "<< velocity.y<<"\n\n";
          break;

        case PT::speed_boost:
          std::cout << "Old velocity.x: "<< velocity.x;
          velocity.x *= 1.1;
          std::cout << " New velocity.x: "<< velocity.x<<"\n\n";
          break;
        default:  return;
    }
}

std::string Hero::getPowerup() { return powerup.powerupToStr(); }

void Hero::setPowerup(std::string s) { powerup.setPowerupType(s); }

void Hero::setPowerupPos(int x, int y) { powerup.setPos(x, y); }

void Hero::setPowerupBuffer(int p) { powerup.setBuffer(p); }

int Hero::getPowerupBuffer(){
  return powerup.getBuffer();
}

sf::Vector2<float> Hero::getPosition() { return position; }

// Health related methods

int Hero::getHealth() { return health; }
int Hero::getMaxHealth() { return maxHealth; }

void Hero::modifyHealth(int amount){
    std::cout << "here" << std::endl;
    if(health + amount > maxHealth){
        health = maxHealth;
    } else if (health + amount < 0){
        health = 0;
    } else {
        health += amount;
    }
}

int Hero::getDamage() { return damage; }

int Hero::getXpos() {
  return powerup.getXPos();
}

int Hero::getYpos() {
  return powerup.getYPos();
}

Collision Hero::getFloorType(){
    return floorType;
}

Direction Hero::getDirection(){
    return facingDirection;
}

sf::Vector2<float> Hero::getCollisionPt(int index) {
    switch(index){
        case 0:
            return topLeftCollisionPt;
        case 1:
            return topRightCollisionPt;
        case 2:
            return bottomLeftCollisionPt;
        case 3:
            return bottomRightCollisionPt;
    }
}

// Takes the current terrain, current position of the hero, and the proposed new position of the hero and returns
// The position of where the hero should be with collision taken into account. Modifies state of hero in accordance
// with the surface he is colliding into.
sf::Vector2<float> Hero::checkCollision(sf::Vector2<float> change, Terrain terrain){
    std::vector<Column> columnList = terrain.columnList;
    std::vector<Obstacle> obstacleList = terrain.obstacleList;

    std::vector<sf::Vector2<float>> originalPt = {topLeftCollisionPt, topRightCollisionPt, bottomLeftCollisionPt, bottomRightCollisionPt};
    std::vector<sf::Vector2<float>> step1 = {topLeftCollisionPt+(0.33f*change), topRightCollisionPt+(0.33f*change), bottomLeftCollisionPt+(0.33f*change), bottomRightCollisionPt+(0.33f*change)};
    std::vector<sf::Vector2<float>> step2 = {topLeftCollisionPt+(0.66f*change), topRightCollisionPt+(0.66f*change), bottomLeftCollisionPt+(0.66f*change), bottomRightCollisionPt+(0.66f*change)};
    std::vector<sf::Vector2<float>> step3 = {topLeftCollisionPt+change, topRightCollisionPt+change, bottomLeftCollisionPt+change, bottomRightCollisionPt+change};

    sf::Vector2<float> furthestValidChange =  0.0f*change;
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
            //std::cout << lastCollision << std::endl;
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
        if(playerState == ground){
            // If any steps intersect, then it can't be a position where we need to re-examine whether the
            // player should be airborne or not. Then we check here to see if the player should be grounded right now.
            std::vector<sf::Vector2<float>> lowerPosition = {bottomLeftCollisionPt-sf::Vector2<float>(0,10), bottomRightCollisionPt-sf::Vector2<float>(0,10)};
            std::vector<sf::Vector2<float>> lowerPositionOffset = {bottomLeftCollisionPt+sf::Vector2<float>(0,10), bottomRightCollisionPt+sf::Vector2<float>(0,15)};

            noneIntersect = true;
            for(int i = 0; i < columnList.size(); i++){
                collision = columnList[i].intersecting(lowerPosition, lowerPositionOffset);
                if(collision != NO_COLLISION){
                    noneIntersect = false;
                }
            }
            for(int i = 0; i < obstacleList.size(); i++){
                collision = obstacleList[i].intersecting(lowerPosition, lowerPositionOffset);
                if(obstacleList[i].intersecting(lowerPosition, lowerPositionOffset) != NO_COLLISION){
                    noneIntersect = false;
                }
            }
            if(noneIntersect){
                playerState = airborne;
            }
        }
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
    // If no tiles intersect on this step, then we want to take the proper actions
    // considering the latest collision and then return this position since it is valid.
    if(noneIntersect){
        if(lastCollision == WALL){
            velocity.x = 0;
        } else if (lastCollision == FLOOR || lastCollision == LEFT_SLOPE || lastCollision == RIGHT_SLOPE){
            //std::cout << "changing to ground 2/3" << std::endl;
            playerState = ground;
            velocity.y = 0;
            velocity.x = 0;
            floorType = lastCollision;
        } else if (lastCollision == CEILING){
            velocity.y = 0;
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
        } else if (lastCollision == FLOOR || lastCollision == LEFT_SLOPE || lastCollision == RIGHT_SLOPE){
            //std::cout << "changing to ground 1/3" << std::endl;
            playerState = ground;
            velocity.y = 0;
            velocity.x = 0;
            floorType = lastCollision;
        } else if (lastCollision == CEILING){
            velocity.y = 0;
        }
        return position+0.33f*change;
    }

    if(lastCollision == WALL){
        velocity.x = 0;
    } else if (lastCollision == FLOOR || lastCollision == LEFT_SLOPE || lastCollision == RIGHT_SLOPE){
        std::cout << "changing to ground 0/3" << std::endl;
        playerState = ground;
        velocity.y = 0;
        velocity.x = 0;
        floorType = lastCollision;
    } else if (lastCollision == CEILING){
        velocity.y = 0;
    }
    return position;
}

Hitbox Hero::getHitbox() {
    return Hitbox(position.x, position.y, HERO_WIDTH, HERO_HEIGHT);
}

bool Hero::healthDepleted() {
    return dead;
}

void Hero::die() {
    dead = true;
}
