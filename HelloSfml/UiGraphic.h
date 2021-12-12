#pragma once

#include "UiElement.h"

class UiGraphic :
    public UiElement
{
public:
    UiGraphic(std::vector<sf::Shape*>* shapes);

    virtual void render(sf::RenderTarget* target) override;
private:
    std::vector<sf::Shape*>* shapes;
};

