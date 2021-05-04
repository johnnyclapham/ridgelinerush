//
// Created by Johnny using John's Hero.h as a template
//

#ifndef RIDGELINERUSH_DRAGON_H
#define RIDGELINERUSH_DRAGON_H
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
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
    int getTimesKilled();


    void hit();

    void shoot();

    void fireSound();
    void heroHit();

    enum state {up, down};

    std::vector<Projectile> projectileList;

    Hitbox getHitbox();

    bool isVisible();

private:
    // members //
    sf::SoundBuffer buffer;
    sf::Sound sound;
    std::string bufferPath;

    sf::SoundBuffer heroHitBuffer;
    sf::Sound heroHitSound;
    std::string heroHitBufferPath;

    Hero *hero;
    Terrain *terrain;
    float width;
    float height;
    int health;
    int timesKilled;
    float projectileDelay;
    float projectileDamage;
    float projectileSpeed;
    float projectileAngle = 0;
    int movementIteration;

    bool visible;
    sf::Clock respawnTimer;

    sf::Clock timer;

    sf::Vector2<float> position;


    //state dragonMovementState; // not needed right now
};

#endif // DRAGON_H
