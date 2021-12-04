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

	void teleport(const sf::RenderTarget* target);

	const sf::Vector2f getPosition() const;
	const float getAngularDirection() const;

private:
	sf::CircleShape shape;
	float rotateSpeed;
	float moveSpeed;
	float size;

	void initVariables();
	void initShape();

	void updatePosition();
	void updateWindowBounds(const sf::RenderTarget* target);
};

