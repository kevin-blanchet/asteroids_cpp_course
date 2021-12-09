#include "UiElement.h"

UiElement::UiElement()
{
	this->initVariables();
}

UiElement::~UiElement()
{
}

void UiElement::update()
{
}

void UiElement::display(bool display)
{
	this->b_isDisplayed = display;
}

void UiElement::initVariables()
{
	this->b_isDisplayed = false;
}
