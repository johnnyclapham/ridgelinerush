//
// Created by Johnny using John's Hero.h as a template
//

#ifndef RIDGELINERUSH_DRAGON_H
#define RIDGELINERUSH_DRAGON_H
#include <SFML/Window.hpp>


class Dragon
{
public:
    // constructors //
    Dragon();
    Dragon(float x, float y);

    // mutators //
    void update(float time);
    void setPosition(float x, float y);

    // inspectors //
    sf::Vector2<float> getPosition();

    enum state {up, down};

private:
    // members //
    float width;
    float height;
    int movementIteration;

    sf::Vector2<float> position;

    //state dragonMovementState; // not needed right now
};

#endif // DRAGON_H
