#ifndef RIDGELINERUSH_LAUNCHER_H
#define RIDGELINERUSH_LAUNCHER_H

#include "Projectile.h"

class Launcher {
  public:
    // constructor //
    Launcher();

    void setPosition(float x, float y);
    void move(float x_diff, float y_diff);
    Projectile shoot();
    // TODO: apply item effect
    void resetBaseValues();

  private:
    float x_coord, y_coord;
    float fire_delay;
    float damage;
    float speed;
    float angle = 0;
}

#endif //RIDGELINERUSH_LAUNCHER_H