#include "UiString.h"

UiString::UiString(std::string* textString)
{
	this->textString = textString;
	this->initFont();
	this->initText();
}

UiString::~UiString()
{
	delete this->textString;
}

void UiString::update()
{
	this->text.setString(*this->textString);
}

void UiString::render(sf::RenderTarget* target)
{
	target->draw(this->text);
}

void UiString::setCharacterSize(unsigned int size)
{
	this->text.setCharacterSize(size);
}

void UiString::setFillColor(const sf::Color color)
{
	this->text.setFillColor(color);
}

void UiString::setPosition(const sf::Vector2f position)
{
	this->text.setPosition(position);
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
	this->text.setString(*this->textString);
	this->text.setFillColor(sf::Color::White);
	this->text.setOrigin(this->text.getLocalBounds().width / 2.f, this->text.getLocalBounds().height / 2.f);
}