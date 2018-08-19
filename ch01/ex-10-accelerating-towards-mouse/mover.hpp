#pragma once

#include <random>
#include "SFML/Graphics.hpp"
#include "jvector.hpp"

class Mover
{
public:
    Mover(double w, double h, double ts);

    void checkEdges();
    void update();
    void update(JVector);
    
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

    // Create random acceleration
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> unif(-0.075, 0.075);
    acceleration.x = unif(gen);
    acceleration.y = unif(gen);
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
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> unif(-0.075, 0.075);
    acceleration.x = unif(gen);
    acceleration.y = unif(gen);
    velocity.add(acceleration);
    velocity.limit(_topspeed);
    position.add(velocity);
}

void Mover::update(JVector dir)
{
    acceleration = dir;
    acceleration.setMag(0.8);
    //acceleration.normalize();
    velocity.add(acceleration);
    velocity.limit(_topspeed);
    position.add(velocity);
}
