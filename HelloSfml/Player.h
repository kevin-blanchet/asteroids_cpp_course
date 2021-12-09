#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "SpaceshipShape.h"

class Player
{
public:
	explicit Player(float x = 0.f, float y = 0.f);
	virtual ~Player();

	void update(const sf::RenderTarget* target);

	void render(sf::RenderTarget* target);


	const sf::Vector2f getPosition() const;
	void setPosition(float x, float y);
	const float getAngularDirection() const;
	const float getSpeed() const;
	const sf::FloatRect getGlobalBounds() const;

	bool canShoot();
	void canShoot(bool isPressed);

	bool canTeleport();

	void teleport(bool isPressed = true);
	void teleport(const sf::RenderTarget* target);

	void forward(bool isPressed = true);
	void turnLeft(bool isPressed = true);
	void turnRight(bool isPressed = true);

private:
	SpaceshipShape shape;
	float rotateSpeed;
	float moveSpeed;
	float maxSpeed;
	float slowRate;
	float size;
	
	sf::Vector2f velocity;

	bool b_canShoot;	//prefixed because of a conflict with function canShoot
	bool b_canTeleport;	//prefixed because of a conflict with function canTeleport

	bool isTeleport;
	bool isTurnLeft;
	bool isTurnRight;
	bool isForward;

	void initVariables();
	void initShape();

	void updatePosition(const sf::RenderTarget* target);
	void updateWindowBounds(const sf::RenderTarget* target);
};

