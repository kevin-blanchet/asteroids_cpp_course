#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

class GuiManager
{
	public:
		GuiManager();
		~GuiManager();
		void render();
		void update();
	private:	
		sf::Font font;
		sf::Text gameOverText;

		void initVariables();
};

