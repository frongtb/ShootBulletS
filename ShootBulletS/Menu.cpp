#include "Menu.h"
#include <iostream>



Menu::Menu(float width, float height)
{
	if (!this->font.loadFromFile("Fonts/Cascadia.ttf"))
		std::cout << "game failed to load font" << "\n";

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUM_ITEM+1)*1));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::Yellow);
	menu[1].setString("Score Board");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUM_ITEM + 1) * 2));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::Yellow);
	menu[2].setString("Option");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUM_ITEM + 1) * 3));

	menu[3].setFont(font);
	menu[3].setColor(sf::Color::Yellow);
	menu[3].setString("Exit");
	menu[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUM_ITEM + 1) * 4));

}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow& window)
{
	for(int i =0 ;i<MAX_NUM_ITEM;i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{

}

void Menu::MoveDown()
{

}
