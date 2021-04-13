#ifndef TITLESCREEN0_HPP_INCLUDED
#define TITLESCREEN0_HPP_INCLUDED

#include <iostream>
#include "cScreen.hpp"

class title_screen_0 : public cScreen
{
public:
    title_screen_0 (void);
    virtual int Run (sf::RenderWindow &App);
};

title_screen_0::title_screen_0 (void){}





//here is our main section previously living in ridgerunner.cpp
//filled with some dummy text for navigation demo

int title_screen_0::Run (sf::RenderWindow &App)
{
		//Initialize our font
	  sf::Font font;
	  if (!font.loadFromFile("../assets/ACETONE.ttf")){
    		printf("\ngame closed\n");}


	  //create sfml text to display score to player
	  sf::Text menuText; //updated during re-rendering
	  menuText.setFont(font); // font is a sf::Font
	  menuText.setCharacterSize(36);
	  menuText.setColor(sf::Color::Green);
	  menuText.setStyle(sf::Text::Bold);
	  menuText.setPosition(50,0);
		std::string menuString = "Title Screen\n"
		                         "Press ENTER to start game";
		menuText.setString(menuString);




		// our game loop
	  while(App.isOpen())
	  {
	    //App.setFramerateLimit(60);

	    // process events
	    sf::Event Event;
	    while(App.pollEvent(Event)){

	              // Exit
	              if(Event.type == sf::Event::Closed){
	                App.close();
	                printf("\ngame closed\n");
	              }

	              // key pressed event
	              if (Event.type == sf::Event::KeyPressed)
	              {

									if (Event.key.code == sf::Keyboard::Return){
										std::cout << "title_screen_0 -> game_screen_1\n";
										//return 1 calls the 1 position screen
                    //1 position screen is game_screen_1
										return(1);

									}
								}


				//clear, draw, and display our dummy screen
				App.clear(sf::Color::Black);
				App.draw(menuText);
				App.display();

			}
		}

    //exit (should not be needed)
    return (-1);
}

#endif // TITLESCREEN0_HPP_INCLUDED
