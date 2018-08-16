#include <iostream>
#include <SFML/Graphics.hpp>


int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Bouncing Ball - No Vector");

    int radius = 50;

    // Create and draw the ball before entering the loop
    sf::CircleShape ball(radius);
    ball.setFillColor(sf::Color::Green);
    float x = 400;
    float y = 300;
    
    // Display ball at initial position
    ball.setPosition(x, y);
    window.draw(ball);
    window.display();

    float xSpeed = 0.1;
    float ySpeed = 0.33;

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
        if((x > WIDTH - 2*radius) || (x < 0))
        {
            xSpeed *= -1;
        }
        if((y > HEIGHT - 2*radius) || (y < 0))
        {
            ySpeed *= -1;
        }
        // Position update
        x += xSpeed;
        y += ySpeed;
        ball.setPosition(x, y);
        // Draw and the ball
        window.clear();
        window.draw(ball);
        window.display();
    }
    return 0;
}
