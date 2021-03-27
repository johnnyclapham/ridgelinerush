#include <SFML/Graphics.hpp>
#include <iostream>
#include "Constants.h"
#include "Logic.h"
#include "PlayerView.h"

// Ridge Line Rush code-base
// basic window template in SFML
// Team Members:
//              Johnny Clapham
//              Evelyn Showalter
//              John Svoboda
//              Moses Alexander

int main(int argc, char** argv)
{
  // create main window
  sf::RenderWindow App(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32), "Ridgeline Rush");

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
      if(Event.type == sf::Event::Closed)
        App.close();
    }

    deltaMS = clock.getElapsedTime().asMilliseconds();
    gameLogic->update(deltaMS);

    // clear screen and fill with blue
    App.clear(sf::Color::Blue);

    playerView.updateView();

    // display
    App.display();
  }

  // Done.
  return 0;
}
