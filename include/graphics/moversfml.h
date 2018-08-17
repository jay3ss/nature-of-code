#ifndef MOVER_SFML_H
#define MOVER_SFML_H

#include "SFML/Graphics.hpp"
#include "mover/mover.h"

class MoverSFML : public Mover
{
public:
    using Mover::Mover;
    void checkEdges();
    void display();
    void draw();
    void setShape(sf::CircleShape*);
    void setWindow(sf::RenderWindow*, float, float);
    void update();

private:
    float _width;               // window width
    float _height;              // window height
    sf::RenderWindow *_window;   // pointer to the window
    sf::CircleShape *_shape;      // shape of the mover
};

#endif // MOVER_SFML_H
