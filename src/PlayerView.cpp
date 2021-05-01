//
// Created by Evelyn on 3/26/2021.
//.

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
    powerupDamageSprite = Sprite("assets/powerups/damage.png");
    powerupHealthSprite = Sprite("assets/powerups/health.png");
    powerupJumpSprite = Sprite("assets/powerups/jump.png");
    powerupSpeedSprite = Sprite("assets/powerups/speed.png");
    backgroundInit();
    updateView(.2);
}

void PlayerView::updateView(float time) {
    drawBackground();
    drawNewPowerups();
    drawTerrain();
    drawHero();
    drawDragon();
    drawProjectiles();
    reset += time;
    //drawNewPowerups();
    //drawPowerups(); //commented out until working correctly
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


void PlayerView::drawNewPowerups() {
  int z1,z2;
    //Hero hero = this->logic->getHero();
    Hero* hero = this->logic->getHeroPointer();
    if (reset > 2000) {
        srand(time(NULL));
        int x = rand() % 100;
        int y = (rand() % 4) + 1;
        if (x < 99) {
            sf::RectangleShape toDraw = sf::RectangleShape(sf::Vector2f(50, 50));
            if (y == 1) { toDraw.setFillColor(sf::Color::Green); }
            if (y == 2) { toDraw.setFillColor(sf::Color::Blue); }
            if (y == 3) { toDraw.setFillColor(sf::Color::Yellow); }
            if (y == 4) { toDraw.setFillColor(sf::Color::Red); }
            hero->setPowerupBuffer(y);
            z1 = (rand() % WINDOW_WIDTH/4) + WINDOW_WIDTH/2;
            z2 = (rand() % WINDOW_HEIGHT/2) + 1;
            // int z1 = 250;
            // int z2 = 250;
            // hero.setPowerupPos(z1, z2);
            hero->setPowerupPos(z1, z2);
            toDraw.setPosition(z1, z2);
            window->draw(toDraw);
        }
        reset = 0;

    }
    drawPowerups(hero->getXpos(),hero->getYpos());
    //  else {
    //    drawPowerups(z1,z2);
    // //   //get power up x and y coord
    // //
    // //   //draw the powerup
    //  }
    //std::cout << "reset: "<<reset<<"\n";
  }

void PlayerView::drawPowerups(int z1, int z2) {
    Hero hero = this->logic->getHero();
    // if (reset < 2000) {
    if (hero.getXpos() > 0 && hero.getYpos() > 0) {
        //sf::Vector2<float> position = hero.getPowerupPosition();
        sf::Vector2<float> position = sf::Vector2<float> (hero.getXpos(), hero.getYpos());
        sf::RectangleShape toDraw = sf::RectangleShape(sf::Vector2f(50, 50));
        int y = hero.getPowerupBuffer();
        if (y == 1) { //damage
          toDraw.setFillColor(sf::Color::Green);
          powerupDamageSprite.draw(position, window);
         }
        if (y == 2) { //health
          toDraw.setFillColor(sf::Color::Blue);
          powerupHealthSprite.draw(position, window);
         }
        if (y == 3) { //jump
          toDraw.setFillColor(sf::Color::Yellow);
          powerupJumpSprite.draw(position, window);
         }
        if (y == 4) { //speed
          toDraw.setFillColor(sf::Color::Red);
          powerupSpeedSprite.draw(position, window);
         }
        // std::cout << "powerupX: "<<z1;
        // std::cout << "powerupY: "<<z2<<"\n";
        // std::cout << "heroX: "<<hero.getXpos();
        // std::cout << "heroY: "<<hero.getYpos();

        //commented out as sprites are now used
        // toDraw.setPosition(z1, z2);
        // window->draw(toDraw);


        //dragonSprite.draw(position, window);
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
