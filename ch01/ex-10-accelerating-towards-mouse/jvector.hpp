#pragma once

#include <cmath>
#include <ostream>

class JVector{
public:
    double x;
    double y;

    JVector(double x_, double y_):
        x(x_),
        y(y_)
        {}

    JVector():
        x(0),
        y(0)
        {}
    void add(JVector);
    void div(double);
    void limit(double);
    double mag();
    void mult(double);
    void normalize();
    void setMag(double);
    void sub(JVector);

    // Static functions
    static JVector add(JVector, JVector);
    static JVector sub(JVector, JVector);
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

void JVector::limit(double lim)
{
    if(mag()*mag() > lim)
    {
        normalize();
        mult(lim);
    }
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

void JVector::setMag(double m)
{
    normalize();
    mult(m);
}

void JVector::sub(JVector v)
{
    x -= v.x;
    y -= v.y;
}

// Static functions

JVector JVector::add(JVector u, JVector v)
{
    JVector w(u.x, u.y);
    w.add(v);
    return w;
}

JVector JVector::sub(JVector u, JVector v)
{
    JVector w(u.x, u.y);
    w.sub(v);
    return w;
}
