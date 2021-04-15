#include "Projectile.h"
#include <math.h>
#include <SFML/Graphics.hpp>

Projectile::Projectile() {
  damage = 1;
  angle = 0;
  speed = 1;
  x_coord = 0;
  y_coord = 0;
  projectileDirection = RIGHT;
}

Projectile::Projectile(float x, float y, float damage, float angle, float speed, Direction direction) {
  this->damage = damage;
  this->angle = angle;
  this->speed = speed;
  x_coord = x;
  y_coord = y;
  projectileDirection = direction;
}

sf::Vector2f Projectile::getPosition() {
  return sf::Vector2f(x_coord, y_coord);
}

void Projectile::move() {
  float x_diff = (speed * (1 - abs(angle)));
  if(projectileDirection == LEFT){
    x_diff *= -1;
  }
  float y_diff = speed * angle;
  x_coord = x_coord + x_diff;
  y_coord = y_coord + y_diff;
}

void Projectile::handleCollision() {
  // TODO check collision with any objects
}
