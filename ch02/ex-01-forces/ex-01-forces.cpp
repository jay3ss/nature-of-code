// Nature of Code - Example 2.1 (Forces)

#include "SFML/Graphics.hpp"
#include "mover.hpp"


int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "NoC - Example 2.1");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    double mass = 10;
    double radius  = 25;

    Mover mover(WIDTH, HEIGHT, mass, radius);
    sf::CircleShape ball(radius);
    ball.setPosition(mover.position.x, mover.position.y);
    ball.setFillColor(sf::Color::Blue); 

    // Forces
    JVector gravity(0, 5);
    JVector wind(0.5, 0);
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
        mover.applyForce(gravity);
        mover.applyForce(wind);
        mover.update();
        mover.checkEdges();
        ball.setPosition(mover.position.x, mover.position.y);
        window.clear();
        window.draw(ball);
        window.display();
    }
}
