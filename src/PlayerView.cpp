//
// Created by Evelyn on 3/26/2021.
//

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "PlayerView.h"
#include "Terrain.h"
#include "Tile.h"
#include "Sprite.h"
#include "Constants.h"

PlayerView::PlayerView(sf::RenderWindow *window, Logic *logic) {
    this->logic = logic;
    this->window = window;
    heroSprite = Sprite("assets/hero.png");
    updateView(.2);
}

void PlayerView::updateView(float time) {
    drawTerrain();
    drawHero();


}

void PlayerView::drawTerrain() {
    Terrain terrain = logic->getTerrain();
    sf::Color fillColor;
    for (int k = 0; k < terrain.columnList.size(); k++) {
        Column column = terrain.columnList.at(k);
        if (k % 2 == 0) fillColor = sf::Color::White;
        else fillColor = sf::Color::Green;
        std::vector<Tile> tiles = column.getTiles();
        for (int i = 0; i < tiles.size(); i++) {
            Tile tile = tiles.at(i);
            drawTile(tile, fillColor);
        }
    }
    if (terrain.obstacleList.size() != 0) {
        for (int k = 0; k < terrain.obstacleList.size(); k++) {
            Obstacle obstacle = terrain.obstacleList.at(k);
            fillColor = sf::Color::Red;
            std::vector<Tile> tiles = obstacle.getTiles();
            for (int i = 0; i < tiles.size(); i++) {
                Tile tile = tiles.at(i);
                drawTile(tile, fillColor);
            }
        }
    }

}

void PlayerView::drawTile(Tile tile, sf::Color color) { // color to be removed - here for clarity of program for now
    sf::Vector2f tileSide = sf::Vector2f(TILE_SIDE, TILE_SIDE);
    if (tile.getShape() == LOWER_RIGHT) {
        sf::ConvexShape toDraw;
        toDraw.setPointCount(3);
        toDraw.setPoint(0, sf::Vector2f(tile.getX() + TILE_SIDE, tile.getY() + TILE_SIDE));
        toDraw.setPoint(1, sf::Vector2f(tile.getX(), tile.getY() + TILE_SIDE));
        toDraw.setPoint(2, sf::Vector2f(tile.getX() + TILE_SIDE, tile.getY()));
        toDraw.setFillColor(color);
        window->draw(toDraw);
    }
    else if (tile.getShape() == LOWER_LEFT) {
        sf::ConvexShape toDraw;
        toDraw.setPointCount(3);
        toDraw.setPoint(0, sf::Vector2f(tile.getX(), tile.getY()));
        toDraw.setPoint(1, sf::Vector2f(tile.getX(), tile.getY() + TILE_SIDE));
        toDraw.setPoint(2, sf::Vector2f(tile.getX() + TILE_SIDE, tile.getY() + TILE_SIDE));
        toDraw.setFillColor(color);
        window->draw(toDraw);
    }
    else if (tile.getShape() == UPPER_LEFT) {
        sf::ConvexShape toDraw;
        toDraw.setPointCount(3);
        toDraw.setPoint(0, sf::Vector2f(tile.getX(), tile.getY()));
        toDraw.setPoint(1, sf::Vector2f(tile.getX(), tile.getY() + TILE_SIDE));
        toDraw.setPoint(2, sf::Vector2f(tile.getX() + TILE_SIDE, tile.getY()));
        toDraw.setFillColor(color);
        window->draw(toDraw);
    }
    else if (tile.getShape() == UPPER_RIGHT) {
        sf::ConvexShape toDraw;
        toDraw.setPointCount(3);
        toDraw.setPoint(0, sf::Vector2f(tile.getX(), tile.getY()));
        toDraw.setPoint(1, sf::Vector2f(tile.getX() + TILE_SIDE, tile.getY() + TILE_SIDE));
        toDraw.setPoint(2, sf::Vector2f(tile.getX() + TILE_SIDE, tile.getY()));
        toDraw.setFillColor(color);
        window->draw(toDraw);
    }
    else {
        sf::RectangleShape toDraw = sf::RectangleShape(tileSide);
        toDraw.setFillColor(color);
        toDraw.setPosition(tile.getX(), tile.getY());
        window->draw(toDraw);
    }
}

void PlayerView::drawHero() {
    Hero hero = this->logic->getHero();
    sf::Vector2<float> position = hero.getPosition();
    heroSprite.draw(position, window);
}
