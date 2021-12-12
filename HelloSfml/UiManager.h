#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

#include "UiString.h"
#include "UiGraphic.h"
#include "SpaceshipShape.h"

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

		void update();
		void render(sf::RenderTarget* target);

		void changeString(UiManager::UiElementList element, std::string string);
		void setShapeVectorLength(int length);

		void display(UiManager::UiElementList uiElement, bool shouldDisplay = true);

	private:
		std::string startText;
		std::string copyrightText;
		std::string scoreText;
		std::string gameOverText;

		std::vector<sf::Shape*> shapeVector;

		std::map<UiManager::UiElementList, UiElement*> uiElementMap;

		void initVariables();
		void initUiElementMap(const sf::RenderTarget* target);

		void deleteAllItemsFromShapeVector();
		void deleteAllItemsFromUiElementMap();
};