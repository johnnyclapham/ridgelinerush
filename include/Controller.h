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
    void setMvmtUpKey(sf::Keyboard::Key k);
    void setMvmtLeftKey(sf::Keyboard::Key k);
    void setMvmtRightKey(sf::Keyboard::Key k);
    void setMvmtDownKey(sf::Keyboard::Key k);
    void setAttackKey(sf::Keyboard::Key k);
    void setPauseKey(sf::Keyboard::Key k);

    // inspectors //
    sf::Keyboard::Key getMvmtUpKey();
    sf::Keyboard::Key getMvmtLeftKey();
    sf::Keyboard::Key getMvmtRightKey();
    sf::Keyboard::Key getMvmtDownKey();
    sf::Keyboard::Key getAttackKey();
    sf::Keyboard::Key getPauseKey();

private:
    // members //
    Hero *playerHero;
    Launcher *weaponLauncher;
    std::string texture;
    sf::Keyboard::Key mvmt_up;
    sf::Keyboard::Key mvmt_left;
    sf::Keyboard::Key mvmt_right;
    sf::Keyboard::Key mvmt_down;
    sf::Keyboard::Key attack;
    sf::Keyboard::Key pause;
};

#endif // RIDGELINERUSH_CONTROLLER_H
