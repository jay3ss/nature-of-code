#include <math.h>
#include "vector/vector.h"

Vector::Vector()
{
    // Constructor for a zero vector
    x = 0;
    y = 0;
    z = 0;
}

Vector::Vector(float x_, float y_)
{
    // Constructor for a 2D vector
    x = x_;
    y = y_;
    z = 0;
}

Vector::Vector(float x_, float y_, float z_)
{
    // Constructor for a 3D vector
    x = x_;
    y = y_;
    z = z_;
}

void Vector::add(float x_, float y_)
{
    // Add to the components of a 2D vector
    x += x_;
    y += y_;
}

void Vector::add(float x_, float y_, float z_)
{
    // Add to the components of a 3D vector
    x += x_;
    y += y_;
    z += z_;
}

void Vector::add(Vector v)
{
    // Add two vectors together component by component
    x += v.x;
    y += v.y;
    z += v.z;
}

Vector Vector::add(Vector a, Vector b)
{
    Vector c(a.x + b.x, a.y + b.y, a.z + b.z);
    return c;
}

void Vector::div(float n)
{
    // Divide the vector by a scalar
    x /= n;
    y /= n;
    z /= n;
}

void Vector::limit(float lim)
{
    float magSquare = mag()*mag();
    if(magSquare > lim*lim)
    {
        normalize();
        mult(lim);
    }
}

float Vector::mag()
{
    // Calculate the magnitude of the vector
    return sqrt(x*x + y*y + z*z);
}

void Vector::mult(float n)
{
    // Multiply the vector by a scalar
    x *= n;
    y *= n;
    z *= n;
}

void Vector::normalize()
{
    // Normalizes the vector
    float m = mag();
    if (m != 0)
    {
        div(m);
    }
}

void Vector::sub(Vector v)
{
    // Subtract two vectors component by component
    x -= v.x;
    y -= v.y;
    z -= v.z;
}

Vector Vector::sub(Vector a, Vector b)
{
    Vector c(a.x - b.x, a.y - b.y, a.z - b.z);
    return c;
}
