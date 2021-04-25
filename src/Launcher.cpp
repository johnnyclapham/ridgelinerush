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

void Launcher::update(float time, Terrain *terrain, Dragon *dragon, Hero *hero) {
  // move launcher based on hero's position
  sf::Vector2f heroPosition = hero->getPosition();
  setPosition(heroPosition.x, heroPosition.y + 20);
  setDirection(hero->getDirection());
  std::cout << hero->getDirection() << std::endl;

  int iter = 0;
  // iterate through projectiles for updates
  for (auto i = projectileList.begin(); i < projectileList.end(); i++) {
    projectileList.at(iter).move();
    if (projectileList.at(iter).handleCollision(terrain)) projectileList.erase(i);
    else if (projectileList.at(iter).getPosition().x < 0) {
      projectileList.erase(i);
    }
    iter++;
  }
}

void Launcher::setPosition(float x, float y) {
  x_coord = x;
  y_coord = y;
}

void Launcher::setDirection(Direction direction) {
    launcherDirection = direction;
}

void Launcher::shoot() {
  // add a projectile to the list
  if (timer.getElapsedTime().asMilliseconds() >= fire_delay) {
    projectileList.emplace_back(Projectile(x_coord, y_coord, damage, angle, speed, launcherDirection, 10));
    std::cout << "Projectile fired" << std::endl;
    timer.restart();
  }
}

// reset everything except position
void Launcher::resetBaseValues() {
  timer.restart();
  angle = 0; // base angle (between -1 and 1)
  speed = 4; // base speed constant
  damage = 1; // base damage
  fire_delay = 500; // base fire delay, in milliseconds
}
