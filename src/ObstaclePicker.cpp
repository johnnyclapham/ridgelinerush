//
// Created by Evelyn on 4/8/2021.
//

#include "ObstaclePicker.h"
#include <cstdlib>


// constructor. All new obstacles should be inputted here. //
ObstaclePicker::ObstaclePicker() {
    obstacleList.reserve(3);

    // basic triangle //
    Obstacle ob = Obstacle();
    ob.storeTile(Tile(ob.getX(), ob.getY(), UPPER_LEFT));
    obstacleList.push_back(ob);

    // three triangles //
    ob = Obstacle();
    ob.storeTile(Tile(ob.getX(), ob.getY(), UPPER_LEFT));
    ob.storeTile(Tile(ob.getX(), ob.getY() - TILE_SIDE, LOWER_RIGHT));
    ob.storeTile(Tile(ob.getX() + TILE_SIDE, ob.getY() - TILE_SIDE, UPPER_LEFT));
    obstacleList.push_back(ob);

    // basic platform //
    ob = Obstacle();
    ob.storeTile(Tile(ob.getX(), ob.getY() - (5 * TILE_SIDE), SQUARE));
    ob.storeTile(Tile(ob.getX() + TILE_SIDE, ob.getY() - (5 * TILE_SIDE), SQUARE));
    ob.storeTile(Tile(ob.getX() + (2 * TILE_SIDE), ob.getY() - (5 * TILE_SIDE), UPPER_LEFT));
    obstacleList.push_back(ob);
}

Obstacle ObstaclePicker::getRandomObstacle() {
    int index = rand() % obstacleList.size();
    return obstacleList.at(index);
}

Obstacle ObstaclePicker::getObstacleAt(int index) {
    return obstacleList.at(index);
}