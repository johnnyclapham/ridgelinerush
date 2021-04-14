//
// Created by John on 3/28/2021.
//

#ifndef RIDGELINERUSH_CONTROLLER_H
#define RIDGELINERUSH_CONTROLLER_H
#include "Hero.h"
#include "Launcher.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Controller
{
public:
    // constructors //
    Controller();
    Controller(Hero *hero, Launcher *launcher);

    // mutators //
    void update();

private:
    // members //
    Hero *playerHero;
    Launcher *weaponLauncher;
    std::string texture;
};

#endif // RIDGELINERUSH_CONTROLLER_H
