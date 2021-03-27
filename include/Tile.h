//
// Created by Evelyn on 3/24/2021.
//

#ifndef RIDGELINERUSH_TILE_H
#define RIDGELINERUSH_TILE_H

#include "Constants.h"

class Tile {
public:
    // constructors //
    Tile();
    Tile(float x, float y, TileShape shape);

    // mutators //
    void move(float x_diff, float y_diff);
    void setPosition(float x, float y);

    // inspectors //
    float getX();
    float getY();
    float getShape();

private:
    // members //
    float x, y;
    TileShape shape;
};

#endif //RIDGELINERUSH_TILE_H
