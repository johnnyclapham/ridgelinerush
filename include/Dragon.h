//
// Created by Johnny using John's Hero.h as a template
//

#ifndef RIDGELINERUSH_DRAGON_H
#define RIDGELINERUSH_DRAGON_H
#include <SFML/Window.hpp>
#include "Projectile.h"


class Dragon
{
public:
    // constructors //
    Dragon();
    Dragon(float x, float y);

    // mutators //
    void update(float time);
    void setPosition(float x, float y);
    void resetShootValues();

    // inspectors //
    sf::Vector2<float> getPosition();

    void shoot();

    enum state {up, down};

    std::vector<Projectile> projectileList;

private:
    // members //
    float width;
    float height;
    float projectileDelay;
    float projectileDamage;
    float projectileSpeed;
    float projectileAngle = 0;
    int movementIteration;
    sf::Clock timer;

    sf::Vector2<float> position;


    //state dragonMovementState; // not needed right now
};

#endif // DRAGON_H
