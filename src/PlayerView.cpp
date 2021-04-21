//
// Created by Evelyn on 3/26/2021.
//

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include "PlayerView.h"
#include "Terrain.h"
#include "Tile.h"
#include "Sprite.h"
#include "Constants.h"
#include "Launcher.h"
#include "Projectile.h"

PlayerView::PlayerView(sf::RenderWindow *window, Logic *logic) {
    this->logic = logic;
    this->window = window;
    heroSprite = Sprite("assets/hero.png");
    dragonSprite = Sprite("assets/dragonArt.png");
    backGroundSprite = Sprite("assets/backgroundArt.png");
    fireballSprite = Sprite("assets/fireball.png");
    updateView(.2);
}

void PlayerView::updateView(float time) {
    drawBackground();
    drawTerrain();
    drawHero();
    drawDragon();
    drawProjectiles();
    reset += (time/GAME_TIME_FACTOR);
    drawPowerups();
}

void PlayerView::drawTerrain() {
    Terrain terrain = logic->getTerrain();
    sf::Color fillColor;
    for (int k = 0; k < terrain.columnList.size(); k++) {
        Column column = terrain.columnList.at(k);
        fillColor = sf::Color(156, 118, 92);
        std::vector<Tile> tiles = column.getTiles();
        for (int i = 0; i < tiles.size(); i++) {
            Tile tile = tiles.at(i);
            drawTile(tile, fillColor);
        }
    }
    if (terrain.obstacleList.size() != 0) {
        for (int k = 0; k < terrain.obstacleList.size(); k++) {
            Obstacle obstacle = terrain.obstacleList.at(k);
            fillColor = sf::Color(156, 118, 92);
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
    sf::Vector2<float> position = sf::Vector2<float>(hero.getPosition().x, hero.getPosition().y);

    heroSprite.setDirection(hero.getDirection());
    heroSprite.setWidth(HERO_WIDTH);
    heroSprite.draw(position, window);
}

//same as for our hero
void PlayerView::drawDragon() {
    Dragon dragon = this->logic->getDragon();
    sf::Vector2<float> position = dragon.getPosition();
    dragonSprite.draw(position, window);
}

//same as for our hero
void PlayerView::drawBackground() {
    sf::Vector2<float> position = sf::Vector2<float>(0,0);
    backGroundSprite.draw(position, window);
}

void PlayerView::drawProjectiles() {
    Launcher launcher = this->logic->getLauncher();
    Dragon dragon = this->logic->getDragon();

    for (int i = 0; i < launcher.projectileList.size(); i++) {
        sf::Vector2f position = launcher.projectileList.at(i).getPosition();
        sf::RectangleShape toDraw = sf::RectangleShape(sf::Vector2f(20, 10));
        toDraw.setFillColor(sf::Color::Yellow);
        toDraw.setPosition(position.x, position.y);
        window->draw(toDraw);
    }

    for (int i = 0; i < dragon.projectileList.size(); i++) {
        sf::Vector2f position = dragon.projectileList.at(i).getPosition();
        fireballSprite.draw(position, window);
    }
}

void PlayerView::drawPowerups() {
    Hero hero = this->logic->getHero();
    if (reset > 1000000) {
        srand(time(NULL));
        int x = 0; // rand() % 100
        int y = 0; // rand() % 5
        if (x < 5) {
            sf::RectangleShape toDraw = sf::RectangleShape(sf::Vector2f(10, 10));
            if (y == 0) { toDraw.setFillColor(sf::Color::Green); hero.setPowerupOnScreen(1); }
            if (y == 1) { toDraw.setFillColor(sf::Color::Blue); hero.setPowerupOnScreen(2); }
            if (y == 2) { toDraw.setFillColor(sf::Color::Yellow); hero.setPowerupOnScreen(3); }
            if (y == 3) { toDraw.setFillColor(sf::Color::Red); hero.setPowerupOnScreen(4); }
            int z1 = hero.getPosition().x;
            int z2 = hero.getPosition().y;
            toDraw.setPosition(z1 + 100, z2 + 100);
            window->draw(toDraw);
        }
        //reset = 0;
    }
}
