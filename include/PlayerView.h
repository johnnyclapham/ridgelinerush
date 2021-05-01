//
// Created by Evelyn on 3/25/2021.
//

#ifndef RIDGELINERUSH_PLAYERVIEW_H
#define RIDGELINERUSH_PLAYERVIEW_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Logic.h"
#include "Sprite.h"

class PlayerView {
public:
    // constructor //
    PlayerView(sf::RenderWindow *window, Logic *logic);

    // mutator //
    void updateView(float time); // this method will call all of the private methods in turn

private:
    void drawTerrain();
    void drawTile(Tile tile, sf::Color color);
    void drawHero();
    void drawDragon();
    void drawProjectiles();
    void drawPowerups(int z1, int z2);
    void drawNewPowerups();
    void drawBackground();
    void backgroundInit();


    sf::RenderWindow *window;
    Logic *logic;

    //Members
    Sprite heroSprite;
    Sprite dragonSprite;
    Sprite backGroundSprite;
    Sprite fireballSprite;
    Sprite powerupDamageSprite;
    Sprite powerupHealthSprite;
    Sprite powerupJumpSprite;
    Sprite powerupSpeedSprite;

    int reset;


    Sprite bgLayer1;
    Sprite bgLayer2;
    Sprite bgLayer3;
    Sprite bgLayer4;
    Sprite bgLayer5;
    Sprite bgLayer6;
};

#endif //RIDGELINERUSH_PLAYERVIEW_H
