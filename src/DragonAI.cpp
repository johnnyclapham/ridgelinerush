#include "DragonAI.h"
#include "Dragon.h"
#include "Hero.h"
#include "math.h"
#include <SFML/Graphics.hpp>

DragonAI::DragonAI() {
  // don't use this
}

DragonAI::DragonAI(Dragon *dragon, Hero *hero) {
  this->dragon = dragon;
  this->hero = hero;
  attackTimer = sf::Clock(); // timer for the dragon's basic attacks
  specialTimer = sf::Clock(); // timer for when the dragon does a special attack
  pattern = NORMAL;
  normalMovementIteration = 0;
}

void DragonAI::update(float time) {
  float x = dragon->getPosition().x;
  float y = dragon->getPosition().y;

  if (y > 0) y = 0;

  switch (pattern) {
    case NORMAL:
      //100 cycles move up
      if (normalMovementIteration<=99) {
        //decrease y position of dragon
        dragon->setPosition(x, y-0.5*time);
        normalMovementIteration+=1;
      }

      //100 cycles move down
      else if (normalMovementIteration>=100 && normalMovementIteration<=199) {
        //increase y position of dragon
        dragon->setPosition(x, y+0.5*time);
        normalMovementIteration+=1;
      }

      //after 200 cycles reset ticker
      else if (normalMovementIteration>=200){
        normalMovementIteration=0;
      }

      dragon->setProjectileAngle(calculateAttackAngle());
      dragon->shoot();

      break;
  }
}

float DragonAI::calculateAttackAngle() {
  float heroX = hero->getPosition().x;
  float heroY = hero->getPosition().y;
  float dragonX = dragon->getPosition().x;
  float dragonY = dragon->getPosition().y;

  float x_diff = heroX - dragonX;
  float y_diff = heroY - dragonY;

  // slope boundaries
  if (heroX < dragonX) x_diff = 1; // to avoid division by 0
  if (heroY < dragonY) y_diff = 0;

  float slope = y_diff / x_diff;

  return slope / 100;
}