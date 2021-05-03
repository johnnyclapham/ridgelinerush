#ifndef RIDGELINERUSH_SETTINGS_H
#define RIDGELINERUSH_SETTINGS_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Settings {

  private:
    int volume;
    int difficulty;
    sf::Keyboard::Key mvmt_up;
    sf::Keyboard::Key mvmt_left;
    sf::Keyboard::Key mvmt_right;
    sf::Keyboard::Key mvmt_down;
    sf::Keyboard::Key attack;
    sf::Keyboard::Key quit;

  public:
    Settings();
    Settings(int x);
    void write();
    void read();
    void restoreToDefault();
    int getVolume();
    void setVolume(int v);
    int getDifficulty();
    void setDifficulty(int d);
    sf::Keyboard::Key getMvmtUpKey();
    sf::Keyboard::Key getMvmtLeftKey();
    sf::Keyboard::Key getMvmtRightKey();
    sf::Keyboard::Key getMvmtDownKey();
    sf::Keyboard::Key getAttackKey();
    sf::Keyboard::Key getQuitKey();
    void setMvmtUpKey(sf::Keyboard::Key k);
    void setMvmtLeftKey(sf::Keyboard::Key k);
    void setMvmtRightKey(sf::Keyboard::Key k);
    void setMvmtDownKey(sf::Keyboard::Key k);
    void setAttackKey(sf::Keyboard::Key k);
    void setQuitKey(sf::Keyboard::Key k);
    std::string keyToStr(sf::Keyboard::Key k);
    sf::Keyboard::Key strToKey(const std::string &s);
};
#endif
