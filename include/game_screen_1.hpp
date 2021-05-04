#ifndef GAMESCREEN1_HPP_INCLUDED
#define GAMESCREEN1_HPP_INCLUDED

#include <fstream>
#include <iostream>
#include "cScreen.hpp"
#include "Settings.h"
#include <SFML/Audio.hpp>

void write_results(int x, int y, int z) {
    std::fstream file;
    file.open("../cfg/results.txt", std::ios::out);
    file << "RESULTS:\n" << std::endl;
    file << "score: " << x << std::endl;
    file << "remaining health: " << y << std::endl;
    file << "dragons killed: " << z << std::endl;
    file << std::endl;
    file.close();
}

class game_screen_1 : public cScreen
{
public:
    game_screen_1 (void);
    virtual int Run (sf::RenderWindow &App);
};

game_screen_1::game_screen_1 (void){}



int game_screen_1::Run (sf::RenderWindow &App)
{
  // initialize logic and views
  Logic *gameLogic = new Logic();
  PlayerView playerView = PlayerView(&App, gameLogic);
  Settings s = Settings(0);

  sf::Clock clock;
  int deltaMS;
  int score = 0;


  // start main loop
  while(App.isOpen())
  {
    // process events
    sf::Event Event;
    while(App.pollEvent(Event))
    {
      // Exit
      if(Event.type == sf::Event::Closed)
        App.close();

      //std::cout << s.keyToStr(s.getQuitKey()) << std::endl;
      if (Event.key.code == s.getQuitKey()){
        std::cout << "title_screen_0 <- game_screen_1\n";
        //return 0 calls the 0 position screen
        //0 position screen is title_screen_0
        return(0);

      }
    }

    deltaMS = clock.getElapsedTime().asMicroseconds();
    gameLogic->update(deltaMS*GAME_TIME_FACTOR);
    score += deltaMS;
    // if the hero is dead, go to the lose screen
    if (gameLogic->getHeroPointer()->healthDepleted()) {
      write_results(score/1000000, (gameLogic->getHero()).getHealth(), (gameLogic->getDragon()).getTimesKilled());
      return 3;
    }
    clock.restart();

    // clear screen and fill with blue
    App.clear(sf::Color::Blue);

    playerView.updateView(deltaMS*GAME_TIME_FACTOR);

    //if hero is off screen end the game
    Hero hero = gameLogic->getHero();
    sf::Vector2<float> position = sf::Vector2<float>(hero.getPosition().x, hero.getPosition().y);
    if(position.y>WINDOW_HEIGHT||position.x<=0){
      write_results(score/1000000, (gameLogic->getHero()).getHealth(), (gameLogic->getDragon()).getTimesKilled());
      return 3;
    }


    // display
    App.display();
    //sf::sleep(sf::milliseconds(50));
  }

    //exit (should not be needed)
    return (-1);
}

#endif // GAMESCREEN1_HPP_INCLUDED
