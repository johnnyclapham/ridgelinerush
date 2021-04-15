//
// Created by Evelyn on 3/24/2021.
//

#ifndef RIDGELINERUSH_TERRAIN_H
#define RIDGELINERUSH_TERRAIN_H

#include "Column.h"
#include "Obstacle.h"
#include <vector>
#include "ObstaclePicker.h"

class Terrain {
public:
    // constructor //
    Terrain();

    // mutators //
    void spawnColumn();
    void despawnColumn();
    void spawnObstacle();
    void despawnObstacle();
    void move(float x_diff, float y_diff);

    std::vector<Column> columnList;
    std::vector<Obstacle> obstacleList;

private:
    void setBaseMap();
    int cycle;
    ObstaclePicker picker;
};

#endif //RIDGELINERUSH_TERRAIN_H
