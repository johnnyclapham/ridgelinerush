#ifndef TITLESCREEN0_HPP_INCLUDED
#define TITLESCREEN0_HPP_INCLUDED

#include <iostream>
#include "cScreen.hpp"
#include "menu.h"
#include "background.h"

class title_screen_0 : public cScreen
{
public:
    title_screen_0 (void);
    virtual int Run (sf::RenderWindow &App);
    Background background;
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
    menuText.setCharacterSize(125);
    menuText.setFillColor(sf::Color::White);
    menuText.setStyle(sf::Text::Bold);
    menuText.setPosition(70,0);
    std::string menuString = "Ridgeline Rush";
    menuText.setString(menuString);
    background = Background();

    Menu menu(App.getSize().x, App.getSize().y);
    sf::Clock clock;
    int deltaMS;


		// our game loop
	  while(App.isOpen())
	  {
        deltaMS = clock.getElapsedTime().asMicroseconds();
        background.update(deltaMS*GAME_TIME_FACTOR);
        clock.restart();
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
                        menu.MoveUp(); //move selection up

                    } else if (Event.key.code == sf::Keyboard::Down){
                        menu.MoveDown(); //move selection down

                    } else if (Event.key.code == sf::Keyboard::Enter){
                        switch (menu.GetPressedItem())
                        //GetPressedItem calls the menu element array selectedItemIndex
                        // this tells us which item has been selected and which screen
                        // we must navigate to next
                            {
                            case 0:
                                std::cout << "\n\nPlay button has been pressed\n";
                                std::cout << "title_screen_0 -> game_screen_1\n";
                                return 1; //1 navigates to game_screen_1
                                break;
                            case 1:
                                std::cout << "\n\nOption button has been pressed ye\n";
                                std::cout << "title_screen_0 -> options_screen_2\n";
                                //TODO: navigate to option_screen_2
                                return 2;
                                break;
                            case 2:
                                std::cout << "\n\nInformation button has been pressed\n";
                                //TODO: navigate to information_screen_3 (if we want it)
                                break;
                            case 3:
                                std::cout << "\n\nGame close detected\n";
                                return -1; //-1 will close the game
                                break;
                            }
                        }
                    }

			}
            //clear, draw, and display our menu screen
			App.clear(sf::Color::Black);
            menu.draw(App, background);
            App.draw(menuText);
			App.display();
		}

    //exit (should not be needed)
    return (-1);
}

#endif // TITLESCREEN0_HPP_INCLUDED
