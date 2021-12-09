#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

class UiElement
{
public:
	UiElement();
	~UiElement();

	void update();
	virtual void render(sf::RenderTarget* target) = 0;

	void display(bool display);

protected:
	bool b_isDisplayed;

	virtual void initVariables();
};