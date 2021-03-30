#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Settings.h"

using namespace std;

Settings::Settings() {
    volume = 100;
    difficulty = 1;
    screentype = ScreenSetting::Fullscreen;
    mvmt_up = sf::Keyboard::W;
    mvmt_left = sf::Keyboard::A;
    mvmt_down = sf::Keyboard::S;
    mvmt_right = sf::Keyboard::D;
    jump = sf::Keyboard::Space;
    attack = sf::Keyboard::X;
    pause = sf::Keyboard::P;
    write();
}

void Settings::write() {
    fstream file;
    file.open("./cfg/settings.txt", ios::out);
    file << "SETTINGS:\n" << endl;
    file << "volume: " << getVolume() << endl;
    file << "difficulty: " << getDifficulty() << endl;
    file << "screen type: " << getScreentype() << endl;
    file << "movement up: " << keyToStr(getMvmtUpKey()) << endl;
    file << "movement left: " << keyToStr(getMvmtLeftKey()) << endl;
    file << "movement down: " << keyToStr(getMvmtDownKey()) << endl;
    file << "movement right: " << keyToStr(getMvmtRightKey()) << endl;
    file << "jump: " << keyToStr(getJumpKey()) << endl;
    file << "attack: " << keyToStr(getAttackKey()) << endl;
    file << "pause: " << keyToStr(getPauseKey()) << endl;

    file << endl;
    file.close();
}

void Settings::read() {
    fstream file;
    file.open("./cfg/settings.txt", ios::in);
    if (file.is_open()) {
        string tmp;
        while (getline(file, tmp)) {
            if (tmp.compare(0, 8, "volume: ") == 0) { setVolume(stoi(tmp.substr(8))); }
            if (tmp.compare(0, 12, "difficulty: ") == 0) { setDifficulty(stoi(tmp.substr(12))); }
            if (tmp.compare(0, 13, "screen type: ") == 0) { setScreenType(strToScreentype(tmp.substr(13))); }
            if (tmp.compare(0, 13, "movement up: ") == 0) { string s = tmp.substr(13); setMvmtUpKey(strToKey(s)); }
            if (tmp.compare(0, 15, "movement left: ") == 0) { string s = tmp.substr(15); setMvmtLeftKey(strToKey(s)); }
            if (tmp.compare(0, 15, "movement down: ") == 0) { string s = tmp.substr(15); setMvmtDownKey(strToKey(s)); }
            if (tmp.compare(0, 16, "movement right: ") == 0) { string s = tmp.substr(16); setMvmtRightKey(strToKey(s)); }
            if (tmp.compare(0, 6, "jump: ") == 0) { string s = tmp.substr(6); setJumpKey(strToKey(s)); }
            if (tmp.compare(0, 8, "attack: ") == 0) { string s = tmp.substr(8); setAttackKey(strToKey(s)); }
            if (tmp.compare(0, 7, "pause: ") == 0) { string s = tmp.substr(7); setPauseKey(strToKey(s)); }
        }
        file.close();
    }
}

void Settings::restoreToDefault() {
    this->volume = 100;
    this->difficulty = 1;
    this->screentype = ScreenSetting::Fullscreen;
    this->mvmt_up = sf::Keyboard::W;
    this->mvmt_left = sf::Keyboard::A;
    this->mvmt_down = sf::Keyboard::S;
    this->mvmt_right = sf::Keyboard::D;
    this->jump = sf::Keyboard::Space;
    this->attack = sf::Keyboard::X;
    this->pause = sf::Keyboard::P;
    write();
}

int Settings::getVolume() { return this->volume; }

void Settings::setVolume(int v) { this->volume = v; write(); }

int Settings::getDifficulty() { return this->difficulty; }

void Settings::setDifficulty(int d) { this->difficulty = d; write(); }

string Settings::getScreentype() {
    switch (screentype) {
        case ScreenSetting::Fullscreen: return "Fullscreen";
        case ScreenSetting::Windowed: return "Windowed";
    }
}

ScreenSetting::ScreenType Settings::strToScreentype(const std::string &s) {
    if (s == "Fullscreen") {return ScreenSetting::Fullscreen; }
    if (s == "Windowed") {return ScreenSetting::Windowed; }
    return ScreenSetting::N; // empty screentype value for totality
}

void Settings::setScreenType(ScreenSetting::ScreenType st) { this->screentype = st; write(); }

sf::Keyboard::Key Settings::getMvmtUpKey() { return this->mvmt_up; }

sf::Keyboard::Key Settings::getMvmtLeftKey() { return this->mvmt_left; }

