/*#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Main.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

#define MAX_NUM_ITEM 4
class Menu
{
public:
	Menu(float width, float height);
	virtual ~Menu();

	

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int GetPressedItem() { return selectedItemIndex;}
private:
	sf::RenderWindow* window;

	int selectedItemIndex;
	sf::Font font;
	sf::Text mainmenu[MAX_NUM_ITEM];
};

*/