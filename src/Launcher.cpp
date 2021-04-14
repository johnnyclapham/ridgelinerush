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

void Launcher::update(float time, Terrain terrain, Dragon *dragon, Hero *hero) {
  // move launcher based on hero's position
  sf::Vector2f heroPosition = hero->getPosition();
  setPosition(heroPosition.x, heroPosition.y + 20);

  // iterate through projectiles for updates
  for (int i = 0; i < projectileList.size(); i++) {
    projectileList.at(i).move();
    projectileList.at(i).handleCollision();
  }
}

void Launcher::setPosition(float x, float y) {
  x_coord = x;
  y_coord = y;
}

void Launcher::shoot() {
  // add a projectile to the list
  if (timer.getElapsedTime().asMilliseconds() >= fire_delay) {
    projectileList.emplace_back(Projectile(x_coord, y_coord, damage, angle, speed));
    std::cout << "Projectile fired" << std::endl;
    timer.restart();
  }
}

// reset everything except position
void Launcher::resetBaseValues() {
  timer.restart();
  angle = 0; // base angle (between -1 and 1)
  speed = 1; // base speed constant
  damage = 1; // base damage
  fire_delay = 500; // base fire delay, in milliseconds
}