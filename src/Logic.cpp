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
    controller = Controller(&hero, &launcher);
    hero = Hero();
    dragon = Dragon(&hero, &terrain);
    dragonAI = DragonAI(&dragon, &hero);
    settings = Settings(0);
    background = Background();

    controller.setMvmtUpKey(settings.getMvmtUpKey());
    controller.setMvmtLeftKey(settings.getMvmtLeftKey());
    controller.setMvmtRightKey(settings.getMvmtRightKey());
    controller.setAttackKey(settings.getAttackKey());
    controller.setQuitKey(settings.getQuitKey());

    // initialize launchers
    sf::Vector2f heroPosition = hero.getPosition();
    // sf::Vector2f dragonPosition = dragon.getPosition();
    launcher = Launcher(heroPosition.x, heroPosition.y, 20, 10);
    // dragonLauncher = Launcher(dragonPosition.x, dragonPosition.y, 50, 50);
}

void Logic::update(float time) {
    controller.update();
    hero.update(.5*time, terrain);
    terrain.move(.5*time, .5*time);
    dragon.update(.5*time);
    dragonAI.update(.5*time);
    // settings.read();
    launcher.updateHero(.5*time, &terrain, &dragon, &hero);
    dragonLauncher.updateDragon(.5*time, &terrain, &dragon, &hero);
    background.update(.5*time);
}

Terrain Logic::getTerrain() {
    return terrain;
}

Hero Logic::getHero() {
    return hero;
}

Hero* Logic::getHeroPointer() {
    return &hero;
}

Dragon Logic::getDragon() {
    return dragon;
}

Background Logic::getBackground() {
    return background;
}

Launcher Logic::getLauncher() {
    return launcher;
}
