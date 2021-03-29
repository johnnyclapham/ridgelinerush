//
// Created by Evelyn on 3/24/2021.
//

#ifndef RIDGELINERUSH_CONSTANTS_H
#define RIDGELINERUSH_CONSTANTS_H

// Used as a member of the Tile class to determine what shape it is. The first four values are triangles,
// indicating which corner the triangle is located in. The last option is for a square tile. These values
// are intended for terrain use for defining walkable areas
enum TileShape { UPPER_LEFT, LOWER_LEFT, UPPER_RIGHT, LOWER_RIGHT, SQUARE };

enum Collision {NO_COLLISION, CEILING, WALL, FLOOR};

// Window width and window height - may not stay constants with resizble window
const int WINDOW_WIDTH = 900;
const int WINDOW_HEIGHT = 750;

// Length in pixels of one side of a square tile
const float TILE_SIDE = WINDOW_WIDTH / 12;

const int COLUMN_LENGTH = 10;

// Affects the speed of the game
const float GAME_TIME_FACTOR = .0002;


#endif //RIDGELINERUSH_CONSTANTS_H
