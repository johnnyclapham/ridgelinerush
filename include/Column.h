//
// Created by Evelyn on 3/24/2021.
//

#ifndef RIDGELINERUSH_COLUMN_H
#define RIDGELINERUSH_COLUMN_H

#include "Tile.h"
#include "Constants.h"
#include <SFML/Window.hpp>
#include <vector>

class Column {
public:
    // constructor //
    Column();

    // mutators //
    void move(float x_diff, float y_diff);
//    setAtSpawnPoint(void);

    Collision intersecting(std::vector<sf::Vector2<float>> prevDiamond, std::vector<sf::Vector2<float>> newDiamond);

    std::vector<Tile> getTiles();
private:
    // members //
    std::vector<Tile> tileList;
};

#endif //RIDGELINERUSH_COLUMN_H
