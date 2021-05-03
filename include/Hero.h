//
// Created by John on 3/28/2021.
//

#ifndef RIDGELINERUSH_HERO_H
#define RIDGELINERUSH_HERO_H
#include <SFML/Window.hpp>
#include "Terrain.h"
#include "Powerup.h"
#include "Hitbox.h"


class Hero
{
public:
    // constructors //
    Hero();
    Hero(float x, float y);

    // mutators //
    void update(float time, Terrain terrain);
    void move(float x_diff, float y_diff);
    void setPosition(float x, float y);
    void setPosition(sf::Vector2<float> newPosition);
    void changePosition(sf::Vector2<float> change, Terrain terrain);
    void jump();
    void driftLeft();
    void driftRight();
    void fastFall();
    void applyPowerup();
    void setPowerup(std::string s);
    void setPowerupPos(int x, int y);
    void setPowerupBuffer(int p);
    bool healthDepleted();



    // other //
    sf::Vector2<float> checkCollision(sf::Vector2<float> change, Terrain terrain);
    sf::Vector2<float> getCollisionPt(int index);
    Collision getFloorType();
    Direction getDirection();

    // inspectors //
    sf::Vector2<float> getPosition();
    bool isGrounded(Terrain terrain);
    bool isAirborne();
    int getHealth();
    int getMaxHealth();
    void modifyHealth(int amount);
    int getDamage();
    std::string getPowerup();
    int getPowerupBuffer();
    int getXpos();
    int getYpos();

    enum state {ground, airborne};

    void walk(Direction direction);
    void die();

    Hitbox getHitbox();
private:
    // members //
    float width;
    float height;
    int health;
    int maxHealth;
    int damage;
    int timer;
    bool dead;
    Direction facingDirection;
    sf::Vector2<float> position;
    sf::Vector2<float> velocity;
    sf::Vector2<float> velocityBuffer;
    sf::Vector2<float> positionBuffer;

    sf::Vector2<float> topLeftCollisionPt;
    sf::Vector2<float> topRightCollisionPt;
    sf::Vector2<float> bottomLeftCollisionPt;
    sf::Vector2<float> bottomRightCollisionPt;

    Collision floorType;
    state playerState;
    Powerup powerup;
};

#endif // HERO_H
