#include "Player.h"

Player::Player(float x, float y)
{
	this->shape.setPosition({ x,y });

	this->initVariables();
	this->initShape();
}

Player::~Player()
{
}

/**
	@todo: calculer x et y selon le sin et cosin du getRotation (lors des appuis sur fleche du haut et fleche du bas)
*/
void Player::updatePosition()
{
	//Keyboard input (will be replaced?)
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
	{
		this->shape.rotate(-1 * this->rotateSpeed);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
	{
		this->shape.rotate(1 * this->rotateSpeed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		//calculer x et y selon le sin et cosin du getRotation 
		this->shape.move(0.f, -1 * this->moveSpeed);
	}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	//{
	//	this->shape.setPosition({ static_cast<float>(rand() % 480), static_cast<float>(rand() % 360) });
	//	//this->shape.move( 0.f, 1 * this->moveSpeed );
	//}
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
	this->updatePosition();
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

void Player::teleport(const sf::RenderTarget* target) {
	this->shape.setPosition({ static_cast<float>(rand() % target->getSize().x), static_cast<float>(rand() % target->getSize().y) });
}