sf::Keyboard::Key Settings::getMvmtDownKey() { return this->mvmt_down; }

sf::Keyboard::Key Settings::getMvmtRightKey() { return this->mvmt_right; }

sf::Keyboard::Key Settings::getJumpKey() { return this->jump; }

sf::Keyboard::Key Settings::getAttackKey() { return this->attack; }

sf::Keyboard::Key Settings::getPauseKey() { return this->pause; }

void Settings::setMvmtUpKey(sf::Keyboard::Key k) { this->mvmt_up = k; write(); }

void Settings::setMvmtLeftKey(sf::Keyboard::Key k) { this->mvmt_left = k; write(); }

void Settings::setMvmtDownKey(sf::Keyboard::Key k) { this->mvmt_down = k; write(); }

void Settings::setMvmtRightKey(sf::Keyboard::Key k) { this->mvmt_right = k; write(); }

void Settings::setJumpKey(sf::Keyboard::Key k) { this->jump = k; write(); }

void Settings::setAttackKey(sf::Keyboard::Key k) { this->attack = k; write(); }

void Settings::setPauseKey(sf::Keyboard::Key k) { this->pause = k; write(); }

string Settings::keyToStr(sf::Keyboard::Key k) {
    switch(k) {
        case sf::Keyboard::A: return "A";
        case sf::Keyboard::B: return "B";
        case sf::Keyboard::C: return "C";
        case sf::Keyboard::D: return "D";
        case sf::Keyboard::E: return "E"; 
        case sf::Keyboard::F: return "F";
        case sf::Keyboard::G: return "G";
        case sf::Keyboard::H: return "H";
        case sf::Keyboard::I: return "I";
        case sf::Keyboard::J: return "J";
        case sf::Keyboard::K: return "K";
        case sf::Keyboard::L: return "L";
        case sf::Keyboard::M: return "M";
        case sf::Keyboard::N: return "N";
        case sf::Keyboard::O: return "O";
        case sf::Keyboard::P: return "P";
        case sf::Keyboard::Q: return "Q";
        case sf::Keyboard::R: return "R";
        case sf::Keyboard::S: return "S";
        case sf::Keyboard::T: return "T";
        case sf::Keyboard::U: return "U";
        case sf::Keyboard::V: return "V";
        case sf::Keyboard::W: return "W";
        case sf::Keyboard::X: return "X";
        case sf::Keyboard::Y: return "Y";
        case sf::Keyboard::Z: return "Z";
        case sf::Keyboard::Num0: return "Num0";
        case sf::Keyboard::Num1: return "Num1";
        case sf::Keyboard::Num2: return "Num2";
        case sf::Keyboard::Num3: return "Num3";
        case sf::Keyboard::Num4: return "Num4";
        case sf::Keyboard::Num5: return "Num5";
        case sf::Keyboard::Num6: return "Num6";
        case sf::Keyboard::Num7: return "Num7";
        case sf::Keyboard::Num8: return "Num8";
        case sf::Keyboard::Num9: return "Num9";
        case sf::Keyboard::Escape: return "Escape";
        case sf::Keyboard::LControl: return "LControl";
        case sf::Keyboard::LShift: return "LShift";
        case sf::Keyboard::LAlt: return "LAlt";
        case sf::Keyboard::LSystem: return "LSystem";
        case sf::Keyboard::RControl: return "RControl";
        case sf::Keyboard::RShift: return "RShift";
        case sf::Keyboard::RAlt: return "RAlt";
        case sf::Keyboard::RSystem: return "RSystem";
        case sf::Keyboard::Menu: return "Menu";
        case sf::Keyboard::LBracket: return "LBracket";
        case sf::Keyboard::RBracket: return "RBracket";
        case sf::Keyboard::SemiColon: return "Semicolon";
        case sf::Keyboard::Comma: return "Comma";
        case sf::Keyboard::Period: return "Period";
        case sf::Keyboard::Quote: return "Quote";
        case sf::Keyboard::Slash: return "Slash";
        case sf::Keyboard::BackSlash: return "Backslash";
        case sf::Keyboard::Tilde: return "Tilde";
        case sf::Keyboard::Equal: return "Equal";
        case sf::Keyboard::Dash: return "Dash";
        case sf::Keyboard::Space: return "Spacebar";
        case sf::Keyboard::Return: return "Enter key";
        case sf::Keyboard::BackSpace: return "Backspace";
        case sf::Keyboard::Tab: return "Tab";
        case sf::Keyboard::PageUp: return "PageUp";
        case sf::Keyboard::PageDown: return "PageDown";
        case sf::Keyboard::End: return "End";
        case sf::Keyboard::Home: return "Home";
        case sf::Keyboard::Insert: return "Insert";
        case sf::Keyboard::Delete: return "Delete";
        case sf::Keyboard::Add: return "Add";
        case sf::Keyboard::Subtract: return "Subtract";
        case sf::Keyboard::Multiply: return "Multiply";
        case sf::Keyboard::Divide: return "Divide";
        case sf::Keyboard::Left: return "Left";
        case sf::Keyboard::Right: return "Right";
        case sf::Keyboard::Up: return "Up";
        case sf::Keyboard::Down: return "Down";
        case sf::Keyboard::Numpad0: return "Numpad0";
        case sf::Keyboard::Numpad1: return "Numpad1";
        case sf::Keyboard::Numpad2: return "Numpad2";
        case sf::Keyboard::Numpad3: return "Numpad3";
        case sf::Keyboard::Numpad4: return "Numpad4";
        case sf::Keyboard::Numpad5: return "Numpad5";
        case sf::Keyboard::Numpad6: return "Numpad6";
        case sf::Keyboard::Numpad7: return "Numpad7";
        case sf::Keyboard::Numpad8: return "Numpad8";
        case sf::Keyboard::Numpad9: return "Numpad9";
        case sf::Keyboard::F1: return "F1";
        case sf::Keyboard::F2: return "F2";
        case sf::Keyboard::F3: return "F3";
        case sf::Keyboard::F4: return "F4";
        case sf::Keyboard::F5: return "F5";
        case sf::Keyboard::F6: return "F6";
        case sf::Keyboard::F7: return "F7";
        case sf::Keyboard::F8: return "F8";
        case sf::Keyboard::F9: return "F9";
        case sf::Keyboard::F10: return "F10";
        case sf::Keyboard::F11: return "F11";
        case sf::Keyboard::F12: return "F12";
        case sf::Keyboard::F13: return "F13";
        case sf::Keyboard::F14: return "F14";
        case sf::Keyboard::F15: return "F15";
        case sf::Keyboard::Pause: return "Pause";
        case sf::Keyboard::KeyCount: return "KeyCount";
    }
    return "Unknown key";
}

