#pragma once
#include "Shape.h"
#include "Vec2f.h"

class Triangle : public Shape {
public:
    Triangle(const Vec2f& A, const Vec2f& B, const Vec2f& C) : A(A), B(B), C(C) {
        shape = new sf::CircleShape;
    }
    ~Triangle() {
        delete shape;
    }

    float getPerimeter() const override {
        float a = (A - B).getMagnitude();
        float b = (B - C).getMagnitude();
        float c = (C - A).getMagnitude();
        return a + b + c;
    }

    float getArea() const override {
        float a = (A - B).getMagnitude();
        float b = (B - C).getMagnitude();
        float c = (C - A).getMagnitude();
        float s = getPerimeter() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));

        //return std::abs(getDeterminant(m_B - m_A, m_C - m_A)) / 2.0f;
    }

    void show(sf::RenderWindow& window) override {
        shape->setFillColor(sf::Color::Green);
        //window.draw(shape);
    }
    void show() override {
        std::cout << "je suis un triangle." << "\n";
    }
private:
    Vec2f A;
    Vec2f B;
    Vec2f C;
    sf::CircleShape* shape;
};