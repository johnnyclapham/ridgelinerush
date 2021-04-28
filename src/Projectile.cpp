#include "Projectile.h"
#include <math.h>
#include "Tile.h"
#include "Terrain.h"
#include "Dragon.h"
#include "Hero.h"
#include "Hitbox.h"
#include <SFML/Graphics.hpp>

Projectile::Projectile() {
  damage = 1;
  angle = 0;
  speed = 1;
  x_coord = 0;
  y_coord = 0;
  projectileDirection = RIGHT;
}

Projectile::Projectile(float x, float y, float damage, float angle, float speed, Direction direction, float height, float width) {
  this->damage = damage;
  this->angle = angle;
  this->speed = speed;
  this->height = height;
  this->width = width;
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

bool Projectile::handleCollision(Terrain *terrain, Hitbox hitbox) {
  // TODO check collision with any objects
  // check if there is a collision with the terrain
  std::vector<Column> columnList = terrain->columnList;
  std::vector<Obstacle> obstacleList = terrain->obstacleList;

  float x_point = x_coord;
  if (projectileDirection == RIGHT) x_point += width;
  sf::Vector2f currentPt = sf::Vector2f(x_point, y_coord + (height / 2)); // area where the projectile will check for collision
  float x_diff = (speed * (1 - abs(angle)));
  if(projectileDirection == LEFT){
    x_diff *= -1;
  }
  float y_diff = speed * angle;
  sf::Vector2f newPt = sf::Vector2f(currentPt.x + x_diff, currentPt.y + y_diff);

  for (int i = 0; i < columnList.size(); i++) {
    // check tiles
    Tile check = columnList.at(i).getTiles().at(0);
    Collision collision = check.intersectingPoint(currentPt, newPt);
    if (collision != NO_COLLISION) return true;
  }
  if (obstacleList.size() != 0) {
    for (int i = 0; i < obstacleList.size(); i++) {
      // check tiles
      for (int j = 0; j < obstacleList.at(i).getTiles().size(); j++) {
        Tile check = obstacleList.at(i).getTiles().at(j);
        Collision collision = check.intersectingPoint(currentPt, newPt);
        if (collision != NO_COLLISION) return true;
      }
    }
  }
  
  // check if there is a collision with the hitbox

  if (projectileDirection == LEFT) {
    // calculate from right side of hitbox
    if (hitbox.x + hitbox.width > currentPt.x && hitbox.x <= currentPt.x) {
      if (currentPt.y >= hitbox.y && currentPt.y < hitbox.y + hitbox.height) {
        std::cout << "Dragon hit" << std::endl;
        return true;
      }
    }
  }
  else if (projectileDirection == RIGHT) {
    // calculate from left side of hitbox
    if (hitbox.x <= currentPt.x && hitbox.x + hitbox.width > currentPt.x) {
      if (currentPt.y >= hitbox.y && currentPt.y < hitbox.y + hitbox.height) {
        std::cout << "Hero hit" << std::endl;
        return true;
      }
    }
  }

  // return
  return false;
}
