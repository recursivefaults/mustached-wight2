#ifndef VECTOR_2D_H
#define VECTOR_2D_H


class Vector2d
{

    public:
        Vector2d() : x(0.0f), y(0.0f) {};
        Vector2d(float _x, float _y) : x(_x), y(_y) {};
        
        float dotProduct(Vector2d &other);
        Vector2d projectOn(Vector2d &other);
        Vector2d normalize();
        Vector2d leftNormal();
        Vector2d rightNormal();
        Vector2d operator+ (Vector2d &other);
        Vector2d operator- (Vector2d &other);
    private:
        float x;
        float y;
    protected:
};

#endif
