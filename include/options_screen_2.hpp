#ifndef OPTIONSSCREEN_HPP_INCLUDED
#define OPTIONSSCREEN_HPP_INCLUDED

#include <iostream>
#include "cScreen.hpp"
#include "options.h"

class options_screen_2 : public cScreen
{
public:
    options_screen_2 (void);
    virtual int Run (sf::RenderWindow &App);
};

options_screen_2::options_screen_2 (void){}


//here is our main section previously living in ridgerunner.cpp
//filled with some dummy text for navigation demo

int options_screen_2::Run (sf::RenderWindow &App)
{



		//Initialize our font
	  sf::Font font;
	  if (!font.loadFromFile(GAME_FONT_PATH)){
    		printf("\ngame closed\n");}

    //create sfml text to display score to player
    sf::Text optionsText; //updated during re-rendering
    optionsText.setFont(font); // font is a sf::Font
    optionsText.setCharacterSize(125);
    optionsText.setFillColor(sf::Color::White);
    optionsText.setStyle(sf::Text::Bold);
    optionsText.setPosition(70,0);
    std::string optionsString = "Options";
    optionsText.setString(optionsString);
    Options options(App.getSize().x, App.getSize().y);
    Settings s = Settings(0);


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
                    options.MoveUp(); //move selection up

                  } else if (Event.key.code == sf::Keyboard::Down){
                    options.MoveDown(); //move selection down

                  } else { //Enter
                    switch (options.GetPressedItem())
                    //GetPressedItem calls the options element array selectedItemIndex
                    // this tells us which item has been selected and which screen
                    // we must navigate to next
                      {
                      case 0:
                        std::cout << "\n\nVolume modified.\n";
                        std::cout << s.keyToStr(Event.key.code) << std::endl;
                        // restrict volume input to between 0 and 9
                        if (Event.key.code > 25 && Event.key.code < 36) { s.setVolume(Event.key.code - 26); }
                        break;
                      case 1:
                        std::cout << "\n\nNew <jump> key set.\n";
                        std::cout << s.keyToStr(Event.key.code) << std::endl;
                        s.setMvmtUpKey(Event.key.code);
                        break;
                      case 2:
                        std::cout << "\n\nNew <move forward> key set.\n";
                        std::cout << s.keyToStr(Event.key.code) << std::endl;
                        s.setMvmtRightKey(Event.key.code);
                        break;
                      case 3:
                        std::cout << "\n\nNew <move backward> key set.\n";
                        std::cout << s.keyToStr(Event.key.code) << std::endl;
                        s.setMvmtLeftKey(Event.key.code);
                        break;
                      case 4:
                        std::cout << "\n\nNew <jump cancel> key set.\n";
                        std::cout << s.keyToStr(Event.key.code) << std::endl;
                        s.setMvmtDownKey(Event.key.code);
                        break;
                      case 5:
                        std::cout << "\n\nNew <attack> key set.\n";
                        std::cout << s.keyToStr(Event.key.code) << std::endl;
                        s.setAttackKey(Event.key.code);
                        break;
                      case 6:
                        std::cout << "\n\nNew <quit> key set.\n";
                        std::cout << s.keyToStr(Event.key.code) << std::endl;
                        s.setQuitKey(Event.key.code);
                        break;
                      case 7:
                        std::cout << "\n\nSettings restored to defaults.\n";
                        s.restoreToDefault();
                        break;
                      case 8:
                        std::cout << "\n\nReturning to Main Menu\n";
                        std::cout << "title_screen_0 <- options_screen_2\n";
                        return 0; //0 goes to main menu
                        break;
                      }
                  }
								}


				//clear, draw, and display our options screen
				App.clear(sf::Color::Black);
                options.draw(App);
                App.draw(optionsText);
				App.display();

			}
		}

    //exit (should not be needed)
    return (-1);
}

#endif // OPTIONSSCREEN_HPP_INCLUDED
