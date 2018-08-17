#include "SFML/Graphics.hpp"
#include "vector/vector.h"
#include "graphics/moversfml.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "MoverSFML Demo");
    sf::RenderWindow *win;
    win = &window;

    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Green);
    sf::CircleShape *shape;
    shape = &circle;


    Vector location(200, 200);
    Vector velocity(0.01, 0.033);
    Vector acceleration(0.00001, -0.00001);
    float topspeed = 10;

    MoverSFML mover(location, velocity, acceleration, topspeed);
    mover.setShape(shape);
    mover.setWindow(win, 800, 600);
    mover.display();

    window.display();

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        mover.draw();
        window.display();
    }
    return 0;
}
