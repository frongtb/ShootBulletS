/*#include "Menu.h"
#include <iostream>

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Main.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

Menu::Menu(float width, float height)
{

	if (!this->font.loadFromFile("Fonts/Cascadia.ttf"))
		std::cout << "game failed to load font" << "\n";

	mainmenu[0].setFont(font);
	mainmenu[0].setFillColor(sf::Color::Red);
	mainmenu[0].setString("Play");
	mainmenu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUM_ITEM+1)*1));

	mainmenu[1].setFont(font);
	mainmenu[1].setFillColor(sf::Color::Yellow);
	mainmenu[1].setString("Score Board");
	mainmenu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUM_ITEM + 1) * 2));

	mainmenu[2].setFont(font);
	mainmenu[2].setFillColor(sf::Color::Yellow);
	mainmenu[2].setString("Option");
	mainmenu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUM_ITEM + 1) * 3));

	mainmenu[3].setFont(font);
	mainmenu[3].setFillColor(sf::Color::Yellow);
	mainmenu[3].setString("Exit");
	mainmenu[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUM_ITEM + 1) * 4));

}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow& window)
{
	for(int i =0 ;i<MAX_NUM_ITEM;i++)
	{
		window.draw(mainmenu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		mainmenu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		mainmenu[selectedItemIndex].setFillColor(sf::Color(128, 128, 128));
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUM_ITEM)
	{
		mainmenu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		mainmenu[selectedItemIndex].setFillColor(sf::Color(128, 128, 128));
	}
}
*/
