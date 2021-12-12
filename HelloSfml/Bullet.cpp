#include "Bullet.h"

Bullet::Bullet(float x, float y, float angularDirection)
{
	this->shape.setPosition({ x,y });
	this->angularDirection = angularDirection;

	this->initVariables();
	this->initShape();
}

Bullet::~Bullet()
{
}

bool Bullet::isDead()
{
	return this->b_isDead;
}

void Bullet::update(const sf::RenderTarget* target)
{
	this->updatePosition();
	this->updateWindowBounds(target);
	this->updateLifeSpan();
}

void Bullet::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

const sf::FloatRect Bullet::getGlobalBounds() const
{
	return this->shape.getGlobalBounds();
}

void Bullet::initVariables()
{
	this->size = 1.f;
	this->moveSpeed = 20.f;
	this->lifeSpan = 0;
	this->lifeSpanMax = 20;

	this->b_isDead = false;
}

void Bullet::initShape()
{
	this->shape.setPointCount(4);
	this->shape.setRadius(this->size);
	this->shape.setOrigin({ this->size, this->size });
	this->shape.setFillColor(sf::Color::White);
}

void Bullet::updatePosition()
{
	float pi = 3.14159265f;
	float radAngularDirection = - this->angularDirection * pi / 180;
	this->shape.move(- sin(radAngularDirection) * moveSpeed, - cos(radAngularDirection) * moveSpeed);
}

void Bullet::updateLifeSpan()
{
	this->lifeSpan++;
	this->b_isDead = (this->lifeSpan > this->lifeSpanMax);
}

void Bullet::updateWindowBounds(const sf::RenderTarget* target)
{
	if (this->shape.getPosition().x < 0.f)
		this->shape.move({ 1.f * target->getSize().x, 0.f });

	if (this->shape.getPosition().y < 0.f)
		this->shape.move({ 0.f, 1.f * target->getSize().y });

	if (this->shape.getPosition().x > target->getSize().x)
		this->shape.move({ -1.f * target->getSize().x, 0.f });

	if (this->shape.getPosition().y > target->getSize().y)
		this->shape.move({ 0.f, -1.f * target->getSize().y });
}
