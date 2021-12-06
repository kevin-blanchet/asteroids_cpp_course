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
		~UiManager();
		void update(const sf::RenderTarget* target);
		void render(sf::RenderTarget* target);

	private:	
		sf::Font font;
		sf::Text gameOverText;

		void initVariables();
};

