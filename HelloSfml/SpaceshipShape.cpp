#include "SpaceshipShape.h"

SpaceshipShape::SpaceshipShape(float radius)
{
    this->radius = radius;
    update();
}

size_t SpaceshipShape::getPointCount() const
{
    return 3;
}

sf::Vector2f SpaceshipShape::getPoint(std::size_t index) const
{
    static const float pi = 3.141592654f;

    float angle = index * 2 * pi / getPointCount() - pi / 2;
    float x = std::cos(angle) * radius;
    float y = std::sin(angle) * radius;

    return sf::Vector2f(radius + x, radius + y);
}

void SpaceshipShape::setRadius(float radius)
{
    this->radius = radius;
    update();
}
