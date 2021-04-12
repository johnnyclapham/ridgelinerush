//
// Created by Evelyn on 3/24/2021.
//

#include "Tile.h"
#include <math.h>
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
    setPosition(x - fabs(x_diff), y + fabs(y_diff));
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

Collision Tile::intersectingPoint(sf::Vector2<float> prevPoint, sf::Vector2<float> newPoint){
    switch (shape){
        case UPPER_LEFT:
            if(newPoint.x >= x && newPoint.y >= y && (newPoint.x+newPoint.y) -(x+y) <= TILE_SIDE){
                return FLOOR;
            } else {
                return NO_COLLISION;
            }
            break;
        case LOWER_RIGHT:
            if (newPoint.x <= x+TILE_SIDE && newPoint.y <= y+TILE_SIDE && (newPoint.x+newPoint.y) -(x+y) >= TILE_SIDE){
                return FLOOR;
            } else {
                return NO_COLLISION;
            }
            break;
        case SQUARE:
            if (newPoint.x >= x && newPoint.y >= y && newPoint.x <= x+TILE_SIDE && newPoint.y <= y+TILE_SIDE){
                return FLOOR;
            } else {
                return NO_COLLISION;
            }
            break;
        default:
            return NO_COLLISION;
    }

}

float Tile::getShape() {
    return shape;
}
