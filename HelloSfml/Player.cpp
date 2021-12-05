#include "Player.h"

#include<iostream>
Player::Player(float x, float y)
{
	this->shape.setPosition({ x,y });

	this->initVariables();
	this->initShape();
}

Player::~Player()
{
}

void Player::updatePosition(const sf::RenderTarget* target)
{
	if (this->isTeleport) {
		this->teleport(target);
		this->isTeleport = false;
	}
	else {
		if (this->isTurnLeft)
		{
			this->shape.rotate(-1 * this->rotateSpeed);
		}
		else if (this->isTurnRight)
		{
			this->shape.rotate(1 * this->rotateSpeed);
		}
		if (this->isForward)
		{
			//calculer x et y selon le sin et cosin du getRotation 
			float pi = 3.14159265;
			float angularDirection = -this->shape.getRotation();
			float radAngularDirection = angularDirection * pi / 180;
			this->shape.move(-sin(radAngularDirection) * moveSpeed, -cos(radAngularDirection) * moveSpeed);
		}
	}
}
void Player::updateWindowBounds(const sf::RenderTarget* target)
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
void Player::update(const sf::RenderTarget* target)
{
	this->updatePosition(target);
	this->updateWindowBounds(target);
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

void Player::initVariables()
{
	this->rotateSpeed = 5.f;
	this->moveSpeed = 5.f;
	this->size = 10.f;

	this->b_canShoot = true;
	this->b_canTeleport = true;
	this->isTeleport = false;
	this->isForward = false;
	this->isTurnLeft = false;
	this->isTurnRight = false;
}

void Player::initShape()
{
	this->shape.setPointCount(3);
	this->shape.setRadius(this->size);
	this->shape.setOrigin({ this->size, this->size });
	this->shape.setScale({ .66f, 1.f });
	this->shape.setFillColor(sf::Color::Transparent);
	this->shape.setOutlineColor(sf::Color::White);
	this->shape.setOutlineThickness(1.f);
}

void Player::teleport(bool isPressed)
{
	this->isTeleport = (isPressed && this->b_canTeleport);
	this->b_canTeleport = !isPressed;
}

void Player::teleport(const sf::RenderTarget* target) {
	this->shape.setPosition({ static_cast<float>(rand() % target->getSize().x), static_cast<float>(rand() % target->getSize().y) });
}

const sf::Vector2f Player::getPosition() const
{
	return this->shape.getPosition();
}

void Player::setPosition(float x, float y)
{
	this->shape.setPosition({ x,y });
}

const float Player::getAngularDirection() const
{
	return this->shape.getRotation();
}

const sf::FloatRect Player::getGlobalBounds() const
{
	return this->shape.getGlobalBounds();
}

void Player::canShoot(bool canShoot)
{
	this->b_canShoot = canShoot;
}

bool Player::canShoot()
{
	return this->b_canShoot;
}

bool Player::canTeleport()
{
	return this->b_canTeleport;
}

void Player::forward(bool isPressed)
{
	this->isForward = isPressed;
}

void Player::turnLeft(bool isPressed)
{
	this->isTurnLeft = isPressed;
}

void Player::turnRight(bool isPressed)
{
	this->isTurnRight = isPressed;
}
