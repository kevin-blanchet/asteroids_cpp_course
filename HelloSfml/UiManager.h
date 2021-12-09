#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

#include "UiString.h"
#include "UiGraphic.h"

class UiManager
{
	public:
		enum struct UiElementList
		{
			Start = 0
			, Copyright = 1
			, Score = 2
			, HitPoints = 3
			, GameOver = 4
		};

		UiManager(const sf::RenderTarget* target);
		~UiManager();

		void update(const sf::RenderTarget* target);
		void render(sf::RenderTarget* target);

		void display(UiManager::UiElementList uiElement);

	private:
		std::string startText;
		std::string copyrightText;
		std::string scoreText;
		std::string hitPointsText;
		std::string gameOverText;

		std::map<UiManager::UiElementList, UiElement*> uiElementMap;

		void initVariables();
		void initUiElementMap(const sf::RenderTarget* target);

		void deleteAllItemsFromUiElementMap();
};