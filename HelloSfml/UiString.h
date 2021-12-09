#pragma once

#include "UiElement.h"

class UiString :
    public UiElement
{
public:
	UiString(std::string* textString);

	void render(sf::RenderTarget* target);
private:
	sf::Font font;
	sf::Text text;
	std::string* textString;

	void initFont();
	void initText();
};

