#ifndef RIDGELINERUSH_DRAGONAI_H
#define RIDGELINERUSH_DRAGONAI_H

#include "Dragon.h"
#include "Hero.h"

enum AttackPattern { NORMAL, BARRAGE, TRIPLE };

class DragonAI {
  public:
    DragonAI();
    DragonAI(Dragon *dragon, Hero *hero);

    void update(float time);

  private:
    // members //
    int normalMovementIteration;

    float calculateAttackAngle();
    void switchPattern(AttackPattern newPattern);
    void resetSpecialCounter();
    AttackPattern selectPattern();

    int specialCounter;

    AttackPattern pattern;
    Dragon *dragon;
    Hero *hero;
    sf::Clock attackTimer, specialTimer;
    bool rise, fall, hold;
};

#endif //RIDGELINERUSH_DRAGONAI_H