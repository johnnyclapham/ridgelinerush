//
// Created by Evelyn on 3/24/2021.
//

#ifndef CSCI437_COLUMN_H
#define CSCI437_COLUMN_H

#include "Tile.h"
#include "Constants.h"
#include <vector>

class Column {
public:
    // constructor //
    Column();

    // mutators //
    void move(float x_diff, float y_diff);
//    setAtSpawnPoint(void);

    std::vector<Tile> getTiles();
private:
    // members //
    std::vector<Tile> tileList;
};

#endif //CSCI437_COLUMN_H
