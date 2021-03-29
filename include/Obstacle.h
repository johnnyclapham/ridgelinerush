//
// Created by Evelyn on 3/26/2021.
//

#ifndef CSCI437_OBSTACLE_H
#define CSCI437_OBSTACLE_H

#include "Tile.h"
#include <vector>

class Obstacle {
public:
    // constructors //
    Obstacle(); // basic constructor

    // modifiers //
    void move(float x_diff, float y_diff);
    void setAtSpawnPoint();

    int getHeight();
    int getWidth();
    float getY();
    float getX();
    Collision intersecting(std::vector<sf::Vector2<float>> prevDiamond, std::vector<sf::Vector2<float>> newDiamond);

    void storeTile(Tile tile);

    std::vector<Tile> getTiles();

private:
    float x = 0, y = 0;
    int width, height;
    std::vector<Tile> tileList;
};

#endif //CSCI437_OBSTACLE_H
