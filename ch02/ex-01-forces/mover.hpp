#pragma once

#include <random>
#include "SFML/Graphics.hpp"
#include "jvector.hpp"

class Mover
{
public:
    Mover(double, double, double, double);

    void applyForce(JVector);
    void checkEdges();
    void update();
    void update(JVector);

    JVector position;
    JVector velocity;
    JVector acceleration;
private:
    double _width;
    double _height;
    double _mass;
    double _radius;

    sf::CircleShape _circle;
};

Mover::Mover(double w, double h, double m, double r)
{
    _width = w;
    _height = h;
    _mass = m;
    _radius = r;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> pxunif(0, _width);
    std::uniform_real_distribution<double> pyunif(0, _height);
    position.x = pxunif(gen);
    position.y = pyunif(gen);

    velocity.x = 0;
    velocity.y = 0;

    acceleration.x = 0;
    acceleration.y = 0;
}

void Mover::applyForce(JVector force)
{
    JVector f = JVector::div(force, _mass);
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

