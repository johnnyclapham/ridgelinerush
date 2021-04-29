#include "options.h"
#include <iostream>
#include "Constants.h"

Options::Options(float screenWidth, float screenHeight)
{
	sf::String OptionsText;
	float OptionsTextWidth;

  sf::String fontPath = GAME_FONT_PATH;
  if(!font.loadFromFile(fontPath)){
     //error
     // new handling: if font fails to load, try alternate
     // addressing method (for Mac OS)
     std::cout << "failed to load font, trying alternate path \n";
     std::cout << "now loading   : ../ACETONE.ttf \n";
     font.loadFromFile("../"+fontPath);
  }

	options[0].setFont(font);
	options[0].setFillColor(sf::Color::Green);
	OptionsText = "Option 1";
	options[0].setString(OptionsText);
	options[0].setPosition(sf::Vector2f(screenWidth / 9, screenHeight / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	options[0].setCharacterSize(50+5);

	options[1].setFont(font);
	options[1].setFillColor(sf::Color::White);
	OptionsText = "Option 2";
	options[1].setString(OptionsText);
	options[1].setPosition(sf::Vector2f(screenWidth / 9, screenHeight / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	options[1].setCharacterSize(50);

	options[2].setFont(font);
	options[2].setFillColor(sf::Color::White);
	OptionsText = "Option 3";
	options[2].setString(OptionsText);
	options[2].setPosition(sf::Vector2f(screenWidth / 9, screenHeight / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	options[2].setCharacterSize(50);

	options[3].setFont(font);
	options[3].setFillColor(sf::Color::White);
	OptionsText = "Return to Menu";
	options[3].setString(OptionsText);
	options[3].setPosition(sf::Vector2f(screenWidth / 9, screenHeight / (MAX_NUMBER_OF_ITEMS + 1) * 4));
	options[3].setCharacterSize(50);


	selectedItemIndex = 0;
}


Options::Options()
{
}

void Options::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(options[i]);
	}
}

void Options::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		options[selectedItemIndex].setFillColor(sf::Color::White);
		options[selectedItemIndex].setCharacterSize(50);
		//decreasing our index
		selectedItemIndex--;
		options[selectedItemIndex].setFillColor(sf::Color::Green);
		options[selectedItemIndex].setCharacterSize(50+5);
	}
}

void Options::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		options[selectedItemIndex].setFillColor(sf::Color::White);
		options[selectedItemIndex].setCharacterSize(50);
		selectedItemIndex++;
		options[selectedItemIndex].setFillColor(sf::Color::Green);
		options[selectedItemIndex].setCharacterSize(50+5);
	}
}

int Options::GetPressedItem(){
	return selectedItemIndex;
	//feeds the array index to our switch statement in title_screen_0

}
