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

    sf::RenderWindow *window;
    Logic *logic;

    //Members
    Sprite heroSprite;
    Sprite dragonSprite;
};

#endif //RIDGELINERUSH_PLAYERVIEW_H