sf::Keyboard::Key Settings::strToKey(const string &s) {
    if (s == "A") { return sf::Keyboard::A; }
    if (s == "B") { return sf::Keyboard::B; }
    if (s == "C") { return sf::Keyboard::C; }
    if (s == "D") { return sf::Keyboard::D; }
    if (s == "E") { return sf::Keyboard::E; } 
    if (s == "F") { return sf::Keyboard::F; }
    if (s == "G") { return sf::Keyboard::G; }
    if (s == "H") { return sf::Keyboard::H; }
    if (s == "I") { return sf::Keyboard::I; }
    if (s == "J") { return sf::Keyboard::J; }
    if (s == "K") { return sf::Keyboard::K; }
    if (s == "L") { return sf::Keyboard::L; }
    if (s == "M") { return sf::Keyboard::M; }
    if (s == "N") { return sf::Keyboard::N; }
    if (s == "O") { return sf::Keyboard::O; }
    if (s == "P") { return sf::Keyboard::P; }
    if (s == "Q") { return sf::Keyboard::Q; }
    if (s == "R") { return sf::Keyboard::R; }
    if (s == "S") { return sf::Keyboard::S; }
    if (s == "T") { return sf::Keyboard::T; }
    if (s == "U") { return sf::Keyboard::U; }
    if (s == "V") { return sf::Keyboard::V; }
    if (s == "W") { return sf::Keyboard::W; }
    if (s == "X") { return sf::Keyboard::X; }
    if (s == "Y") { return sf::Keyboard::Y; }
    if (s == "Z") { return sf::Keyboard::Z; }
    if (s == "Num0") { return sf::Keyboard::Num0; }
    if (s == "Num1") { return sf::Keyboard::Num1; }
    if (s == "Num2") { return sf::Keyboard::Num2; }
    if (s == "Num3") { return sf::Keyboard::Num3; }
    if (s == "Num4") { return sf::Keyboard::Num4; }
    if (s == "Num5") { return sf::Keyboard::Num5; }
    if (s == "Num6") { return sf::Keyboard::Num6; }
    if (s == "Num7") { return sf::Keyboard::Num7; }
    if (s == "Num8") { return sf::Keyboard::Num8; }
    if (s == "Num9") { return sf::Keyboard::Num9; }
    if (s == "Escape") { return sf::Keyboard::Escape; }
    if (s == "LControl") { return sf::Keyboard::LControl; }
    if (s == "LShift") { return sf::Keyboard::LShift; }
    if (s == "LAlt") { return sf::Keyboard::LAlt; }
    if (s == "LSystem") { return sf::Keyboard::LSystem; }
    if (s == "RControl") { return sf::Keyboard::RControl; }
    if (s == "RShift") { return sf::Keyboard::RShift; }
    if (s == "RAlt") { return sf::Keyboard::RAlt; }
    if (s == "RSystem") { return sf::Keyboard::RSystem; }
    if (s == "Menu") { return sf::Keyboard::Menu; }
    if (s == "LBracket") { return sf::Keyboard::LBracket; }
    if (s == "RBracket") { return sf::Keyboard::RBracket; }
    if (s == "Semicolon") { return sf::Keyboard::SemiColon; }
    if (s == "Comma") { return sf::Keyboard::Comma; }
    if (s == "Period") { return sf::Keyboard::Period; }
    if (s == "Quote") { return sf::Keyboard::Quote; }
    if (s == "Slash") { return sf::Keyboard::Slash; }
    if (s == "Backslash") { return sf::Keyboard::BackSlash; }
    if (s == "Tilde") { return sf::Keyboard::Tilde; }
    if (s == "Equal") { return sf::Keyboard::Equal; }
    if (s == "Dash") { return sf::Keyboard::Dash; }
    if (s == "Spacebar") { return sf::Keyboard::Space; }
    if (s == "Enter key") { return sf::Keyboard::Return; }
    if (s == "Backspace") { return sf::Keyboard::BackSpace; }
    if (s == "Tab") { return sf::Keyboard::Tab; }
    if (s == "PageUp") { return sf::Keyboard::PageUp; }
    if (s == "PageDown") { return sf::Keyboard::PageDown; }
    if (s == "End") { return sf::Keyboard::End; }
    if (s == "Home") { return sf::Keyboard::Home; }
    if (s == "Insert") { return sf::Keyboard::Insert; }
    if (s == "Delete") { return sf::Keyboard::Delete; }
    if (s == "Add") { return sf::Keyboard::Add; }
    if (s == "Subtract") { return sf::Keyboard::Subtract; }
    if (s == "Multiply") { return sf::Keyboard::Multiply; }
    if (s == "Divide") { return sf::Keyboard::Divide; }
    if (s == "Left") { return sf::Keyboard::Left; }
    if (s == "Right") { return sf::Keyboard::Right; }
    if (s == "Up") { return sf::Keyboard::Up; }
    if (s == "Down") { return sf::Keyboard::Down; }
    if (s == "Numpad0") { return sf::Keyboard::Numpad0; }
    if (s == "Numpad1") { return sf::Keyboard::Numpad1; }
    if (s == "Numpad2") { return sf::Keyboard::Numpad2; }
    if (s == "Numpad3") { return sf::Keyboard::Numpad3; }
    if (s == "Numpad4") { return sf::Keyboard::Numpad4; }
    if (s == "Numpad5") { return sf::Keyboard::Numpad5; }
    if (s == "Numpad6") { return sf::Keyboard::Numpad6; }
    if (s == "Numpad7") { return sf::Keyboard::Numpad7; }
    if (s == "Numpad8") { return sf::Keyboard::Numpad8; }
    if (s == "Numpad9") { return sf::Keyboard::Numpad9; }
    if (s == "F1") { return sf::Keyboard::F1; }
    if (s == "F2") { return sf::Keyboard::F2; }
    if (s == "F3") { return sf::Keyboard::F3; }
    if (s == "F4") { return sf::Keyboard::F4; }
    if (s == "F5") { return sf::Keyboard::F5; }
    if (s == "F6") { return sf::Keyboard::F6; }
    if (s == "F7") { return sf::Keyboard::F7; }
    if (s == "F8") { return sf::Keyboard::F8; }
    if (s == "F9") { return sf::Keyboard::F9; }
    if (s == "F10") { return sf::Keyboard::F10; }
    if (s == "F11") { return sf::Keyboard::F11; }
    if (s == "F12") { return sf::Keyboard::F12; }
    if (s == "F13") { return sf::Keyboard::F13; }
    if (s == "F14") { return sf::Keyboard::F14; }
    if (s == "F15") { return sf::Keyboard::F15; }
    if (s == "Pause") { return sf::Keyboard::Pause; }
    if (s == "KeyCount") { return sf::Keyboard::KeyCount; }
    return sf::Keyboard::Unknown;
}
