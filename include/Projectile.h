#ifndef RIDGELINERUSH_PROJECTILE_H
#define RIDGELINERUSH_PROJECTILE_H

#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Terrain.h"
#include "Hitbox.h"

class Projectile {
  public:
    // constructors //
    Projectile();
    Projectile(float x, float y, float damage, float angle, float speed, Direction direction, float height, float width);

    void move();
    sf::Vector2f getPosition();
    bool handleCollision(Terrain *terrain, Hitbox hitbox);

    float damage;
    float height;
    float width;

  private:
    float angle;
    float speed;
    float x_coord, y_coord;
    Direction projectileDirection;
};

#endif //RIDGELINERUSH_PROJECTILE_H
