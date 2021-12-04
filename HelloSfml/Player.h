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

	void updatePosition();
	void updateWindowBounds(const sf::RenderTarget* target);
	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
	void teleport(const sf::RenderTarget* target);

private:
	sf::CircleShape shape;
	float rotateSpeed;
	float moveSpeed;
	float size;
	float angularDirection;

	void initVariables();
	void initShape();
};

