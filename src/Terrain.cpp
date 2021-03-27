//
// Created by Evelyn on 3/24/2021.
//

#include "Terrain.h"
#include "Column.h"
#include "Constants.h"

Terrain::Terrain() {
    setBaseMap();
    cycle = 0;
}

void Terrain::spawnColumn() {
    columnList.emplace_back();
}

void Terrain::despawnColumn() {
    columnList.erase(columnList.begin());
}

void Terrain::move(float x_diff, float y_diff) {
    for (int i = 0; i < 10; i++) {
        columnList.at(i).move(x_diff, y_diff);
    }
}

void Terrain::setBaseMap() {
//    Column column = Column();
//    column.move(4 * TILE_SIDE, 4 * TILE_SIDE);
//    columnList.push_back(column);
    for (int i = 9; i >= 0; i--) {
        Column column = Column();
        column.move(i * TILE_SIDE, i * TILE_SIDE);
        columnList.push_back(column);
    }
}
