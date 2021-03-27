//
// Created by Evelyn on 3/25/2021.
//

#ifndef CSCI437_LOGIC_H
#define CSCI437_LOGIC_H

#include "Constants.h"
#include "Terrain.h"

// This defines the main logic class, which serves as a container for all other logic components
// and queries them as needed. The instance of this class will be a member of the respective views,
// so they can query for information to display.

// Pass instances of this class by reference only

class Logic {
public:
    // constructors //
    Logic();

    // inspectors //
    Terrain getTerrain();

private:
    // members //
    Terrain terrain;
};

#endif //CSCI437_LOGIC_H
