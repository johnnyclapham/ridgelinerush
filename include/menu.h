#include "SFML/Graphics.hpp"


#ifndef RIDGELINERUSH_MENU_H
#define RIDGELINERUSH_MENU_H

#define MAX_NUMBER_OF_ITEMS 4 //# of elem. on screen
//(we have 4 buttons)

class Menu
{
public:
	Menu(float screenWidth, float screenHeight);
	Menu();

	void draw(sf::RenderWindow &window);
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

};

#endif // MENU_H
