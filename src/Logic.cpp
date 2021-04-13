//
// Created by Evelyn on 3/25/2021.
//

#include "Logic.h"
#include "Terrain.h"
#include "Hero.h"
#include "Dragon.h"
#include "Launcher.h"
#include "Logic.h"
#include "Controller.h"
#include <iostream>
#include <SFML/Window.hpp>


Logic::Logic() {
    terrain = Terrain();
    controller = Controller(&hero);
    hero = Hero();
    dragon = Dragon();
    sf::Vector2f heroPosition = hero.getPosition();
    std::cout << heroPosition.x << " " << heroPosition.y << std::endl;
    launcher = Launcher(heroPosition.x, heroPosition.y);
}

void Logic::update(float time) {
    controller.update();
    hero.update(.5*time, terrain);
    terrain.move(.5*time, .5*time);
    dragon.update(.5*time);
}

Terrain Logic::getTerrain() {
    return terrain;
}

Hero Logic::getHero() {
    return hero;
}

Dragon Logic::getDragon() {
    return dragon;
}

// Launcher Logic::getLauncher() {
//     return launcher;
// }
