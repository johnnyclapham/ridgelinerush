//
// Created by Evelyn on 3/26/2021.
//

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "PlayerView.h"
#include "Terrain.h"
#include "Tile.h"
#include "Constants.h"

PlayerView::PlayerView(sf::RenderWindow *window, Logic *logic) {
    this->logic = logic;
    this->window = window;
    updateView();
}

void PlayerView::updateView() {
    drawTerrain();
}

void PlayerView::drawTerrain() {
    sf::Vector2f tileSide = sf::Vector2f(TILE_SIDE, TILE_SIDE);
    Terrain terrain = logic->getTerrain();
    sf::Color fillColor;
    for (int k = 0; k < terrain.columnList.size(); k++) {
        Column column = terrain.columnList.at(k);
        if (k % 2 == 0) fillColor = sf::Color::White;
        else fillColor = sf::Color::Green;
        std::vector<Tile> tiles = column.getTiles();
        for (int i = 0; i < tiles.size(); i++) {
            Tile tile = tiles.at(i);
            if (tile.getShape() == LOWER_RIGHT) {
                sf::ConvexShape toDraw;
                toDraw.setPointCount(3);
                toDraw.setPoint(0, sf::Vector2f(tile.getX() + TILE_SIDE, tile.getY() + TILE_SIDE));
                toDraw.setPoint(1, sf::Vector2f(tile.getX(), tile.getY() + TILE_SIDE));
                toDraw.setPoint(2, sf::Vector2f(tile.getX() + TILE_SIDE, tile.getY()));
                toDraw.setFillColor(fillColor);
                window->draw(toDraw);
            } else {
                sf::RectangleShape toDraw = sf::RectangleShape(tileSide);
                toDraw.setFillColor(fillColor);
                toDraw.setPosition(tile.getX(), tile.getY());
                window->draw(toDraw);
            }

        }
    }
}
