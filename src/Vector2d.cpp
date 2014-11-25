#include "Vector2d.h"
#include <cmath>

float Vector2d::dotProduct(Vector2d &other) const
{
    return (x * other.x) + (y * other.y);
}
Vector2d Vector2d::projectOn(Vector2d &other) const
{
    Vector2d projected = Vector2d();
    float dot = dotProduct(other);
    projected.x = (dot / (other.x * other.x + other.y * other.y) ) * other.x;
    projected.y = (dot / (other.y * other.y + other.y * other.y) ) * other.y;
    return projected;
}

Vector2d Vector2d::normalize() const
{
    return Vector2d();
}
Vector2d Vector2d::leftNormal() const
{
    return Vector2d(-y, x);
}
Vector2d Vector2d::rightNormal() const
{
    return Vector2d(y, x);
}
Vector2d Vector2d::operator+ (Vector2d &other) const
{
    return Vector2d(x + other.x, y + other.y);
}
Vector2d Vector2d::operator- (Vector2d &other) const
{
    return Vector2d(x - other.x, y - other.y);
}

Vector2d Vector2d::unit() const
{
    float mag = magnitude();
    return Vector2d(x/mag, y/mag);
}

float Vector2d::magnitude() const
{
    return sqrt(x * x + y * y);

}
