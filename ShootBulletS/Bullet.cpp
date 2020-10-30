#include "Bullet.h"


Bullet::Bullet(sf::Texture* texture, float posX, float posY,float dir_X, float dir_Y, float movement_speed)
{
	this->shape.setTexture(*texture);

	this->shape.setPosition(posX, posY);
	this->direction.x = dir_X;
	this->direction.y = dir_Y;
	this->movementspeed = movement_speed;
}

Bullet::~Bullet()
{

}

sf::FloatRect Bullet::getBounds() const
{
	return this->shape.getGlobalBounds();
}

void Bullet::update()
{
	//movement
	this->shape.move(this->movementspeed * this->direction);
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
