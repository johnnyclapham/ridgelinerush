//
// Created by Johnny on 4/8/2021 using John's Hero.c as a template
//

#include "Dragon.h"
#include <math.h>
#include <iostream>


Dragon::Dragon() {
    setPosition(0, 0);
    //dragonMovementState = up; // not needed right now
    movementIteration = 0;
    height = 60;
    width = 56;
}

Dragon::Dragon(float x, float y) {
    setPosition(x, y);
}

void Dragon::update(float time){
    //100 cycles move up
    if (movementIteration<=99){
      //decrease y position of dragon
      setPosition(position.x, position.y-0.5*time);
      movementIteration+=1;

    //100 cycles move down
  } else if (movementIteration>=100 && movementIteration<=199) {
      //increase y position of dragon
      setPosition(position.x, position.y+0.5*time);
      movementIteration+=1;
    }
    //after 200 cycles reset ticker
    else if (movementIteration>=200){
      movementIteration=0;
    }
    //std::cout << "movement iteration: "<<movementIteration<<"\n";
}


void Dragon::setPosition(float x, float y) {
    position = sf::Vector2<float>(x,y);
}


sf::Vector2<float> Dragon::getPosition() {
    return position;
}
