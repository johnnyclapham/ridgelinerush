#ifndef RIDGELINERUSH_HITBOX_H
#define RIDGELINERUSH_HITBOX_H

class Hitbox {
  public:
    Hitbox();
    Hitbox(float x, float y, float width, float height);

    float x, y, width, height;
};

#endif //RIDGELINERUSH_HITBOX_H