//
// Created by Evelyn on 3/24/2021.
//

#ifndef RIDGELINERUSH_CONSTANTS_H
#define RIDGELINERUSH_CONSTANTS_H
#include <string>

// Used as a member of the Tile class to determine what shape it is. The first four values are triangles,
// indicating which corner the triangle is located in. The last option is for a square tile. These values
// are intended for terrain use for defining walkable areas
enum TileShape { UPPER_LEFT, LOWER_LEFT, UPPER_RIGHT, LOWER_RIGHT, SQUARE };

// Left slope is "/", right slope is "\"
enum Collision {NO_COLLISION, CEILING, WALL, FLOOR, LEFT_SLOPE, RIGHT_SLOPE};

enum EntityCollision {TERRAIN, HERO, DRAGON, NONE};

enum Direction {LEFT, RIGHT};

// Window width and window height - may not stay constants with resizble window
const int WINDOW_WIDTH = 900;
const int WINDOW_HEIGHT = 750;

// Width and height of hero
const int HERO_WIDTH = 56;
const int HERO_HEIGHT = 60;

// Length in pixels of one side of a square tile
const float TILE_SIDE = WINDOW_WIDTH / 12;

const int COLUMN_LENGTH = 10;

// Affects the speed of the game
const float GAME_TIME_FACTOR = .0003;

// Main font used in the game
const std::string GAME_FONT_PATH = "assets/8bitlim.ttf";


#endif //RIDGELINERUSH_CONSTANTS_H
