#ifndef RIDGELINERUSH_PROJECTILE_H
#define RIDGELINERUSH_PROJECTILE_H

#include <SFML/Graphics.hpp>

class Projectile {
  public:
    // constructors //
    Projectile();
    Projectile(float x, float y, float damage, float angle, float speed);

    void move();
    sf::Vector2f getPosition();
    void handleCollision();

    float damage;

  private:
    float angle;
    float speed;
    float x_coord, y_coord;
};

#endif //RIDGELINERUSH_PROJECTILE_H