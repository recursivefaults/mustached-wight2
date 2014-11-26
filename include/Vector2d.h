#ifndef VECTOR_2D_H
#define VECTOR_2D_H


class Vector2d
{

    public:
        Vector2d() : x(0.0f), y(0.0f) {};
        Vector2d(float _x, float _y) : x(_x), y(_y) {};
        
        float dotProduct(Vector2d &other) const;
        Vector2d projectOn(Vector2d &other) const;
        Vector2d normalize() const;
        Vector2d leftNormal() const;
        Vector2d rightNormal() const;
        Vector2d operator+ (Vector2d &other) const;
        Vector2d operator- (Vector2d &other) const;
        float magnitude() const;
        Vector2d unit() const;
        float y;
        float x;
    private:
    protected:
};

#endif
