#ifndef GAMESCREEN2_HPP_INCLUDED
#define GAMESCREEN2_HPP_INCLUDED

#include <iostream>
#include "cScreen.hpp"

class game_screen_2 : public cScreen
{
public:
    game_screen_2 (void);
    virtual int Run (sf::RenderWindow &App);
};

game_screen_2::game_screen_2 (void){}





//here is our main section previously living in ridgerunner.cpp
//filled with some dummy text for navigation demo

int game_screen_2::Run (sf::RenderWindow &App)
{
		//Initialize our font
	  sf::Font font;
	  if (!font.loadFromFile("../assets/ACETONE.ttf")){
    	printf("\ngame closed\n");}


	  //create sfml text to display score to player
	  sf::Text menuText; //updated during re-rendering
	  menuText.setFont(font); // font is a sf::Font
	  menuText.setCharacterSize(36);
	  menuText.setFillColor(sf::Color::Black);
	  menuText.setStyle(sf::Text::Bold);
	  menuText.setPosition(50,0);
		std::string menuString = "example_screen_n\n"
		"Press Escape to return to Game Screen";
		menuText.setString(menuString);





	  while(App.isOpen())
	  {
	    App.setFramerateLimit(60);

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

									if (Event.key.code == sf::Keyboard::Key::Enter){
										std::cout << "title_screen_0 <- example_screen_n\n";
                    //return 0 calls the 0 position screen
                    //0 position screen is title_screen_0
										return(0);

									}

                  else if (Event.key.code == sf::Keyboard::Key::Escape){
										std::cout << "game_screen_1  <- example_screen_n\n";
                    //return 0 calls the 0 position screen
                    //0 position screen is title_screen_0
										return(1);

									}
								}



				App.clear(sf::Color::Yellow); //clear screen for drawing
				App.draw(menuText);
				App.display();

			}
		}

    //exit (should not be needed)
    return (-1);
}

#endif // GAMESCREEN2_HPP_INCLUDED
