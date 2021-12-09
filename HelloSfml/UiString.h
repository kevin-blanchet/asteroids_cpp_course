#pragma once

#include "UiElement.h"

class UiString :
    public UiElement
{
public:
	UiString(std::string* textString);

	void render(sf::RenderTarget* target);

	void setCharacterSize(unsigned int size);
	void setFillColor(const sf::Color color);
	void setPosition(const sf::Vector2f position);
private:
	sf::Font font;
	sf::Text text;
	std::string* textString;

	void initFont();
	void initText();
};

