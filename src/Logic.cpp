//
// Created by Evelyn on 3/25/2021.
//

#include "Logic.h"
#include "Terrain.h"
#include "Hero.h"
#include "Dragon.h"
#include "Logic.h"
#include "Controller.h"
#include <iostream>


Logic::Logic() {
    terrain = Terrain();
    controller = Controller(&hero);
    hero = Hero();
    dragon = Dragon();
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

Dragon Logic::getDragon(){
  return dragon;
}
