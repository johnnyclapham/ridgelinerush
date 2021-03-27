//
// Created by Evelyn on 3/24/2021.
//

#include "Tile.h"
#include "Column.h"
#include "Constants.h"
#include <vector>

Column::Column() {
    tileList.push_back(Tile(WINDOW_WIDTH + (TILE_SIDE), 0, LOWER_RIGHT));
    for (int i = 1; i < 10; i++) { // initialize all squares in tileList
        tileList.push_back(Tile(WINDOW_WIDTH + (TILE_SIDE), TILE_SIDE * i, SQUARE));
    }
}

void Column::move(float x_diff, float y_diff) {
    for (int i = 0; i < 10; i++) {
        tileList.at(i).move(x_diff, y_diff);
    }
}

std::vector<Tile> Column::getTiles() {
    return tileList;
}

