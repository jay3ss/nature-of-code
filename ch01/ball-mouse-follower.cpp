#include <iostream>
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
    Vector velocity(0.1, 0.3);
    Vector acceleration(0.01, -0.001);
    
    float topspeed = 0.25;

    MoverSFML mover(location, velocity, acceleration, topspeed);
    mover.setShape(shape);
    mover.setWindow(win, 800, 600);
    mover.display();

    window.display();

    Vector mouse;
    Vector direction;

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
        // Calculate the accleration based on a vector going from the cursor
        // location to the mover object
        mouse.x = sf::Mouse::getPosition(window).x;
        mouse.y = sf::Mouse::getPosition(window).y;

        direction = Vector::sub(mouse, mover.location);
        direction.normalize();
        direction.mult(5);
        mover.acceleration = direction;

        window.clear();
        mover.draw();
        window.display();

        std::cout << "Direction: (" << direction.x << ", " << direction.y << ")\n";
    }
    return 0;
}
