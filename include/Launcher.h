#ifndef RIDGELINERUSH_LAUNCHER_H
#define RIDGELINERUSH_LAUNCHER_H

#include "Projectile.h"
#include "Dragon.h"
#include "Hero.h"
#include "Terrain.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Launcher {
  public:
    // constructor //
    Launcher();
    Launcher(float x, float y, float width, float height);

    void setPosition(float x, float y);
    void setDirection(Direction direction);
    void move(float x_diff, float y_diff);
    void updateHero(float time, Terrain *terrain, Dragon *dragon, Hero *hero);
    void shoot();
    void weaponSound();
    void dragonHit();

    // TODO: apply item effect

    std::vector<Projectile> projectileList;

  private:
    sf::SoundBuffer buffer;
    sf::Sound sound;
    std::string bufferPath;

    sf::SoundBuffer dragonHitBuffer;
    sf::Sound dragonHitSound;
    std::string dragonHitBufferPath;

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
