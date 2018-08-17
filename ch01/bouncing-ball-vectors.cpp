#include <iostream>
#include <SFML/Graphics.hpp>
#include "vector/vector.h"


int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Bouncing Ball - No Vector");

    int radius = 50;

    // Create and draw the ball before entering the loop
    sf::CircleShape ball(radius);
    ball.setFillColor(sf::Color::Green);
    Vector location(400, 300);
    
    // Display ball at initial position
    ball.setPosition(location.x, location.y);
    window.draw(ball);
    window.display();

    Vector velocity(0.1, 0.33);

    while(window.isOpen())
    {
        // Check if the window has been closed
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type ==sf::Event::Closed)
            {
                window.close();
            }
        }
        // Animate and such
        // Check for being drawn outside of window (we don't want that)
        location.add(velocity);
        if((location.x > WIDTH - 2*radius) || (location.x < 0))
        {
            velocity.x *= -1;
        }
        if((location.y > HEIGHT - 2*radius) || (location.y < 0))
        {
            velocity.y *= -1;
        }
        // Position update
        ball.setPosition(location.x, location.y);
        // Draw and the ball
        window.clear();
        window.draw(ball);
        window.display();
    }
    return 0;
}
