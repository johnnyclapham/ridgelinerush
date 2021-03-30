#ifndef GAMESCREEN1_HPP_INCLUDED
#define GAMESCREEN1_HPP_INCLUDED

#include <iostream>
#include "cScreen.hpp"
#include "Constants.h"
#include "Logic.h"
#include "PlayerView.h"

class game_screen_1 : public cScreen
{
public:
    game_screen_1 (void);
    virtual int Run (sf::RenderWindow &App);
};

game_screen_1::game_screen_1 (void){}





//here is our main section previously living in ridgerunner.cpp
//filled with some dummy text for navigation demo

int game_screen_1::Run (sf::RenderWindow &App)
{
  // initialize logic and views
  Logic *gameLogic = new Logic();
  PlayerView playerView = PlayerView(&App, gameLogic);

  sf::Clock clock;
  int deltaMS;

  // start main loop
  while(App.isOpen())
  {
    // process events
    sf::Event Event;
    while(App.pollEvent(Event))
    {
      // Exit
      if(Event.type == sf::Event::Closed){
        App.close();
      }

        // key pressed event
        if (Event.type == sf::Event::KeyPressed)
        {

					if (Event.key.code == sf::Keyboard::Key::Escape){
						std::cout << "title_screen_0 <- game_screen_1\n";
            //return 0 calls the 0 position screen
            //0 position screen is title_screen_0
						return(0);

					}
				}
    }

    // TODO set up gameTimeFactor for adaptive frame rate
    deltaMS = clock.getElapsedTime().asMilliseconds();
    gameLogic->update(deltaMS);

    // clear screen and fill with blue
    App.clear(sf::Color::Blue);

    playerView.updateView();

    // display
    App.display();
  }

    //exit (should not be needed)
    return (-1);
}

#endif // GAMESCREEN1_HPP_INCLUDED
