// Nature of Code - Example 2.5 (Fluid Resistance)

#include <random>
#include <vector>
#include <SFML/Graphics.hpp>
#include "liquid.hpp"
#include "mover.hpp"


int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "NoC - Example 2.5", sf::Style::Default, settings);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    double initX = 0;
    double initY = HEIGHT/2;
    int numBalls = 9;

    // Instantiate RNG
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> unif(0.1, 75);

    std::vector<Mover> movers;
    std::vector<sf::CircleShape> balls;

    sf::Color gray(128, 128, 128, 100);

    for(int i = 0; i < numBalls; i++)
    {
        double mass = unif(gen);
        Mover m(40+i*80, 0, WIDTH, HEIGHT, mass, mass); // mass & size are related
        movers.push_back(m);

        sf::CircleShape b(mass);
        b.setPosition(initX, initY);
        b.setFillColor(gray);
        b.setOutlineColor(sf::Color::Black);
        b.setOutlineThickness(2);
        balls.push_back(b);
    }

    // Forces
    JVector gravity(0, .5);
    Liquid liquid(0, HEIGHT/2, WIDTH, HEIGHT/2, .099);

    sf::Color blue(0, 100, 255, 150);
    sf::RectangleShape water;
    water.setFillColor(blue);
    water.setSize(sf::Vector2f(WIDTH, HEIGHT/2));
    water.setPosition(sf::Vector2f(0, HEIGHT/2));


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
        window.clear(sf::Color::White);
        for(int i = 0; i < numBalls; i++)
        {
            if(movers[i].isInLiquid(liquid))
            {
                movers[i].drag(liquid);
            }
            double mass = movers[i].mass;
            JVector g = JVector::mult(gravity, mass);
            movers[i].applyForce(g);

            movers[i].update();
            movers[i].checkEdges();
            balls[i].setPosition(movers[i].position.x, movers[i].position.y);
            window.draw(balls[i]);
        }
        window.draw(water);
        window.display();
    }
}
