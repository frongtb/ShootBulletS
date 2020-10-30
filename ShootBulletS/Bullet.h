#pragma once
#ifndef BULLET_H
#define BULLET_H

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Main.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>
#include<string>
class Bullet
{
private:


	sf::Sprite shape;
	//sf::Texture* texture;

	sf::Vector2f direction;
	float movementspeed;
public:
	Bullet(sf::Texture* texture,float posX,float posY,float dir_X,float dir_Y,float movement_speed);
	virtual ~Bullet();


	//accessor
	sf::FloatRect getBounds() const;

	void update();
	void render(sf::RenderTarget* target);
};

#endif // !BULLET_H


