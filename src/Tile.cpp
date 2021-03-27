//
// Created by Evelyn on 3/24/2021.
//

#include "Tile.h"
#include <cstdlib>
#include <iostream>

Tile::Tile() {
    setPosition(0, 0);
    shape = SQUARE;
}

Tile::Tile(float x, float y, TileShape shape) {
    setPosition(x, y);
    this->shape = shape;
}

void Tile::move(float x_diff, float y_diff) {
    setPosition(x - abs(x_diff), y + abs(y_diff));
}

void Tile::setPosition(float x, float y) {
    this->x = x;
    this->y = y;
}

float Tile::getX() {
    return x;
}

float Tile::getY() {
    return y;
}

float Tile::getShape() {
    return shape;
}