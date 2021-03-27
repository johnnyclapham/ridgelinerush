//
// Created by Evelyn on 3/26/2021.
//

#include "Obstacle.h"
#include <vector>
#include "Tile.h"

Obstacle::Obstacle() {
    width = 1;
    height = 1;
    setAtSpawnPoint();
}

// The spawn point is constant - it is the top of the column generation. Any adjustments to tiles
// must take that in consideration by subtracting y values and adding x values.
void Obstacle::setAtSpawnPoint() {
    x = WINDOW_WIDTH + TILE_SIDE;
    y = 0;
}

void Obstacle::move(float x_diff, float y_diff) {
    if (!tileList.empty()) {
        for (int i = 0; i < tileList.size(); i++) {
            tileList.at(i).move(x_diff, y_diff);
        }
    }
}

int Obstacle::getHeight() {
    return height;
}
int Obstacle::getWidth() {
    return width;
}

float Obstacle::getY() {
    return y;
}

float Obstacle::getX() {
    return x;
}

void Obstacle::storeTile(Tile tile) {
    tileList.emplace_back(tile);
}

std::vector<Tile> Obstacle::getTiles() {
    return tileList;
}


