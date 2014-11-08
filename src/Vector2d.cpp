#include "Vector2d.h"
float Vector2d::dotProduct(Vector2d &other)
{
    return (x * other.x) + (y * other.y);
}
Vector2d Vector2d::projectOn(Vector2d &other)
{
    Vector2d projected = Vector2d();
    float dot = dotProduct(other);
    projected.x = (dot / (other.x * other.x + other.y * other.y) ) * other.x;
    projected.y = (dot / (other.y * other.y + other.y * other.y) ) * other.y;
    return projected;
}
Vector2d Vector2d::normalize()
{
    return Vector2d();
}
Vector2d Vector2d::leftNormal()
{
    return Vector2d();
}
Vector2d Vector2d::rightNormal()
{
    return Vector2d();
}
Vector2d Vector2d::operator+ (Vector2d &other)
{
    return Vector2d();
}
Vector2d Vector2d::operator- (Vector2d &other)
{
    return Vector2d();
}
