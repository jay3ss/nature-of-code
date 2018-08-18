#ifndef JVECTOR_EX_1_03_H
#define JVECTOR_EX_1_03_H

#include <cmath>

class JVector{
public:
    double x;
    double y;

    JVector(double x_, double y_):
        x(x_),
        y(y_)
        {}

    void add(JVector);
    void div(double);
    double mag();
    void mult(double);
    void normalize();
    void sub(JVector);
};

void JVector::add(JVector v)
{
    x += v.x;
    y += v.y;
}

void JVector::div(double n)
{
    x /= n;
    y /= n;
}

double JVector::mag()
{
    return std::sqrt(x*x + y*y);
}

void JVector::mult(double n)
{
    x *= n;
    y *= n;
}

void JVector::normalize()
{
    float m = mag();
    if(m != 0)
    {
        div(m);
    }
}

void JVector::sub(JVector v)
{
    x -= v.x;
    y -= v.y;
}

#endif // JVECTOR_EX_1_03_H
