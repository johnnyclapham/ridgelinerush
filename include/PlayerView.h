//
// Created by Evelyn on 3/25/2021.
//

#ifndef CSCI437_PLAYERVIEW_H
#define CSCI437_PLAYERVIEW_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Logic.h"

class PlayerView {
public:
    // constructor //
    PlayerView(sf::RenderWindow *window, Logic *logic);

    // mutator //
    void updateView(); // this method will call all of the private methods in turn

private:
    void drawTerrain();

    sf::RenderWindow *window;
    Logic *logic;
};

#endif //CSCI437_PLAYERVIEW_H
