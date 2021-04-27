#ifndef RIDGELINERUSH_POWERUP_H
#define RIDGELINERUSH_POWERUP_H

#include <iostream>

namespace PT { enum PowerupType {damage_boost, health_boost, jump_boost, speed_boost, none}; }

class Powerup {
  public:
    Powerup();
    PT::PowerupType getPowerupType();
    void setPowerupType(const std::string &s);
    std::string powerupToStr();
    PT::PowerupType strToPowerup(const std::string &s);
    void setPos(int x, int y);
    int getXPos();
    int getYPos();
    int getBuffer();
    void setBuffer(int p);

  private:
    PT::PowerupType pt;
    int xpos;
    int ypos;
    int buffer;
};
#endif // RIDEGLINERUSH_POWERUP_H
