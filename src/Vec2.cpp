#include "../include/Utils/Vec2.h"

Vec2::Vec2() : x(0), y(0){};
Vec2::Vec2(float x, float y) : x(x), y(y){};
Vec2 Vec2::operator+(const Vec2 &vec2) {
    return Vec2(this->x + vec2.x, this->y + vec2.y);
};
Vec2 Vec2::operator-(const Vec2 &vec2) {
    return Vec2(this->x - vec2.x, this->y - vec2.y);
};
Vec2 Vec2::operator*(float num) { return Vec2(this->x * num, this->y * num); };
float Vec2::operator*(const Vec2 &vec2) {
    return this->x * vec2.x + this->y * vec2.y;
};
float Vec2::length() { return std::sqrt(x * x + y * y); };
Vec2 Vec2::normalize() {
    double len = this->length();
    return Vec2(x / len, y / len);
};