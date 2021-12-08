#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

class UiManager
{
	public:
		UiManager();
		UiManager(int);
		~UiManager();
		void update(const sf::RenderTarget* target, int lifes = 0);
		void render(sf::RenderTarget* target);

	private:	
		sf::Font font;
		sf::Text gameOverText;
		sf::Font gui;
		sf::Text life;

		void initVariables();
		void initVariablesUI();
};

