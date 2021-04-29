#include "DragonAI.h"
#include "Dragon.h"
#include "Hero.h"

DragonAI::DragonAI() {
  // don't use this
}

DragonAI::DragonAI(Dragon &dragon, Hero &hero) {
  this->dragon = dragon;
  this->hero = hero;
  attackTimer = sf::Clock(); // timer for the dragon's basic attacks
  specialTimer = sf::Clock(); // timer for when the dragon does a special attack
}

DragonAI::update(float time) {
  // TODO this
}