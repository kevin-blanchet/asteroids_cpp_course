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

	virtual void update();
	virtual void render(sf::RenderTarget* target) = 0;

	void display(bool display);
	const bool isDisplayed() const;

protected:
	bool b_isDisplayed;

	virtual void initVariables();
};