#pragma once
#ifndef ENEMY_H
#define ENEMY_H

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
class Enemy
{
private:
	unsigned pointCount;
	sf::CircleShape shape;

	int type;
	float speed;
	int hp;
	int hpMax;
	int damage;
	int points;

	void initShape();
	void initVariables();

public:
	Enemy(float pos_x, float pos_y);
	virtual ~Enemy();

	//accessors
	const sf::FloatRect getBounds() const;
	const int& getPoints() const;
	const int& getDamage() const;

	//func
	void update();
	void render(sf::RenderTarget* target);
};

#endif
