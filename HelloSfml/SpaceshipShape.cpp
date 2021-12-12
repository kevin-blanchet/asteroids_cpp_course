#include "SpaceshipShape.h"

SpaceshipShape::SpaceshipShape(float size)
{
    this->size = size;
    this->setFillColor(sf::Color::Transparent);
    this->setOutlineColor(sf::Color::White);
    this->setOutlineThickness(1.f);
    this->setScale({ 1.f, -1.f });
    update();
}

size_t SpaceshipShape::getPointCount() const
{
    return 6;
}

sf::Vector2f SpaceshipShape::getPoint(std::size_t index) const
{
    sf::Vector2f returnVector;
    switch (index)
    {
    case 0:
        returnVector = { 0.f, 1.85f };
        break;
    case 1:
        returnVector = { 1.f, -1.f };
        break;
    case 2:
        returnVector = { .5f, -.5f };
        break;
    case 3:
        returnVector = { 0.f, -.3f };
        break;
    case 4:
        returnVector = { -.5f, -.5f };
        break;
    case 5:
        returnVector = { -1.f, -1.f };
        break;
    }
    return returnVector * this->size;
}

void SpaceshipShape::setSize(float size)
{
    this->size = size;
    update();
}
