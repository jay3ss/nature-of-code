// Nature of Code -  Example 1.1 (Bouncing ball with no vectors)

#include <SFML/Graphics.hpp>

int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "NoC - Example 1.1");

    double x = 100;
    double y = 100;

    double xspeed = 0.08;
    double yspeed = 0.264;

    double radius = 50;

    sf::CircleShape ball(radius);
    ball.setFillColor(sf::Color::Blue);

    ball.setPosition(x, y);
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
        x += xspeed;
        y += yspeed;

        // Check for bouncing
        if ((x + 2*radius > WIDTH) || (x < 0))
        {
            xspeed *= -1;
        }
        if ((y + 2*radius > HEIGHT) || (y < 0))
        {
            yspeed *= -1;
        }
        window.clear();
        ball.setPosition(x, y);
        window.draw(ball);
        window.display();
    }
}
