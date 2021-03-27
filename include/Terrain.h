//
// Created by Evelyn on 3/24/2021.
//

#ifndef CSCI437_TERRAIN_H
#define CSCI437_TERRAIN_H

#include "Column.h"
#include <vector>

class Terrain {
public:
    // constructor //
    Terrain();

    // mutators //
    void spawnColumn();
    void despawnColumn();
    void move(float x_diff, float y_diff);

    std::vector<Column> columnList;

private:
    void setBaseMap();
    int cycle;
};

#endif //CSCI437_TERRAIN_H
