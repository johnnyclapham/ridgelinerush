//
// Created by Johnny using John's Hero.h as a template
//

#ifndef RIDGELINERUSH_DRAGON_H
#define RIDGELINERUSH_DRAGON_H
#include <SFML/Window.hpp>
#include "Projectile.h"
#include "Hitbox.h"
#include "Hero.h"


class Dragon
{
public:
    // constructors //
    Dragon();
    Dragon(Hero *hero, Terrain *terrain);
    Dragon(float x, float y, Hero *hero, Terrain *terrain);

    // mutators //
    void update(float time);
    void setPosition(float x, float y);
    void resetShootValues();

    void setDelay(float delay);
    void setProjectileAngle(float angle);
    void setProjectileSpeed(float speed);

    // inspectors //
    sf::Vector2<float> getPosition();
    float getDelay();

    void shoot();

    enum state {up, down};

    std::vector<Projectile> projectileList;

    Hitbox getHitbox();

private:
    // members //
    Hero *hero;
    Terrain *terrain;
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
