//
// Created by John on 4/27/2021.
//

#include "Background.h"
#include <vector>
#include "Constants.h"
#include <math.h>

Background::Background() {
    layerWidths = {1356,1548,1508,1172,1140,100};
}

void Background::setSpriteWidths(std::vector<float> spriteWidths){
    layerWidths = spriteWidths;
}

float Background::getOffset(int layerIndex){
    return offsetList[layerIndex];
}

void Background::update(float time) {
    for(int i = 0; i < 6; i++){
        offsetList[i] = fmod(offsetList[i] - time*velocityList[i], layerWidths[i]);
    }
}

