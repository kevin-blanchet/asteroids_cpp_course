#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Asteroid
{
public:
	enum struct SizeList
	{
		large = 3
		, medium = 2
		, small = 1
	};

	Asteroid(float x = 0.f, float y = 0.f, Asteroid::SizeList size = Asteroid::SizeList::large);
	virtual ~Asteroid();
	
	const sf::FloatRect getGlobalBounds() const;
	const sf::Vector2f getPosition() const;
	const Asteroid::SizeList getSizeType() const;

	void update(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
private:
	sf::CircleShape shape;
	float rotateSpeed;
	int angularDirection;
	float moveSpeed;
	float size;
	Asteroid::SizeList sizeType;

	void initVariables();
	void initSize(Asteroid::SizeList sizeType);
	void initShape();

	void updatePosition();
	void updateWindowBounds(const sf::RenderTarget* target);
};

