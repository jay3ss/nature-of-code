// Nature of Code - Example 1.8 (Motion 101)

#include "SFML/Graphics.hpp"
#include "mover.hpp"

int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "NoC - Example 1.7");

    double radius = 50;
    double topspeed = 1;
    Mover mover(WIDTH, HEIGHT, topspeed);
    sf::CircleShape circle(radius);
    circle.setPosition(mover.position.x, mover.position.y);
    window.draw(circle);
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
        mover.update();
        mover.checkEdges();
        circle.setPosition(mover.position.x, mover.position.y);
        window.draw(circle);
        window.display();
    }

    return 0;
}
