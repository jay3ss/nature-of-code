#ifndef MOVER_H
#define MOVER_H
#include "vector/vector.h"

class Mover
{
public:
    Vector location;
    Vector velocity;
    Vector acceleration;

    float topspeed;

    explicit Mover(Vector l, Vector v, Vector a, float ts):
        location(l),
        velocity(v),
        acceleration(a),
        topspeed(ts)
    {}

    void update();
};

#endif // MOVER_H
