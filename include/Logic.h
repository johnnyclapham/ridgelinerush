//
// Created by Evelyn on 3/25/2021.
//

#ifndef RIDGELINERUSH_LOGIC_H
#define RIDGELINERUSH_LOGIC_H

#include "Constants.h"
#include "Terrain.h"
#include "Launcher.h"
#include "Hero.h"
#include "Dragon.h"
#include "Controller.h"

// This defines the main logic class, which serves as a container for all other logic components
// and queries them as needed. The instance of this class will be a member of the respective views,
// so they can query for information to display.

// Pass instances of this class by reference only

class Logic {
public:
    // constructors //
    Logic();

    void update(float time); // main update method. will call all other updaters

    // inspectors //
    Terrain getTerrain();
    Hero getHero();
    Dragon getDragon();
    // Launcher getLauncher();

private:
    // update methods //
    void updateTerrain();

    // members //
    Terrain terrain;
    Hero hero;
    Launcher launcher;
    Dragon dragon;
    Controller controller;
};

#endif //RIDGELINERUSH_LOGIC_H
