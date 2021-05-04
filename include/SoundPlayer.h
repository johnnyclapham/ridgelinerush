#ifndef RIDGELINERUSH_SOUNDPLAYER_H
#define RIDGELINERUSH_SOUNDPLAYER_H

#include <SFML/Audio.hpp>

class SoundPlayer {
  public:
    SoundPlayer();

    void launcher_play();

  private:
    sf::SoundBuffer launcher_buffer;
    sf::Sound launcher_sound;

    // sf::SoundBuffer fire_buffer;
    // sf::Sound fire_sound;
};

#endif //RIDGELINERUSH_SOUNDPLAYER_H