//
// Created by Evelyn on 3/24/2021.
//

#include "Tile.h"
#include "Column.h"
#include "Constants.h"
#include <vector>
#include <iostream>

Column::Column() {
    tileList.emplace_back(WINDOW_WIDTH + (TILE_SIDE), 0, LOWER_RIGHT);
    for (int i = 1; i < 10; i++) { // initialize all squares in tileList
        tileList.emplace_back(WINDOW_WIDTH + (TILE_SIDE), TILE_SIDE * i, SQUARE);
    }
}

void Column::move(float x_diff, float y_diff) {
    for (int i = 0; i < 10; i++) {
        tileList.at(i).move(x_diff, y_diff);
    }
}

// Takes an std::vector containing four coordinates of a quadrilateral and
// returns whether the quadrilateral intersects the column. Mainly used for
// The bounding box of the player.
Collision Column::intersecting(std::vector<sf::Vector2<float>> prevDiamond, std::vector<sf::Vector2<float>> newDiamond){
    // First we get the largest y and smallest/largest x/y to see if it intersects the column at all
    float columnTop = tileList[0].getY();
    float columnLeft = tileList[0].getX();
    float columnRight = columnLeft + TILE_SIDE;

    // We need to check to see if all 4 points on the quadrilateral intersect the trivial rectangle
    bool pointIntersects = false;
    for(int i = 0; i < newDiamond.size(); i++){
        if(newDiamond[i].y > columnTop && newDiamond[i].x > columnLeft && newDiamond[i].x < columnRight){
            pointIntersects = true;
        }
    }
    if(!pointIntersects){
        return NO_COLLISION;
    } else {
        bool intersectsTile = false;
        for(int i = 0; i < newDiamond.size(); i++){
            Collision collision = tileList[0].intersectingPoint(prevDiamond[i], newDiamond[i]);
            if(collision != NO_COLLISION){
                return collision;
            }
        }
        //std::cout << "Here" << std::endl;
    }
    return NO_COLLISION;
}

std::vector<Tile> Column::getTiles() {
    return tileList;
}

