#include "SFML/Graphics.hpp"


#ifndef RIDGELINERUSH_MENU_H
#define RIDGELINERUSH_MENU_H

#define MAX_NUMBER_OF_ITEMS 4 //# of elem. on screen
//(we have 4 buttons)
#include "background.h"
#include "Sprite.h"

class Menu
{
public:
	Menu(float screenWidth, float screenHeight);
	Menu();

	void draw(sf::RenderWindow &window, Background &background);
	void MoveUp(); //to move selection up
	void MoveDown(); //to mover selection down
	//function to get current selection
	// int GetPressedItem() { return selectedItemIndex; }
  int GetPressedItem();

private:
	int selectedItemIndex;
	sf::Font font;
	//array of elements for the menu
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

    void drawBackground(sf::RenderWindow &window, Background &background);
	void backgroundInit();
    Sprite bgLayer1, bgLayer2, bgLayer3, bgLayer4, bgLayer5, bgLayer6;
    Background background;

};

#endif // MENU_H
