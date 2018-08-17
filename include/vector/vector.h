#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
public:
    Vector();
    Vector(float, float);          // 2D vector
    Vector(float, float, float);   // 3D vector

    void set(float, float);
    void set(float, float, float);

    // Normal vector math functions
    // Many are not yet implemented
    void add(Vector);
    void add(float, float);
    void add(float, float, float);
    float angleBetween(Vector);
    void cross(Vector);
    void div(float);
    float dist(Vector);
    void dot(Vector);
    float heading();
    Vector lerp(Vector);
    void limit(float);
    float mag();
    void mult(float);
    void normalize();
    Vector rotate(float);
    void sub(Vector);

    static Vector add(Vector, Vector);
    static Vector sub(Vector, Vector);
    
    float x;
    float y;
    float z;
};
#endif // PVECTOR_H
