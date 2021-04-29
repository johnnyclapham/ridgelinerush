#include "results.h"
#include <iostream>
#include "Constants.h"
#include <string>


Results::Results(float screenWidth, float screenHeight)
{
	sf::String ResultsText;
	float ResultsTextWidth;

  normalCharSize = 55;
  largerCharSize = 60;
  topOffset = 230;
  sf::String fontPath = GAME_FONT_PATH;
  if(!font.loadFromFile(fontPath)){
     //error
     // new handling: if font fails to load, try alternate
     // addressing method (for Mac OS)
     std::cout << "failed to load font, trying alternate path \n";
     std::cout << "now loading   : ../ACETONE.ttf \n";
     font.loadFromFile("../"+fontPath);
  }

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//TODO: fetch hero attributes here and display
	std::string result0 = std::to_string(1);
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	results[0].setFont(font);
	results[0].setFillColor(sf::Color(240,204,136));
	ResultsText = result0+" dragons killed ";
	results[0].setString(ResultsText);
  results[0].setCharacterSize(largerCharSize);
	results[0].setPosition(sf::Vector2f(screenWidth / 2 - results[0].getLocalBounds().width/2, topOffset + (screenHeight-topOffset) / (MAX_NUMBER_OF_ITEMS + 1) * 1 ));

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//TODO: fetch hero attributes here and display
	std::string result1 = std::to_string(96);
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	results[1].setFont(font);
	results[1].setFillColor(sf::Color::White);
	ResultsText = result1+" health remaining ";
	results[1].setString(ResultsText);
  results[1].setCharacterSize(normalCharSize);
	results[1].setPosition(sf::Vector2f(screenWidth / 2 - results[1].getLocalBounds().width/2, topOffset + (screenHeight-topOffset) / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//TODO: fetch hero attributes here and display
	std::string result2 = std::to_string(10);
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	results[2].setFont(font);
	results[2].setFillColor(sf::Color::White);
	ResultsText = result2+" points collected ";
	results[2].setString(ResultsText);
  results[2].setCharacterSize(normalCharSize);
	results[2].setPosition(sf::Vector2f(screenWidth / 2 - results[2].getLocalBounds().width/2, topOffset + (screenHeight-topOffset) / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	results[3].setFont(font);
	results[3].setFillColor(sf::Color::White);
	ResultsText = "Return to Main Menu";
	results[3].setString(ResultsText);
    results[3].setCharacterSize(normalCharSize);
	results[3].setPosition(sf::Vector2f(screenWidth / 2 - results[3].getLocalBounds().width/2, topOffset + (screenHeight-topOffset) / (MAX_NUMBER_OF_ITEMS + 1) * 4));


	selectedItemIndex = 0;
	backgroundInit();
}


Results::Results()
{
}

void Results::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(results[i]);
	}
}

void Results::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		results[selectedItemIndex].setFillColor(sf::Color::White);
		results[selectedItemIndex].setCharacterSize(normalCharSize);
		results[selectedItemIndex].setPosition(sf::Vector2f(WINDOW_WIDTH / 2 - results[selectedItemIndex].getLocalBounds().width/2, topOffset + (WINDOW_HEIGHT-topOffset) / (MAX_NUMBER_OF_ITEMS + 1) * (selectedItemIndex+1)));
		//decreasing our index
		selectedItemIndex--;
        results[selectedItemIndex].setCharacterSize(largerCharSize);
		results[selectedItemIndex].setFillColor(sf::Color(240,204,136));
		results[selectedItemIndex].setPosition(sf::Vector2f(WINDOW_WIDTH / 2 - results[selectedItemIndex].getLocalBounds().width/2, topOffset + (WINDOW_HEIGHT-topOffset) / (MAX_NUMBER_OF_ITEMS + 1) * (selectedItemIndex+1)));
	}
}

void Results::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		results[selectedItemIndex].setFillColor(sf::Color::White);
		results[selectedItemIndex].setCharacterSize(normalCharSize);
		results[selectedItemIndex].setPosition(sf::Vector2f(WINDOW_WIDTH / 2 - results[selectedItemIndex].getLocalBounds().width/2, topOffset + (WINDOW_HEIGHT-topOffset) / (MAX_NUMBER_OF_ITEMS + 1) * (selectedItemIndex+1)));
		selectedItemIndex++;
		results[selectedItemIndex].setFillColor(sf::Color(240,204,136));
		results[selectedItemIndex].setCharacterSize(largerCharSize);
		results[selectedItemIndex].setPosition(sf::Vector2f(WINDOW_WIDTH / 2 - results[selectedItemIndex].getLocalBounds().width/2, topOffset + (WINDOW_HEIGHT-topOffset) / (MAX_NUMBER_OF_ITEMS + 1) * (selectedItemIndex+1)));
	}
}

int Results::GetPressedItem(){
	return selectedItemIndex;
	//feeds the array index to our switch statement in title_screen_0

}

void Results::backgroundInit(){
    std::vector<float> spriteWidths;
    bgLayer1 = Sprite("assets/backgroundLayer1.png");
    bgLayer2 = Sprite("assets/backgroundLayer2.png");
    bgLayer3 = Sprite("assets/backgroundLayer3.png");
    bgLayer4 = Sprite("assets/backgroundLayer4.png");
    bgLayer5 = Sprite("assets/backgroundLayer5.png");
    bgLayer6 = Sprite("assets/backgroundLayer6.png");
    background.setSpriteWidths(spriteWidths);
}

void Results::drawBackground(sf::RenderWindow &window, Background &background) {
    sf::Vector2<float> position = sf::Vector2<float>(0,0);
    bgLayer6.draw(sf::Vector2<float>(background.getOffset(5),0), &window);
    bgLayer5.draw(sf::Vector2<float>(background.getOffset(4),50), &window);
    bgLayer4.draw(sf::Vector2<float>(background.getOffset(3),50), &window);
    bgLayer3.draw(sf::Vector2<float>(background.getOffset(2),330), &window);
    bgLayer2.draw(sf::Vector2<float>(background.getOffset(1),380), &window);
    bgLayer1.draw(sf::Vector2<float>(background.getOffset(0),450), &window);
}
