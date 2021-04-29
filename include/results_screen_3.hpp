#ifndef RESULTSSCREEN_HPP_INCLUDED
#define RESULTSSCREEN_HPP_INCLUDED

#include <iostream>
#include "cScreen.hpp"
#include "results.h"

class results_screen_3 : public cScreen
{
public:
    results_screen_3 (void);
    virtual int Run (sf::RenderWindow &App);
};

results_screen_3::results_screen_3 (void){}


//here is our main section previously living in ridgerunner.cpp
//filled with some dummy text for navigation demo

int results_screen_3::Run (sf::RenderWindow &App)
{



		//Initialize our font
	  sf::Font font;
	  if (!font.loadFromFile(GAME_FONT_PATH)){
    		printf("\ngame closed\n");}

    //create sfml text to display score to player
    sf::Text resultsText; //updated during re-rendering
    resultsText.setFont(font); // font is a sf::Font
    resultsText.setCharacterSize(125);
    resultsText.setFillColor(sf::Color::White);
    resultsText.setStyle(sf::Text::Bold);
    resultsText.setPosition(70,0);
    std::string resultsString = "Results";
    resultsText.setString(resultsString);

    Results results(App.getSize().x, App.getSize().y);


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

                  if (Event.key.code == sf::Keyboard::Up){
                    results.MoveUp(); //move selection up

                  } else if (Event.key.code == sf::Keyboard::Down){
                    results.MoveDown(); //move selection down

                  } else if (Event.key.code == sf::Keyboard::Enter){
                    switch (results.GetPressedItem())
                    //GetPressedItem calls the results element array selectedItemIndex
                    // this tells us which item has been selected and which screen
                    // we must navigate to next
                      {
                      case 0:
                        std::cout << "\n\nOption 1 pressed\n";
                        //TODO: Do domething on press
                        //implement an option
                        break;
                      case 1:
                        std::cout << "\n\nOption 2 pressed\n";
                        //TODO: Do domething on press
                        //implement an option
                        break;

                      case 2:
                        std::cout << "\n\nOption 3 pressed\n";
                        //TODO: Do domething on press
                        //implement an option
                        break;
                      case 3:
                        std::cout << "\n\nReturning to Main Menu\n";
                        std::cout << "title_screen_0 <- results_screen_3\n";
                        return 0; //0 goes to main menu
                        break;
                      }
                  }
								}


				//clear, draw, and display our results screen
				App.clear(sf::Color::Black);
        results.draw(App);
        App.draw(resultsText);
				App.display();

			}
		}

    //exit (should not be needed)
    return (-1);
}

#endif // RESULTSSCREEN_HPP_INCLUDED
