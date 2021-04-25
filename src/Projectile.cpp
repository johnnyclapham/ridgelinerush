#include "Projectile.h"
#include <math.h>
#include "Tile.h"
#include "Terrain.h"
#include "Dragon.h"
#include "Hero.h"
#include <SFML/Graphics.hpp>

Projectile::Projectile() {
  damage = 1;
  angle = 0;
  speed = 1;
  x_coord = 0;
  y_coord = 0;
  projectileDirection = RIGHT;
}

Projectile::Projectile(float x, float y, float damage, float angle, float speed, Direction direction, float height) {
  this->damage = damage;
  this->angle = angle;
  this->speed = speed;
  this->height = height;
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

bool Projectile::handleCollision(Terrain *terrain) {
  // TODO check collision with any objects
  // check if there is a collision with the terrain
  std::vector<Column> columnList = terrain->columnList;
  std::vector<Obstacle> obstacleList = terrain->obstacleList;

  sf::Vector2f collisionPt = sf::Vector2f(x_coord, y_coord + (height / 2)); // area where the projectile will check for collision

  for (int i = 0; i < columnList.size(); i++) {
    // check tiles
    Tile check = columnList.at(i).getTiles().at(0);
    if (collisionPt.x > check.getX() && collisionPt.x < check.getX() + TILE_SIDE) {
      if (collisionPt.y > check.getY() && collisionPt.y < check.getY() + TILE_SIDE) {
        std::cout << "Projectile collision detected" << std::endl;
        return true;
      }
    }
  }
  if (obstacleList.size() != 0) {
    for (int i = 0; i < obstacleList.size(); i++) {
      // check tiles
      for (int j = 0; j < obstacleList.at(i).getTiles().size(); j++) {
        Tile check = obstacleList.at(i).getTiles().at(j);
        if (collisionPt.x > check.getX() && collisionPt.x < check.getX() + TILE_SIDE) {
          if (collisionPt.y > check.getY() && collisionPt.y < check.getY() + TILE_SIDE) {
            std::cout << "Projectile collision detected" << std::endl;
            return true;
          }
        }
      }
    }
  }
  
  // check if there is a collision with the dragon

  // check if there is a collision with the hero

  // return
  return false;
}
