#include "Launcher.h"
#include "Projectile.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Launcher::Launcher() {
  timer = sf::Clock();
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
  // Projectile *toReturn;
  // *toReturn = Projectile(x_coord, y_coord, damage, angle, speed);
  if (timer.getElapsedTime().asMilliseconds() >= fire_delay) {
    std::cout << "Projectile fired" << std::endl;
    timer.restart();
  }
  // return toReturn;
}

// reset everything except position
void Launcher::resetBaseValues() {
  timer.restart();
  angle = 0; // base angle
  speed = 1; // base speed constant
  damage = 1; // base damage
  fire_delay = 500; // base fire delay, in milliseconds
}