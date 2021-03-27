//
// Created by Evelyn on 3/25/2021.
//

#include "Logic.h"
#include "Terrain.h"


Logic::Logic() {
    terrain = Terrain();
}

void Logic::update(int ms) {
    terrain.move(1, 1);
}

Terrain Logic::getTerrain() {
    return terrain;
}

