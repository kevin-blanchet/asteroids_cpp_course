#pragma once
#include <SFML/Graphics.hpp>

class Shape {
public:
    Shape() {}
    virtual ~Shape() {}

    virtual float getPerimeter() const = 0;
    virtual float getArea() const = 0;

    virtual void show(sf::RenderWindow& window) = 0;
    virtual void show() = 0;
};