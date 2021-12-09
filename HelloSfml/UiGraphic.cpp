#include "UiGraphic.h"

UiGraphic::UiGraphic()
{
	this->initShape();
}

void UiGraphic::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

void UiGraphic::initShape()
{
}
