#ifndef RIDGELINERUSH_LAUNCHER_H
#define RIDGELINERUSH_LAUNCHER_H

#include "Projectile.h"
#include "Dragon.h"
#include "Hero.h"
#include "Terrain.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Launcher {
  public:
    // constructor //
    Launcher();
    Launcher(float x, float y, float width, float height);

    void setPosition(float x, float y);
    void setDirection(Direction direction);
    void move(float x_diff, float y_diff);
    void updateHero(float time, Terrain *terrain, Dragon *dragon, Hero *hero);
    void updateDragon(float time, Terrain *terrain, Dragon *dragon, Hero *hero);
    void shoot();
    // TODO: apply item effect

    std::vector<Projectile> projectileList;

  private:
    float projectileWidth;
    float projectileHeight;
    float x_coord, y_coord;
    float fire_delay;
    float damage;
    float speed;
    float angle = 0;
    Direction launcherDirection;
    sf::Clock timer;

    void resetBaseValues();
};

#endif //RIDGELINERUSH_LAUNCHER_H
