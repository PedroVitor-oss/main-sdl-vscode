#include "Vec2.h"
#include <cmath>

//Vec2::Vec2(float x_, float y_) : x(x_), y(y_) {}

Vec2 Vec2::operator+(const Vec2& other) const {
    return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::operator-(const Vec2& other) const {
    return Vec2(x - other.x, y - other.y);
}

Vec2 Vec2::operator*(float scalar) const {
    return Vec2(x * scalar, y * scalar);
}

Vec2 Vec2::operator/(float scalar) const {
    return Vec2(x / scalar, y / scalar);
}

Vec2& Vec2::operator+=(const Vec2& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vec2& Vec2::operator-=(const Vec2& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vec2& Vec2::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

Vec2& Vec2::operator/=(float scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}

float Vec2::length() const {
    return std::sqrt(x * x + y * y);
}

Vec2 Vec2::normalize() const {
    float len = length();
    if (len != 0.0f) {
        return *this / len;
    } else {
        return Vec2(0.0f, 0.0f);
    }
}

float Vec2::dot(const Vec2& other) const {
    return x * other.x + y * other.y;
}

bool Vec2::operator==(const Vec2& other) const {
    return x == other.x && y == other.y;
}

bool Vec2::operator!=(const Vec2& other) const {
    return !(*this == other);
}
