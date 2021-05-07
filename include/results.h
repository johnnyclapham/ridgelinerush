#include "SFML/Graphics.hpp"


#ifndef RIDGELINERUSH_RESULTS_H
#define RIDGELINERUSH_RESULTS_H

#define MAX_NUMBER_OF_ITEMS 4 //# of elem. on screen
//(we have 4 buttons)
#include "Background.h"
#include "Sprite.h"

class Results
{
public:
	Results(float screenWidth, float screenHeight);
	Results();

	void draw(sf::RenderWindow &window, Background &background);
	void MoveUp(); //to move selection up
	void MoveDown(); //to mover selection down
	//function to get current selection
	// int GetPressedItem() { return selectedItemIndex; }
  int GetPressedItem();

private:
	int selectedItemIndex;
	sf::Font font;
	//array of elements for the results
	sf::Text results[MAX_NUMBER_OF_ITEMS];
	int normalCharSize;
	int largerCharSize;
	int topOffset;

	void drawBackground(sf::RenderWindow &window, Background &background);
	void backgroundInit();
	Sprite bgLayer1, bgLayer2, bgLayer3, bgLayer4, bgLayer5, bgLayer6;
	Background background;

};

#endif // RESULTS_H
