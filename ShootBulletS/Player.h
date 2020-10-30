#pragma once

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
class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float movementspeed;

	float atkCooldown;
	float atkCooldownMax;

	int hp;
	int hpMax;


	//pri func
	void initVariables();
	void initTexture();
	void initSprite();

public:
	Player();
	virtual ~Player();

	//accessor
	const sf::Vector2f& getPos() const;
	const sf::FloatRect getBounds() const;
	const int& getHp() const;
	const int& getHpMax() const;

	//modifiers
	void setPosition(const sf::Vector2f pos);
	void setPosition(const float x, const float y);
	void setHp(const int hp);
	void loseHp(const int value);

	//func
	void move(const float dirX, const float dirY);
	const bool canAtk();

	void updateAtk();
	void update();
	void render(sf::RenderTarget& target);
};

