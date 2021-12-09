#include "UiElement.h"

UiElement::UiElement()
{
	this->initVariables();
}

UiElement::~UiElement()
{
}

void UiElement::update(const sf::RenderTarget* target)
{
}

void UiElement::display(bool display)
{
	this->b_isDisplayed = display;
}

const bool UiElement::isDisplayed() const
{
	return this->b_isDisplayed;
}

void UiElement::initVariables()
{
	this->b_isDisplayed = false;
}
