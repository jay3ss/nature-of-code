#pragma once

#include <random>
#include "SFML/Graphics.hpp"
#include "jvector.hpp"

class Mover
{
public:
    Mover(double w, double h);

    void checkEdges();
    void display(sf::RenderWindow&);
    void update();
    
    JVector position;
    JVector velocity;
private:
    double _width;
    double _height;

    sf::CircleShape _circle;
};

Mover::Mover(double w, double h)
{
    _width = w;
    _height = h;
    position.x = _width/2;
    position.y = _height/2;

    // Create random velocities
    std::uniform_real_distribution<double> unif(0, 0.75);
    std::default_random_engine reng;
    velocity.x = unif(reng);
    velocity.y = unif(reng);
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
    position.add(velocity);
}
