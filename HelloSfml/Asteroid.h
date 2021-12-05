#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Asteroid
{
public:
	Asteroid(float x = 0.f, float y = 0.f, float size = 50.f);
	virtual ~Asteroid();
	
	const sf::FloatRect getGlobalBounds() const;
	const sf::Vector2f getPosition() const;

	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
private:
	sf::CircleShape shape;
	float rotateSpeed;
	int angularDirection;
	float moveSpeed;
	float size;


	void initVariables();
	void initShape();

	void updatePosition();
	void updateWindowBounds(const sf::RenderTarget* target);
};

