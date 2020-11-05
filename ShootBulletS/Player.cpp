#include "Player.h"

void Player::initVariables()
{
	this->movementspeed = 90.f;


	this->atkCooldownMax = 10.f;
	this->atkCooldown = this->atkCooldownMax;

	this->hpMax = 100;
	this->hp = this->hpMax;
}

void Player::initTexture()
{
	//load texture form file
	if (!this->texture.loadFromFile("Textures/spaceplane.GIF"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n";
	}
	
}

void Player::initSprite()
{
	//set texture to the sprite
	this->sprite.setTexture(this->texture);

	//resize sprite
	this->sprite.scale(0.1f, 0.1f);
	this->sprite.setPosition(sf::Vector2f(538.f, 417.f));
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{

}

const sf::Vector2f& Player::getPos() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

void Player::setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(x, y);
}

void Player::setHp(const int hp)
{
	this->hp = hp;
}

void Player::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}



void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementspeed * dirX,this->movementspeed * dirY);
}

const bool Player::canAtk()
{
	if (this->atkCooldown >= this->atkCooldownMax)
	{
		this->atkCooldown = 0.f;
		return true;
	}

	return false;
}

void Player::updateAtk()
{
	if(this->atkCooldown < this->atkCooldownMax)
		this->atkCooldown += 0.5f;
}

//func
void Player::update()
{
	this->updateAtk();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
