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
    backgroundInit();
    updateView(.2);
}

void PlayerView::updateView(float time) {
    drawBackground();
    drawTerrain();
    drawHero();
    drawDragon();
    drawProjectiles();
    reset += time;
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
    Background background = logic->getBackground();;
    sf::Vector2<float> position = sf::Vector2<float>(0,0);
    bgLayer6.draw(sf::Vector2<float>(background.getOffset(5),0), window);
    bgLayer5.draw(sf::Vector2<float>(background.getOffset(4),0), window);
    bgLayer4.draw(sf::Vector2<float>(background.getOffset(3),0), window);
    bgLayer3.draw(sf::Vector2<float>(background.getOffset(2),280), window);
    bgLayer2.draw(sf::Vector2<float>(background.getOffset(1),330), window);
    bgLayer1.draw(sf::Vector2<float>(background.getOffset(0),400), window);
}

void PlayerView::drawProjectiles() {
    Launcher launcher = this->logic->getLauncher();
    Dragon dragon = this->logic->getDragon();

    for (int i = 0; i < launcher.projectileList.size(); i++) {
        sf::Vector2f position = launcher.projectileList.at(i).getPosition();
        sf::RectangleShape toDraw = sf::RectangleShape(sf::Vector2f(20, launcher.projectileList.at(i).height));
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
        int x = rand() % 100;
        int y = (rand() % 4) + 1;
        if (x < 20) {
            sf::RectangleShape toDraw = sf::RectangleShape(sf::Vector2f(50, 50));
            if (y == 0) { toDraw.setFillColor(sf::Color::Green); }
            if (y == 1) { toDraw.setFillColor(sf::Color::Blue); }
            if (y == 2) { toDraw.setFillColor(sf::Color::Yellow); }
            if (y == 3) { toDraw.setFillColor(sf::Color::Red); }
            hero.setPowerupBuffer(y);
            int z1 = (rand() % WINDOW_WIDTH/2) + WINDOW_WIDTH/2;
            int z2 = (rand() % WINDOW_HEIGHT) + 1;
            hero.setPowerupPos(z1, z2);
            toDraw.setPosition(z1, z2);
            window->draw(toDraw);
        }
        //reset = 0;
    }
  }


void PlayerView::backgroundInit(){
    Background background = logic->getBackground();
    std::vector<float> spriteWidths;
    bgLayer1 = Sprite("assets/backgroundLayer1.png");
    bgLayer2 = Sprite("assets/backgroundLayer2.png");
    bgLayer3 = Sprite("assets/backgroundLayer3.png");
    bgLayer4 = Sprite("assets/backgroundLayer4.png");
    bgLayer5 = Sprite("assets/backgroundLayer5.png");
    bgLayer6 = Sprite("assets/backgroundLayer6.png");
    background.setSpriteWidths(spriteWidths);
}
