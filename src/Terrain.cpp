//
// Created by Evelyn on 3/24/2021.
//

#include <iostream>
#include "Terrain.h"
#include "Column.h"
#include "Obstacle.h"
#include "Constants.h"
#include "ObstaclePicker.h"

Terrain::Terrain() {
    setBaseMap();
    picker = ObstaclePicker();
    cycle = 0;
}

void Terrain::spawnColumn() {
    columnList.emplace_back(Column());
    cycle += 1;
    if (cycle % 3 == 0) {
        cycle = 0;
        spawnObstacle();
    }

}

void Terrain::despawnColumn() {
    columnList.erase(columnList.begin());
}

void Terrain::spawnObstacle() {
    Obstacle ob = Obstacle();
    obstacleList.emplace_back(picker.getRandomObstacle());
}

void Terrain::despawnObstacle() {
    obstacleList.erase(obstacleList.begin());
}

void Terrain::move(float x_diff, float y_diff) {
    for (int i = 0; i < columnList.size(); i++) {
        columnList.at(i).move(x_diff, y_diff);
    }
    if (!obstacleList.empty()) {
        for (int i = 0; i < obstacleList.size(); i++) {
            obstacleList.at(i).move(x_diff, y_diff);
        }
        if (obstacleList.at(0).getY() + TILE_SIDE - obstacleList.at(0).getHeight() >= WINDOW_HEIGHT) {
            despawnObstacle();
        }
        else if (obstacleList.at(0).getX() + TILE_SIDE * obstacleList.at(0).getWidth() <= 0) {
            despawnObstacle();
        }
    }
    if (columnList.at(0).getTiles().at(0).getY() >= WINDOW_HEIGHT) {
        despawnColumn();
        spawnColumn();
    }

}

void Terrain::setBaseMap() {
    for (int i = 9; i >= 0; i--) {
        Column column = Column();
        column.move(i * TILE_SIDE, i * TILE_SIDE);
        columnList.push_back(column);
        if (i % 3 == 0) {
            obstacleList.push_back(picker.getRandomObstacle());
        }
    }
}
