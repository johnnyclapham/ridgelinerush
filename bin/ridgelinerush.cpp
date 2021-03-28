#include <SFML/Graphics.hpp>
#include "screens.hpp"

// Ridge Line Rush code-base
// Team Members:
//              Johnny Clapham
//              Evelyn Showalter
//              John Svoboda
//              Moses Alexander

int main(int argc, char** argv)
{
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

  //done
	return 0;
}
