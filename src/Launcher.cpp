#include "Launcher.h"
#include "Projectile.h"
#include <iostream>

Launcher::Launcher() {
  setPosition(0, 0);
  resetBaseValues();
}

Launcher::Launcher(float x, float y) {
  setPosition(x, y);
  resetBaseValues();
  std::cout << "Launcher initialized, position is " << x_coord << " " << y_coord << std::endl;
}

void Launcher::setPosition(float x, float y) {
  x_coord = x;
  y_coord = y;
}

Projectile* Launcher::shoot() {
  Projectile *toReturn;
  *toReturn = Projectile(x_coord, y_coord, damage, angle, speed);
  return toReturn;
}

// reset everything except position
void Launcher::resetBaseValues() {
  angle = 0; // base angle
  speed = 1; // base speed constant
  damage = 1; // base damage
  fire_delay = 1; // base fire delay
}