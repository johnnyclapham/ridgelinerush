#ifndef RIDGELINERUSH_DRAGONAI_H
#define RIDGELINERUSH_DRAGONAI_H

#include "Dragon.h"
#include "Hero.h"

enum AttackPattern { NORMAL };

class DragonAI {
  public:
    DragonAI();
    DragonAI(Dragon *dragon, Hero *hero);

    void update(float time);

  private:
    // members //
    int normalMovementIteration;

    float calculateAttackAngle();

    AttackPattern pattern;
    Dragon *dragon;
    Hero *hero;
    sf::Clock attackTimer, specialTimer;
};

#endif //RIDGELINERUSH_DRAGONAI_H