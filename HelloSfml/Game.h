#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include "Player.h"

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

	Player player;

	void initVariables();
	void initWindow();
};

