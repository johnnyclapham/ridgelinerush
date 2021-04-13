#ifndef RIDGELINERUSH_LAUNCHER_H
#define RIDGELINERUSH_LAUNCHER_H

#include "Projectile.h"
#include <SFML/Window.hpp>

class Launcher {
  public:
    // constructor //
    Launcher();
    Launcher(float x, float y);

    void setPosition(float x, float y);
    void move(float x_diff, float y_diff);
    Projectile *shoot();
    // TODO: apply item effect

  private:
    float x_coord, y_coord;
    float fire_delay;
    float damage;
    float speed;
    float angle = 0;

    void resetBaseValues();
};

#endif //RIDGELINERUSH_LAUNCHER_H