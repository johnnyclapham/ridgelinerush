#include "SFML/Graphics.hpp"
#include "Settings.h"


#ifndef RIDGELINERUSH_OPTIONS_H
#define RIDGELINERUSH_OPTIONS_H

#define MAX_NUMBER_OF_OPTIONS_ITEMS 9 //# of elem. on screen
//(we have 8 buttons)

class Options
{
public:
	Options(float screenWidth, float screenHeight);
	Options();

	void draw(sf::RenderWindow &window);
	void MoveUp(); //to move selection up
	void MoveDown(); //to mover selection down
    int GetPressedItem(); //function to get current selection

private:
	int selectedItemIndex;
	sf::Font font;
	//array of elements for the Options
	sf::Text options[MAX_NUMBER_OF_OPTIONS_ITEMS];

};

#endif // OPTIONS_H
