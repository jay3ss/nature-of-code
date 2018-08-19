#pragma once

class JVector{
public:
    double x;
    double y;

    JVector(double x_, double y_):
        x(x_),
        y(y_)
        {}

    void add(JVector);
    void mult(double);
    void sub(JVector);
};

void JVector::add(JVector v)
{
    x += v.x;
    y += v.y;
}

void JVector::mult(double n)
{
    x *= n;
    y *= n;
}

void JVector::sub(JVector v)
{
    x -= v.x;
    y -= v.y;
}
