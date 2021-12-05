#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Bullet
{
public:
	Bullet(float x = 0.f, float y = 0.f, int angularDirection = 50.f);
	virtual ~Bullet();

	void update(const sf::RenderTarget* target);

	void render(sf::RenderTarget* target);

	const sf::FloatRect getGlobalBounds() const;
private:
	sf::CircleShape shape;
	int angularDirection;
	float moveSpeed;
	float size;
	float lifeSpanMax;
	float lifeSpan;

	void initVariables();
	void initShape();

	void updatePosition();
	void updateLifeSpan();
	void updateWindowBounds(const sf::RenderTarget* target);
};