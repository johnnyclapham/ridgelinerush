#include <SFML/Graphics.hpp>

#include <iostream>
#include "Constants.h"
#include "Logic.h"
#include "PlayerView.h"
#include "screens.hpp"

// Ridge Line Rush code-base
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

	//Application variables
	std::vector<cScreen*> Screens;
	int screen = 0;

	// create main window
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Ridgeline Rush");


	//Screens preparations
	title_screen_0 s0;
	Screens.push_back(&s0);
	game_screen_1 s1;
	Screens.push_back(&s1);

	//Main loop
	while (screen >= 0)
	{
		screen = Screens[screen]->Run(App);
	}
  
//   // TODO set up gameTimeFactor for adaptive frame rate
//     deltaMS = clock.getElapsedTime().asMicroseconds();
//     //std::cout << deltaMS*GAME_TIME_FACTOR << std::endl;
//     gameLogic->update(deltaMS*GAME_TIME_FACTOR);
//     clock.restart();

//     // clear screen and fill with blue
//     App.clear(sf::Color::Blue);

//     playerView.updateView(deltaMS*GAME_TIME_FACTOR);

//     // display
//     App.display();
//     //sf::sleep(sf::milliseconds(50));


  //done
	return 0;
}
