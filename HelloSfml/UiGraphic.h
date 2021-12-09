#pragma once

#include "UiElement.h"
#include "SpaceshipShape.h"

class UiGraphic :
    public UiElement
{
public:
    UiGraphic();

    void render(sf::RenderTarget* target);
private:
    SpaceshipShape shape;

    void initShape();
};

