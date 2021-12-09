#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class SpaceshipShape :
    public sf::Shape
{
public:
    explicit SpaceshipShape(float size = 1.f);

    virtual size_t getPointCount() const;
    virtual sf::Vector2f getPoint(std::size_t index) const;

    void setRadius(float size);

private:
    float radius;
};

