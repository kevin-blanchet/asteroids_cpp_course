#pragma once
#include "Shape.h"
#include "Vec2f.h"

class Rectangle : public Shape {
public:
    Rectangle(const Vec2f& origin, const Vec2f& size) : origin(origin), size(size) {
        shape = new sf::CircleShape;
    }
    ~Rectangle() {
        delete shape;
    }

    float getPerimeter() const override {
        return size.x * 2 + size.y * 2;
    }

    float getArea() const override {
        return size.x * size.y;
    }

    void show(sf::RenderWindow& window) override {
        shape->setFillColor(sf::Color::Green);
        //window.draw(shape);
    }
    void show() override {
        std::cout << "je suis un rectangle." << "\n";
    }
private:
    Vec2f origin;
    Vec2f size;
    sf::CircleShape* shape;
};