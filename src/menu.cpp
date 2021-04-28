#include "menu.h"
#include <iostream>

Menu::Menu(float screenWidth, float screenHeight)
{
	sf::String MenuText;
	float MenuTextWidth;

  sf::String fontPath = "assets/ACETONE.ttf";
  if(!font.loadFromFile(fontPath)){
     //error
     // new handling: if font fails to load, try alternate
     // addressing method (for Mac OS)
     std::cout << "failed to load font, trying alternate path \n";
     std::cout << "now loading   : ../ACETONE.ttf \n";
     font.loadFromFile("../"+fontPath);
  }

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	MenuText = "Play Game";
	menu[0].setString(MenuText);
	menu[0].setPosition(sf::Vector2f(screenWidth / 9, screenHeight / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	menu[0].setCharacterSize(50+5);

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	MenuText = "Options";
	menu[1].setString(MenuText);
	menu[1].setPosition(sf::Vector2f(screenWidth / 9, screenHeight / (MAX_NUMBER_OF_ITEMS + 1) * 2));
	menu[1].setCharacterSize(50);

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	MenuText = "Information";
	menu[2].setString(MenuText);
	menu[2].setPosition(sf::Vector2f(screenWidth / 9, screenHeight / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	menu[2].setCharacterSize(50);

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	MenuText = "Exit Game";
	menu[3].setString(MenuText);
	menu[3].setPosition(sf::Vector2f(screenWidth / 9, screenHeight / (MAX_NUMBER_OF_ITEMS + 1) * 4));
	menu[3].setCharacterSize(50);


	selectedItemIndex = 0;
	backgroundInit();
}


Menu::Menu()
{
}

void Menu::draw(sf::RenderWindow &window, Background &background)
{
    drawBackground(window, background);
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
		menu[selectedItemIndex].setCharacterSize(50);
		//decreasing our index
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
		menu[selectedItemIndex].setCharacterSize(50+5);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		menu[selectedItemIndex].setCharacterSize(50);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
		menu[selectedItemIndex].setCharacterSize(50+5);
	}
}

int Menu::GetPressedItem(){
	return selectedItemIndex;
	//feeds the array index to our switch statement in title_screen_0

}

void Menu::backgroundInit(){
    std::vector<float> spriteWidths;
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
    bgLayer5.draw(sf::Vector2<float>(background.getOffset(4),0), &window);
    bgLayer4.draw(sf::Vector2<float>(background.getOffset(3),0), &window);
    bgLayer3.draw(sf::Vector2<float>(background.getOffset(2),280), &window);
    bgLayer2.draw(sf::Vector2<float>(background.getOffset(1),330), &window);
    bgLayer1.draw(sf::Vector2<float>(background.getOffset(0),400), &window);
}
