#include "Projectile.h"

Projectile::Projectile(float x, float y, float damage, float angle, float speed) {
  this->damage = damage;
  this->angle = angle;
  this->speed = speed;
  x_coord = x;
  y_coord = y;
}

void Projectile::move() {
  // TODO change location based on angle and speed
}

void Projectile::handleCollision() {
  // TODO check collision with any objects
}
