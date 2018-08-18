// Nature of Code - Example 1.3 (Vector subtraction)

#include "SFML/Graphics.hpp"
#include "jvector.cpp"

double getMouseX(sf::RenderWindow *win);
double getMouseY(sf::RenderWindow *win);


int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "NoC - Example 1.3");

    JVector center(WIDTH/2, HEIGHT/2);
    JVector mouse(getMouseX(&window), getMouseY(&window));
    JVector endpoint = center;


    // To draw a line, use the sf::VertexArray
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
        mouse.x = getMouseX(&window);
        mouse.y = getMouseY(&window);
        mouse.sub(center);
    
        sf::Transform translation;
        translation.translate(WIDTH/2, HEIGHT/2);
        sf::Vector2f endpoint = translation.transformPoint(mouse.x, mouse.y);

        line[1].position = endpoint;
        window.clear();
        window.draw(line);
        window.display();
    }

    return 0;
}


double getMouseX(sf::RenderWindow *win)
{
    double x = sf::Mouse::getPosition(*win).x;
    return x;
}

double getMouseY(sf::RenderWindow *win)
{
    double y = sf::Mouse::getPosition(*win).y;
    return y;
}
