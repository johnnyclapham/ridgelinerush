#include "menu.h"
#include <iostream>
#include "Constants.h"

Menu::Menu(float screenWidth, float screenHeight)
{
	sf::String MenuText;
	float MenuTextWidth;

  normalCharSize = 55;
  largerCharSize = 60;
  topOffset = 230;
  sf::String fontPath = GAME_FONT_PATH;
  if(!font.loadFromFile(fontPath)){
     //error
     // new handling: if font fails to load, try alternate
     // addressing method (for Mac OS)
     font.loadFromFile("../"+fontPath);
  }

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color(240,204,136));
	MenuText = "Play Game";
	menu[0].setString(MenuText);
    menu[0].setCharacterSize(largerCharSize);
	menu[0].setPosition(sf::Vector2f(screenWidth / 2 - menu[0].getLocalBounds().width/2, topOffset + (screenHeight-topOffset) / (MAX_NUMBER_OF_ITEMS + 1) * 1 ));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	MenuText = "Options";
	menu[1].setString(MenuText);
    menu[1].setCharacterSize(normalCharSize);
	menu[1].setPosition(sf::Vector2f(screenWidth / 2 - menu[1].getLocalBounds().width/2, topOffset + (screenHeight-topOffset) / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	MenuText = "Results";
	menu[2].setString(MenuText);
    menu[2].setCharacterSize(normalCharSize);
	menu[2].setPosition(sf::Vector2f(screenWidth / 2 - menu[2].getLocalBounds().width/2, topOffset + (screenHeight-topOffset) / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	MenuText = "Exit Game";
	menu[3].setString(MenuText);
    menu[3].setCharacterSize(normalCharSize);
	menu[3].setPosition(sf::Vector2f(screenWidth / 2 - menu[3].getLocalBounds().width/2, topOffset + (screenHeight-topOffset) / (MAX_NUMBER_OF_ITEMS + 1) * 4));


	selectedItemIndex = 0;
	backgroundInit();
}


Menu::Menu()
{
}

void Menu::draw(sf::RenderWindow &window, Background &background)
{
    drawBackground(window, background);
    gameLogo.draw(sf::Vector2<float>(175,20), &window);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		menu[selectedItemIndex].setCharacterSize(normalCharSize);
		menu[selectedItemIndex].setPosition(sf::Vector2f(WINDOW_WIDTH / 2 - menu[selectedItemIndex].getLocalBounds().width/2, topOffset + (WINDOW_HEIGHT-topOffset) / (MAX_NUMBER_OF_ITEMS + 1) * (selectedItemIndex+1)));
		//decreasing our index
		selectedItemIndex--;
        menu[selectedItemIndex].setCharacterSize(largerCharSize);
		menu[selectedItemIndex].setFillColor(sf::Color(240,204,136));
		menu[selectedItemIndex].setPosition(sf::Vector2f(WINDOW_WIDTH / 2 - menu[selectedItemIndex].getLocalBounds().width/2, topOffset + (WINDOW_HEIGHT-topOffset) / (MAX_NUMBER_OF_ITEMS + 1) * (selectedItemIndex+1)));
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		menu[selectedItemIndex].setCharacterSize(normalCharSize);
		menu[selectedItemIndex].setPosition(sf::Vector2f(WINDOW_WIDTH / 2 - menu[selectedItemIndex].getLocalBounds().width/2, topOffset + (WINDOW_HEIGHT-topOffset) / (MAX_NUMBER_OF_ITEMS + 1) * (selectedItemIndex+1)));
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color(240,204,136));
		menu[selectedItemIndex].setCharacterSize(largerCharSize);
		menu[selectedItemIndex].setPosition(sf::Vector2f(WINDOW_WIDTH / 2 - menu[selectedItemIndex].getLocalBounds().width/2, topOffset + (WINDOW_HEIGHT-topOffset) / (MAX_NUMBER_OF_ITEMS + 1) * (selectedItemIndex+1)));
	}
}

int Menu::GetPressedItem(){
	return selectedItemIndex;
	//feeds the array index to our switch statement in title_screen_0

}

void Menu::backgroundInit(){
    std::vector<float> spriteWidths;
    gameLogo = Sprite("assets/Logo.png");
    bgLayer1 = Sprite("assets/backgroundLayer1.png");
    bgLayer2 = Sprite("assets/backgroundLayer2.png");
    bgLayer3 = Sprite("assets/backgroundLayer3.png");
    bgLayer4 = Sprite("assets/backgroundLayer4.png");
    bgLayer5 = Sprite("assets/backgroundLayer5.png");
    bgLayer6 = Sprite("assets/backgroundLayer6.png");
    background.setSpriteWidths(spriteWidths);
}

void Menu::drawBackground(sf::RenderWindow &window, Background &background) {
    sf::Vector2<float> position = sf::Vector2<float>(0,0);
    bgLayer6.draw(sf::Vector2<float>(background.getOffset(5),0), &window);
    bgLayer5.draw(sf::Vector2<float>(background.getOffset(4),50), &window);
    bgLayer4.draw(sf::Vector2<float>(background.getOffset(3),50), &window);
    bgLayer3.draw(sf::Vector2<float>(background.getOffset(2),330), &window);
    bgLayer2.draw(sf::Vector2<float>(background.getOffset(1),380), &window);
    bgLayer1.draw(sf::Vector2<float>(background.getOffset(0),450), &window);
}
