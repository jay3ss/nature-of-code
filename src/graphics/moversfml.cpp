#include "graphics/moversfml.h"

void MoverSFML::checkEdges()
{
    if(location.x > _width)
    {
        location.x = 0;
    }
    else if(location.x < 0)
    {
        location.x = _width;
    }

    if(location.y > _height)
    {
        location.y = 0;
    }
    else if(location.y < 0)
    {
        location.y = _height;
    }
}

void MoverSFML::display()
{
    _shape->setPosition(location.x, location.y);
    _window->draw(*_shape);
}

void MoverSFML::draw()
{
    update();
    checkEdges();
    display();
}

void MoverSFML::setShape(sf::CircleShape *s)
{
    _shape = s;
}

void MoverSFML::setWindow(sf::RenderWindow *win, float w, float h)
{
    _window = win;
    _width = w;
    _height = h;
}

void MoverSFML::update()
{
    velocity.add(acceleration);
    velocity.limit(topspeed);
    location.add(velocity);
}
