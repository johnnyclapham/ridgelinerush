#include "SoundPlayer.h"
#include <SFML/Audio.hpp>

SoundPlayer::SoundPlayer() {
  // Launcher sound
  launcher_buffer.loadFromFile("../assets/sounds/Weapon_fired.wav");
  launcher_sound = sf::Sound(launcher_buffer);
}

void SoundPlayer::launcher_play() {
  launcher_sound.play();
}