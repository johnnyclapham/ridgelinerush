#include "SFML/Graphics.hpp"


#ifndef RIDGELINERUSH_OPTIONS_H
#define RIDGELINERUSH_OPTIONS_H

#define MAX_NUMBER_OF_ITEMS 4 //# of elem. on screen
//(we have 4 buttons)

class Options
{
public:
	Options(float screenWidth, float screenHeight);
	Options();

	void draw(sf::RenderWindow &window);
	void MoveUp(); //to move selection up
	void MoveDown(); //to mover selection down
	//function to get current selection
	// int GetPressedItem() { return selectedItemIndex; }
  int GetPressedItem();

private:
	int selectedItemIndex;
	sf::Font font;
	//array of elements for the Options
	sf::Text options[MAX_NUMBER_OF_ITEMS];

};

#endif // OPTIONS_H
