#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <vector>

#include "Player.h"
#include "Asteroid.h"
#include "Bullet.h"

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
	sf::RenderWindow* window; //On créé un pointeur pour avoir plus de controle
	sf::Event ev;
	bool endGame;
	//TODO : A rennomer
	bool booltp = true;

	Player player;
	std::vector<Asteroid> asteroids;
	std::vector<Bullet> bullets;

	void initVariables();
	void initWindow();

	void spawnAsteroids(int n = 8);

	void renderAsteroids(sf::RenderTarget* target);
	void renderBullets(sf::RenderTarget* target);

	void updateAsteroids(const sf::RenderTarget* target);
	void updateBullets(const sf::RenderTarget* target);
	void updateControls();
};

