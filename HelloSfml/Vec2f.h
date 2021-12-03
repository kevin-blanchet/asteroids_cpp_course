#pragma once
#include <cmath>
class Vec2f
{
public:
    Vec2f(float x, float y) : x(x), y(y) {}

    float x;
    float y;

    float getMagnitude() const {
        return std::sqrt(x * x + y * y);
    }
};

Vec2f operator-(const Vec2f& v1, const Vec2f& v2)
{
    return Vec2f{ v1.x - v2.x, v1.y - v2.y };
}

float getDeterminant(const Vec2f& v1, const Vec2f& v2)
{
    return v1.x * v2.y - v2.x * v1.y;
}