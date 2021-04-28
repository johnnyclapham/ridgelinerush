//
// Created by John on 4/27/2021.
//

#ifndef RIDGELINERUSH_BACKGROUND_H
#define RIDGELINERUSH_BACKGROUND_H
#include <vector>

class Background {
public:
    // constructors //
    Background(); // basic constructor

    void update(float time);
    void setSpriteWidths(std::vector<float> spriteWidths);
    float getOffset(int layerIndex);

private:
    float offsetList [6] = {0,0,0,0,0,0};
    float velocityList [6] = {.95,.7,.5,.3,.2,0};
    std::vector<float> layerWidths;
};

#endif //RIDGELINERUSH_BACKGROUND_H
