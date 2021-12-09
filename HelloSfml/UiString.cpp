#include "UiString.h"

UiString::UiString(std::string* textString)
{
	this->textString = textString;
	this->initFont();
	this->initText();
}

void UiString::render(sf::RenderTarget* target)
{
	target->draw(this->text);
}

void UiString::initFont()
{
	if (!this->font.loadFromFile("../Resources/Vectorb.ttf"))
	{
		std::cout << "Error while loading font" << "\n";
	}
}

void UiString::initText()
{
	this->text.setFont(this->font);
	this->text.setFillColor(sf::Color::White);
	this->text.setOrigin(this->text.getLocalBounds().width / 2.f, this->text.getLocalBounds().height / 2.f);
}