// Nature of Code - Exercise 1.10
#include <iostream>
#include "SFML/Graphics.hpp"
#include "mover.hpp"

double getMouseX(sf::RenderWindow&);
double getMouseY(sf::RenderWindow&);

int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "NoC - Example 1.10");
    window.setFramerateLimit(60);

    double radius = 50;
    double topspeed = 6;
    Mover mover(WIDTH, HEIGHT, topspeed);
    sf::CircleShape circle(radius);
    circle.setPosition(mover.position.x, mover.position.y);
    window.draw(circle);
    window.display();

    JVector center(WIDTH/2, HEIGHT/2);
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
        double mx = getMouseX(window) - radius;
        double my = getMouseY(window) - radius;
        JVector mouse(mx, my);
        JVector direction = JVector::sub(mouse, mover.position);
        mover.update(direction);
        mover.checkEdges();
        circle.setPosition(mover.position.x, mover.position.y);
        window.draw(circle);
        window.display();
        JVector v = mover.velocity;
    }

    return 0;
}

double getMouseX(sf::RenderWindow &window)
{
    double x = sf::Mouse::getPosition(window).x;
    return x;
}

double getMouseY(sf::RenderWindow &window)
{
    double y = sf::Mouse::getPosition(window).y;
    return y;
}
