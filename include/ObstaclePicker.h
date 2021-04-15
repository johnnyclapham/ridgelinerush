//
// Created by Evelyn on 4/8/2021.
//

#ifndef RIDGELINERUSH_OBSTACLEPICKER_H
#define RIDGELINERUSH_OBSTACLEPICKER_H

#include "Obstacle.h"
#include <vector>

class ObstaclePicker {
public:
    ObstaclePicker();

    Obstacle getRandomObstacle();
    Obstacle getObstacleAt(int index);

private:
    std::vector<Obstacle> obstacleList;
};

#endif //RIDGELINERUSH_OBSTACLEPICKER_H
