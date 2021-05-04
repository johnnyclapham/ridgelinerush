#include "Launcher.h"
#include "Projectile.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

Launcher::Launcher() {
  timer = sf::Clock();
  setPosition(0, 0);
  resetBaseValues();
}

Launcher::Launcher(float x, float y, float width, float height) {
  setPosition(x, y);
  projectileWidth = width;
  projectileHeight = height;
  resetBaseValues();
  std::cout << "Launcher initialized, position is " << x_coord << " " << y_coord << std::endl;
}

void Launcher::updateHero(float time, Terrain *terrain, Dragon *dragon, Hero *hero) {
  // move launcher based on hero's position
  sf::Vector2f heroPosition = hero->getPosition();
  setPosition(heroPosition.x, heroPosition.y + 20);
  setDirection(hero->getDirection());

  int iter = 0;
  // iterate through projectiles for updates
  for (auto i = projectileList.begin(); i < projectileList.end(); i++) {
    projectileList.at(iter).move();
    EntityCollision collision = projectileList.at(iter).handleCollision(terrain, dragon->getHitbox());
    if (collision == DRAGON) {
      dragonHit();
      dragon->hit();
    }
    if (collision != NONE) {
      projectileList.erase(i);
    }
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
    projectileList.emplace_back(Projectile(x_coord, y_coord, damage, angle, speed, launcherDirection, projectileHeight, projectileWidth));
    std::cout << "Projectile fired" << std::endl;
    weaponSound();
    timer.restart();
  }
}

void Launcher::weaponSound() {
  std::string path = "assets/sounds/weapon_fired.wav";
  if (!buffer.loadFromFile(path)) {
      path = "../" + path;
  }
  buffer.loadFromFile(path);
  sound.setBuffer(buffer);
  sound.setVolume(10);
  sound.setPitch(3);
  sound.play();
}

void Launcher::dragonHit() {
  std::string path = "assets/sounds/dragon_hit.wav";
  if (!dragonHitBuffer.loadFromFile(path)) {
      path = "../" + path;
  }
  dragonHitBuffer.loadFromFile(path);
  dragonHitSound.setBuffer(dragonHitBuffer);
  dragonHitSound.setVolume(10);
  dragonHitSound.play();
}

// reset everything except position
void Launcher::resetBaseValues() {
  timer.restart();
  angle = 0; // base angle (between -1 and 1)
  speed = 4; // base speed constant
  damage = 1; // base damage
  fire_delay = 500; // base fire delay, in milliseconds
}
