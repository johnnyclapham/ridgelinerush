#ifndef RIDGELINERUSH_OPTIONS_H
#define RIDGELINERUSH_OPTIONS_H

#include "SFML/Graphics.hpp"
#include "Settings.h"
#include "Sprite.h"
#include "Background.h"


#define MAX_NUMBER_OF_OPTIONS_ITEMS 9 //# of elem. on screen
//(we have 9 buttons)

class Options
{
public:
	Options(float screenWidth, float screenHeight);
	Options();

	void draw(sf::RenderWindow &window, Background &background);
	void MoveUp(); //to move selection up
	void MoveDown(); //to mover selection down
    int GetPressedItem(); //function to get current selection

private:
	int selectedItemIndex;
	sf::Font font;
	//array of elements for the Options
	sf::Text options[MAX_NUMBER_OF_OPTIONS_ITEMS];

    void drawBackground(sf::RenderWindow &window, Background &background);
	void backgroundInit();

	Sprite bgLayer1, bgLayer2, bgLayer3, bgLayer4, bgLayer5, bgLayer6;
	Background background;

};

#endif // OPTIONS_H
