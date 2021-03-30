//
// Created by John on 3/28/2021.
//

#ifndef RIDGELINERUSH_CONTROLLER_H
#define RIDGELINERUSH_CONTROLLER_H
#include "Hero.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Controller
{
public:
    // constructors //
    Controller();
    Controller(Hero *hero);

    // mutators //
    void update();

private:
    // members //
    Hero *playerHero;
    std::string texture;
};

#endif // RIDGELINERUSH_CONTROLLER_H
