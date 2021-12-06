#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Player
{
public:
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();

	void update(const sf::RenderTarget* target);

	void render(sf::RenderTarget* target);


	const sf::Vector2f getPosition() const;
	void setPosition(float x, float y);
	const float getAngularDirection() const;
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
	sf::CircleShape shape;
	float rotateSpeed;
	float moveSpeed;
	float size;

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

