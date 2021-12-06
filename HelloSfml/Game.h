#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <vector>

#include "Player.h"
#include "Asteroid.h"
#include "Bullet.h"
#include "UiManager.h"

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
	int hitPoint;

	enum controlMap
	{
		quit = sf::Keyboard::Escape
		, pause = sf::Keyboard::Enter
		, forward = sf::Keyboard::Up
		, teleport = sf::Keyboard::Down
		, turnLeft = sf::Keyboard::Left
		, turnRight = sf::Keyboard::Right
		, shoot = sf::Keyboard::Space
	};

	Player player;
	std::vector<Asteroid> asteroids;
	std::vector<Asteroid> temp_asteroids;
	std::vector<Bullet> bullets;
	UiManager* userInterface;

	void initVariables();
	void initWindow();

	void spawnAsteroids(int n = 8);
	void shootBulletOnPlayerPosition();
	void splitAsteroids(sf::Vector2f coord, Asteroid::SizeList size, int nbSplit);

	void winHP(int hp = 1);
	void looseHP(int hp = 1);

	void renderAsteroids(sf::RenderTarget* target);
	void renderBullets(sf::RenderTarget* target);

	void updateAsteroids(const sf::RenderTarget* target);
	void updateBullets(const sf::RenderTarget* target);
	void updateCollisions();
};

