// Nature of Code - Example 1.2 (Bouncing ball with vectors)

#include "SFML/Graphics.hpp"
#include "jvector.cpp"

int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "NoC - Example 1.2");

    JVector position(100, 100);
    JVector velocity(0.08, 0.264);

    double radius = 50;

    sf::CircleShape ball(radius);
    ball.setFillColor(sf::Color::Blue);

    ball.setPosition(position.x, position.y);
    window.draw(ball);
    window.display();

    // Main event loop
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
        // Check for bouncing
        position.add(velocity);
        if((position.x + 2*radius > WIDTH) || (position.x < 0))
        {
            velocity.x *= -1;
        }
        if((position.y + 2*radius > HEIGHT) || (position.y < 0))
        {
            velocity.y *= -1;
        }
        window.clear();
        ball.setPosition(position.x, position.y);
        window.draw(ball);
        window.display();
    }
}
