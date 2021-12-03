#pragma once
#include "Shape.h"
#include "Vec2f.h"

constexpr float pi()
{
    return 3.14159265358979323846f;
}

class Circle : public Shape {
public:
    Circle(const Vec2f& origin, const float& radius) : origin(origin), radius(radius) {
        shape = new sf::CircleShape;
    }
    ~Circle() {
        delete shape;
    }

    virtual float getPerimeter() const override
    {
        return 2.0f * pi() * radius;
    }

    virtual float getArea() const override
    {
        return pi() * radius * radius;
    }

    void show(sf::RenderWindow& window) override {
        //shape->setFillColor(sf::Color::Green);
        //window.draw(shape);


        sf::CircleShape shape(radius);
        shape.setPosition(origin.x, origin.y);
        shape.setFillColor(sf::Color::Green);
        window.draw(shape);
    }
    void show() override {
        std::cout << "je suis un cercle." << "\n";
    }
private:
    Vec2f origin;
    float radius;
    sf::CircleShape* shape;
};