#pragma once

#include "SFML/Graphics.hpp"
#include "jvector.hpp"

class Mover
{
public:
    Mover(double w, double h, double ts);

    void checkEdges();
    void update();
    
    JVector position;
    JVector velocity;
    JVector acceleration;
private:
    double _width;
    double _height;
    double _topspeed;

    sf::CircleShape _circle;
};

Mover::Mover(double w, double h, double ts)
{
    _width = w;
    _height = h;
    _topspeed = ts;
    position.x = _width/2;
    position.y = _height/2;

    velocity.x = 0;
    velocity.y = 0;

    acceleration.x = -0.0001;
    acceleration.y = 0.001;
}

void Mover::checkEdges()
{
    if(position.x > _width)
    {
        position.x = 0;
    }
    else if(position.x < 0)
    {
        position.x = _width;
    }

    if(position.y > _height)
    {
        position.y = 0;
    }
    else if(position.y < 0)
    {
        position.y = _height;
    }
}

void Mover::update()
{
    velocity.add(acceleration);
    velocity.limit(_topspeed);
    position.add(velocity);
}
