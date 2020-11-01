#include"Menu.h"
#include"Game.h"
#include<time.h>
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Main.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

int main()
{
	Menu menu(window.getSize().x,window.getSize().y);

	menu.draw;

	srand(static_cast<unsigned>(time(0)));

	Game game;

	game.run();


	//end app
	return 0;
}