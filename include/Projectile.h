#ifndef RIDGELINERUSH_PROJECTILE_H
#define RIDGELINERUSH_PROJECTILE_H

class Projectile {
  public:
    // constructors //
    Projectile(float x, float y, float damage, float angle, float speed);

    void move();
    void handleCollision();

    float damage;

  private:
    float angle;
    float speed;
    float x_coord, y_coord;
};

#endif //RIDGELINERUSH_PROJECTILE_H