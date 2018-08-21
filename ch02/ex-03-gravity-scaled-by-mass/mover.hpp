#pragma once

#include "SFML/Graphics.hpp"
#include "jvector.hpp"

class Mover
{
public:
    Mover(double, double, double, double, double, double);

    void applyForce(JVector);
    void checkEdges();
    void update();
    void update(JVector);

    JVector position;
    JVector velocity;
    JVector acceleration;
    
    double mass;
private:
    double _width;
    double _height;
    double _radius;

    sf::CircleShape _circle;
};

Mover::Mover(double x, double y, double w, double h, double m, double r)
{
    _width = w;
    _height = h;
    mass = m;
    _radius = r;

    position.x = x;
    position.y = y;

    velocity.x = 0;
    velocity.y = 0;

    acceleration.x = 0;
    acceleration.y = 0;
}

void Mover::applyForce(JVector force)
{
    JVector f = JVector::div(force, mass);
    acceleration.add(f);
}

void Mover::checkEdges()
{
    if(position.x + 2*_radius > _width)
    {
        position.x = _width - 2*_radius;
        velocity.x *= -1;
    }
    else if(position.x < 0)
    {
        velocity.x *= -1;
        position.x = 0;
    }
    if(position.y + 2*_radius > _height)
    {
        position.y = _height - 2*_radius;
        velocity.y *=-1;
    }
    else if(position.y < 0)
    {
        position.y = 0;
        velocity.y *= -1;
    }
}

void Mover::update()
{
    velocity.add(acceleration);
    position.add(velocity);
    acceleration.mult(0);
}

void Mover::update(JVector dir)
{
    acceleration = dir;
    acceleration.setMag(0.8);
    //acceleration.normalize();
    velocity.add(acceleration);
    position.add(velocity);
}

