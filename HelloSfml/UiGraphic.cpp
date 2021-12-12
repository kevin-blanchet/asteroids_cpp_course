#include "UiGraphic.h"

UiGraphic::UiGraphic(std::vector<sf::Shape*>* shapes)
{
	this->shapes = shapes;
}

void UiGraphic::render(sf::RenderTarget* target)
{
	for (auto& i : *this->shapes)
	{
		target->draw(*i);
	}
}