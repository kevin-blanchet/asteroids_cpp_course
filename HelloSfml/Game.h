#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <vector>

#include "Player.h"
#include "Asteroid.h"

/*
* Game engine
*/
class Game
{
public:
	Game();
	virtual ~Game();

	const bool isRunning() const;

	void pollEvents();
	void update();
	void render();

private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window; //On cr�� un pointeur pour avoir plus de controle
	sf::Event ev;
	bool endGame;

	Player player;
	std::vector<Asteroid> asteroids;

	void initVariables();
	void initWindow();

	void spawnAsteroids(int n = 8);
	void renderAsteroids(sf::RenderTarget* target);
	void updateAsteroids(const sf::RenderTarget* target);
};

