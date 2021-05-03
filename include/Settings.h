#ifndef RIDGELINERUSH_SETTINGS_H
#define RIDGELINERUSH_SETTINGS_H

#include <iostream>
#include <SFML/Graphics.hpp>

namespace ScreenSetting { enum ScreenType{Fullscreen, Windowed, N}; }

class Settings {

  private:
    int volume;
    int difficulty;
    ScreenSetting::ScreenType screentype;
    sf::Keyboard::Key mvmt_up;
    sf::Keyboard::Key mvmt_left;
    sf::Keyboard::Key mvmt_right;
    sf::Keyboard::Key mvmt_down;
    sf::Keyboard::Key attack;
    sf::Keyboard::Key pause;

  public:
    Settings();
    void write();
    void read();
    void restoreToDefault();
    int getVolume();
    void setVolume(int v);
    int getDifficulty();
    void setDifficulty(int d);
    std::string getScreentype();
    ScreenSetting::ScreenType strToScreentype(const std::string &s);
    void setScreenType(ScreenSetting::ScreenType st);
    sf::Keyboard::Key getMvmtUpKey();
    sf::Keyboard::Key getMvmtLeftKey();
    sf::Keyboard::Key getMvmtRightKey();
    sf::Keyboard::Key getMvmtDownKey();
    sf::Keyboard::Key getAttackKey();
    sf::Keyboard::Key getPauseKey();
    void setMvmtUpKey(sf::Keyboard::Key k);
    void setMvmtLeftKey(sf::Keyboard::Key k);
    void setMvmtRightKey(sf::Keyboard::Key k);
    void setMvmtDownKey(sf::Keyboard::Key k);
    void setAttackKey(sf::Keyboard::Key k);
    void setPauseKey(sf::Keyboard::Key k);
    std::string keyToStr(sf::Keyboard::Key k);
    sf::Keyboard::Key strToKey(const std::string &s);
};
#endif
