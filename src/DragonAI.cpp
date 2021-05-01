#include "DragonAI.h"
#include "Dragon.h"
#include "Hero.h"
#include "math.h"
#include <cstdlib>
#include <SFML/Graphics.hpp>

DragonAI::DragonAI() {
  // don't use this
}

DragonAI::DragonAI(Dragon *dragon, Hero *hero) {
  this->dragon = dragon;
  this->hero = hero;
  attackTimer = sf::Clock(); // timer for the dragon's basic attacks
  specialTimer = sf::Clock();
  specialCounter = 3;
  pattern = NORMAL;
  normalMovementIteration = 0;
}

void DragonAI::update(float time) {
  float x = dragon->getPosition().x;
  float y = dragon->getPosition().y;

  switch (pattern) {
    case NORMAL:
      if (y > 200) y = 200;

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
        specialCounter--;
        if (!specialCounter) {
          switchPattern(selectPattern());
        }
      }

      dragon->setProjectileAngle(calculateAttackAngle());
      dragon->shoot();

      break;

    case BARRAGE:
      // rise to the top
      if (rise) { 
        dragon->setPosition(x, y-0.5*time); 
        if (dragon->getPosition().y <= 50) {
          specialTimer.restart();
          rise = false;
          hold = true;
          dragon->setDelay(200);
          dragon->setProjectileSpeed(8);
          dragon->setProjectileAngle(.35);
        }
      }
      // hold in place
      else if (hold) {
        if (specialTimer.getElapsedTime().asMilliseconds() >= 1000 * 3) {
          hold = false;
          fall = true;
          dragon->setDelay(500);
        }
      }
      // lower back down
      else if (fall) {
        dragon->setPosition(x, y+0.5*time);
        if (dragon->getPosition().y >= 200) {
          // return to normal pattern
          fall = false;
          switchPattern(NORMAL);
          resetSpecialCounter();
        }
      }
      
      if (!hold) dragon->setProjectileAngle(calculateAttackAngle());
      // attack
      dragon->shoot();

      break;

    default:
      break;
  }
}

void DragonAI::switchPattern(AttackPattern newPattern) {
  switch (newPattern) {
    case NORMAL:
      dragon->resetShootValues();
      std::cout << "Returning to normal attack pattern" << std::endl;
      break;
    case BARRAGE:
      rise = true;
      hold = false;
      fall = false;
      dragon->setDelay(500);
      dragon->setProjectileAngle(.5);
      std::cout << "Barrage activated" << std::endl;
      break;
  }

  pattern = newPattern;
}

void DragonAI::resetSpecialCounter() {
  specialCounter = (rand() % 3) + 2; // number between 2 and 4 cycles
}

AttackPattern DragonAI::selectPattern() {
  int pattern_options = 2; // INCREMENT THIS IF YOU ADD A NEW PATTERN
  int pick = rand() % (pattern_options - 1);

  switch (pick) {
    case 0:
      return BARRAGE;
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