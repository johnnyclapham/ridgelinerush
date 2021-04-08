//
// Created by Evelyn on 4/8/2021.
//

#ifndef CSCI437_OBSTACLEPICKER_H
#define CSCI437_OBSTACLEPICKER_H

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

#endif //CSCI437_OBSTACLEPICKER_H
