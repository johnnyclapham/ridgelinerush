#include <SFML/Graphics.hpp>
#include <iostream>
#include "Constants.h"
#include "Logic.h"
#include "PlayerView.h"
#include "screens.hpp"

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

  	//Application variables
  	std::vector<cScreen*> Screens;
  	int screen = 0;



  	//Screens preparations
  	title_screen_0 s0;
  	Screens.push_back(&s0);
  	game_screen_1 s1;
  	Screens.push_back(&s1);
    options_screen_2 s2;
  	Screens.push_back(&s2);
    results_screen_3 s3;
  	Screens.push_back(&s3);

  	//Main loop
  	while (screen >= 0)
  	{
      //update the screen with returned screen index
  		screen = Screens[screen]->Run(App);
      std::cout << screen << '\n';
  	}

    //done
  	return 0;
  }
