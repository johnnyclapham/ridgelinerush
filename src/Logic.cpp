//
// Created by Evelyn on 3/25/2021.
//

#include "Logic.h"
#include "Terrain.h"


Logic::Logic() {
    terrain = Terrain();
}

Terrain Logic::getTerrain() {
    return terrain;
}

