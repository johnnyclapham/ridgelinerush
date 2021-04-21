#include "Powerup.h"
#include <iostream>

Powerup::Powerup() {
    pt = PT::none;
    time = 0;
}

PT::PowerupType Powerup::getPowerupType() { return pt; }

void Powerup::setPowerupType(const std::string &s) {
    pt = strToPowerup(s);
    if (pt == PT::damage_boost || pt == PT::speed_boost || pt == PT::jump_boost) { time = 10; }
}

std::string Powerup::powerupToStr() {
    switch (pt) {
        case PT::damage_boost: return "damage boost";
        case PT::health_boost: return "health boost";
        case PT::jump_boost: return "jump boost";
        case PT::speed_boost: return "speed boost";
        default: return "no boost";
    }
}

PT::PowerupType Powerup::strToPowerup(const std::string &s) {
    if (s == "damage boost") { return PT::damage_boost; }
    if (s == "health boost") { return PT::health_boost; }
    if (s == "jump boost") { return PT::jump_boost; }
    if (s == "speed boost") { return PT::speed_boost; }
    return PT::none;
}
