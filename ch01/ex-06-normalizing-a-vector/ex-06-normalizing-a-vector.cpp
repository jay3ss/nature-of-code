// Nature of Code  - Example 1.6 (Normalizing a vector)

#include "SFML/Graphics.hpp"
#include "jvector.cpp"

double getMouseX(sf::RenderWindow&);
double getMouseY(sf::RenderWindow&);

int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "NoC - Example 1.6");

    JVector center(WIDTH/2, HEIGHT/2);
    JVector mouse(getMouseX(window), getMouseY(window));

    sf::VertexArray line(sf::Lines, 2);
    line[0].position = sf::Vector2f(center.x, center.y);
    line[0].color = sf::Color::Green;
    line[1].position = sf::Vector2f(center.x, center.y);
    line[1].color = sf::Color::Red;

    window.draw(line);
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
        mouse.x = getMouseX(window);
        mouse.y = getMouseY(window);

        // Normalize the vector then multiply a constant so that it's visible
        mouse.sub(center);
        mouse.normalize();
        mouse.mult(150);

        // Create a transform object and set its position to be the center of
        // the window. Then create a point that's translated from the center
        // of the window to a point midway between the center of the window
        // and the mouse.
        sf::Transform translation;
        translation.translate(WIDTH/2, HEIGHT/2);
        sf::Vector2f endpoint = translation.transformPoint(mouse.x, mouse.y);

        line[1].position = endpoint;
        window.clear();
        window.draw(line);
        window.display();
    }
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
