#include "Asteroid.h"
#include <iostream>
#include <math.h>

Asteroid::Asteroid(float x, float y, Asteroid::SizeList size)
{
	this->shape.setPosition({ x,y });

	this->initVariables();
	this->initSize(size);
	this->initShape();
}

Asteroid::~Asteroid()
{
}

const sf::FloatRect Asteroid::getGlobalBounds() const
{
	return this->shape.getGlobalBounds();
}

const sf::Vector2f Asteroid::getPosition() const
{
	return this->shape.getPosition();
}

const Asteroid::SizeList Asteroid::getSizeType() const
{
	return this->sizeType;
}

void Asteroid::updatePosition()
{
	float pi = 3.14159265;
	float radAngularDirection = this->angularDirection * pi / 180;
	this->shape.rotate(this->rotateSpeed);
	this->shape.move(sin(radAngularDirection) * moveSpeed, cos(radAngularDirection) * moveSpeed);
}

void Asteroid::updateWindowBounds(const sf::RenderTarget* target)
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

void Asteroid::update(const sf::RenderTarget* target)
{
	this->updatePosition();
	this->updateWindowBounds(target);
}

void Asteroid::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

void Asteroid::initVariables()
{
	this->angularDirection = rand() % 360;
	this->rotateSpeed = static_cast<float>(rand() % 21 - 10);
	this->moveSpeed = 2.f;
}

void Asteroid::initSize(Asteroid::SizeList sizeType)
{
	switch (sizeType)
	{
	case Asteroid::SizeList::small:
		this->sizeType = sizeType;
		this->size = 5.f;
		break;
	case Asteroid::SizeList::medium:
		this->sizeType = sizeType;
		this->size = 10.f;
		break;
	case Asteroid::SizeList::large:
	default:
		this->sizeType = Asteroid::SizeList::large;
		this->size = 20.f;
		break;
	}
}

void Asteroid::initShape()
{
	this->shape.setPointCount(7);
	this->shape.setRadius(this->size);
	this->shape.setOrigin({ this->size, this->size });
	this->shape.setFillColor(sf::Color::Transparent);
	this->shape.setOutlineColor(sf::Color::White);
	this->shape.setOutlineThickness(1.f);
}