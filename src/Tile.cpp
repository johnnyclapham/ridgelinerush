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

sf::Vector2<float> Tile::getPosition() {
    return sf::Vector2<float>(x,y);
}

float Tile::getX() {
    return x;
}

float Tile::getY() {
    return y;
}

Collision Tile::intersectingPoint(sf::Vector2<float> prevPoint, sf::Vector2<float> newPoint){
    float slope = (newPoint.y - prevPoint.y)/(newPoint.x - prevPoint.x);
    float flatFloorXIntersect = (y-prevPoint.y)/slope + prevPoint.x;
    float flatCeilingXIntersect = (y+TILE_SIDE-prevPoint.y)/slope + prevPoint.x;
    float leftWallYIntersect = slope*(x-prevPoint.y) + prevPoint.x;
    float rightWallYIntersect = slope*(x+TILE_SIDE-prevPoint.x) + prevPoint.y;
    switch (shape){
        case UPPER_LEFT:
            if(newPoint.x < x || newPoint.y < y || (newPoint.x+newPoint.y) -(x+y) > TILE_SIDE){
                return NO_COLLISION;
            } else if (flatFloorXIntersect > x && flatFloorXIntersect< x+TILE_SIDE){
                //std::cout << "upper left floor" << std::endl;
                return FLOOR;
            } else if (prevPoint.y > y && prevPoint.x > x && prevPoint.y > slope*(prevPoint.x - x - TILE_SIDE) + y && prevPoint.y < slope*(prevPoint.x - x) + y + TILE_SIDE){
                //std::cout << "upper left ceiling" << std::endl;
                return CEILING;
            } else if (leftWallYIntersect > y && leftWallYIntersect < y+TILE_SIDE){
                //std::cout << "upper left wall" << std::endl;
                return WALL;
            }
            break;
        case LOWER_RIGHT:
            if (newPoint.x > x+TILE_SIDE || newPoint.y > y+TILE_SIDE || (newPoint.x+newPoint.y) -(x+y) < TILE_SIDE){
                //std::cout << "lower right nothing" << std::endl;
                return NO_COLLISION;
            } else if (prevPoint.y < y + TILE_SIDE  && prevPoint.x < x + TILE_SIDE && prevPoint.y < slope*(prevPoint.x - x) + y + TILE_SIDE && prevPoint.y > slope*(prevPoint.x - x - TILE_SIDE) + y){
                //std::cout << "lower right floor" << std::endl;
                return LEFT_SLOPE;
            } else if (flatCeilingXIntersect > x && flatCeilingXIntersect < x+TILE_SIDE){
                return CEILING;
            } else if (prevPoint.x > x + TILE_SIDE && prevPoint.y > slope*(prevPoint.x - x - TILE_SIDE) + y && prevPoint.y < slope*(prevPoint.x - x - TILE_SIDE) + y + TILE_SIDE){
                //std::cout << "lower right wall" << std::endl;
                return WALL;
            }
            break;
        case SQUARE:
            if (newPoint.x < x || newPoint.y < y || newPoint.x > x+TILE_SIDE || newPoint.y > y+TILE_SIDE){
                return NO_COLLISION;
            } else if (flatFloorXIntersect > x && flatFloorXIntersect< x+TILE_SIDE){
                //std::cout << "square floor" << std::endl;
                return FLOOR;
            } else if (flatCeilingXIntersect > x && flatCeilingXIntersect < x+TILE_SIDE){
                return CEILING;
            //left side of square
            } else if (leftWallYIntersect > y && leftWallYIntersect < y+TILE_SIDE){
                //std::cout << "square left wall" << std::endl;
                return WALL;
            //right side of square
            } else if (rightWallYIntersect > y && rightWallYIntersect < y+TILE_SIDE){
                //std::cout << "square right wall" << std::endl;
                return WALL;
            }
            break;
        default:
            return NO_COLLISION;
    }
    return NO_COLLISION;
}

float Tile::getShape() {
    return shape;
}
