// Nature of Code - Exercise 1.11
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"
#include "mover.hpp"

double getMouseX(sf::RenderWindow&);
double getMouseY(sf::RenderWindow&);

int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "NoC - Example 1.11");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    sf::Color white(255, 255, 255, 100); // 4th parameter is alpha

    double radius = 1;
    double topspeed = 6;
    int numMovers = 2500;
    std::vector<Mover> movers;
    std::vector<sf::CircleShape> circles;
    for(int i = 0; i < numMovers; i++)
    {
        Mover m(WIDTH, HEIGHT, topspeed);
        movers.push_back(m);
        sf::CircleShape c(radius);
        c.setPosition(m.position.x, m.position.y);
        c.setFillColor(white);
        circles.push_back(c);
        window.draw(c);
    }
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

        for(int i = 0; i < numMovers; i++)
        {
            JVector direction = JVector::sub(mouse, movers[i].position);
            movers[i].update(direction);
            movers[i].checkEdges();
            JVector pos = movers[i].position;
            circles[i].setPosition(pos.x, pos.y);
            window.draw(circles[i]);

        }
        window.display();
    }

    return 0;
}

double getMouseX(sf::RenderWindow &window)
{
    return sf::Mouse::getPosition(window).x;
}

double getMouseY(sf::RenderWindow &window)
{
    return sf::Mouse::getPosition(window).y;
}
