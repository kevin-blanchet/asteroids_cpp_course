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
			float pi = 3.14159265f;
			this->velocity.x += sin(this->getAngularDirection() * pi / 180) * moveSpeed;
			this->velocity.y -= cos(this->getAngularDirection() * pi / 180) * moveSpeed;
			if (this->getSpeed() > this->maxSpeed) {
				this->velocity *= (this->maxSpeed / this->getSpeed());
			}
		}
		else {
			this->velocity *= this->slowRate;
		}
		this->shape.move(this->velocity);
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
void Player::updateRespawnTimer()
{
	this->respawnTimer--;
}
bool Player::isRespawning()
{
	return (this->respawnTimer > 0);
}
void Player::update(const sf::RenderTarget* target)
{
	if (this->isRespawning()) { this->updateRespawnTimer(); }
	if (this->shouldUpdate()) {
		this->updatePosition(target);
		this->updateWindowBounds(target);
	}
}

void Player::render(sf::RenderTarget* target)
{
	if (this->shouldRender()) {
		target->draw(this->shape);
	}
}

bool Player::shouldUpdate()
{
	return (!this->isRespawning());
}

bool Player::shouldRender()
{
	return (!this->isRespawning());
}

void Player::initVariables()
{
	this->rotateSpeed = 15.f;
	this->moveSpeed = 1.f;
	this->maxSpeed = 20.f;
	this->slowRate = 0.95f;
	this->size = 5.f;

	this->respawnTimer = 0;
	this->maxRespawnTimer = 24;

	this->velocity = { 0,0 };

	this->b_canShoot = true;
	this->b_canTeleport = true;
	this->isTeleport = false;
	this->isForward = false;
	this->isTurnLeft = false;
	this->isTurnRight = false;
}

void Player::initShape()
{
	//this->shape.setPointCount(3);
	this->shape.setSize(this->size);
	this->shape.setScale({ 1.f, -1.f });
	this->shape.setFillColor(sf::Color::Transparent);
	this->shape.setOutlineColor(sf::Color::White);
	this->shape.setOutlineThickness(1.f);
}

void Player::teleport(bool isPressed)
{
	if (isPressed) {
		this->isTeleport = this->b_canTeleport;
	}
	else
	{
		this->b_canTeleport = true;
	}
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

void Player::reset(float x, float y)
{
	this->setPosition(x, y);
	this->velocity = { 0.f, 0.f };
}

const float Player::getAngularDirection() const
{
	return this->shape.getRotation();
}

const float Player::getSpeed() const
{
	return sqrt(this->velocity.x * this->velocity.x + this->velocity.y * this->velocity.y);
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
	return (this->b_canShoot && this->shouldUpdate());
}

bool Player::canTeleport()
{
	return (this->b_canTeleport && this->shouldUpdate());
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

void Player::respawn()
{
	this->respawnTimer = this->maxRespawnTimer;
}
