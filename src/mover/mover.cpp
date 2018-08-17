#include "mover/mover.h"

void Mover::update()
{
    velocity.add(acceleration);
    velocity.limit(topspeed);
    location.add(velocity);
}

