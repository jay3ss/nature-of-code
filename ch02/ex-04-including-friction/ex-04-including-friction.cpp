// Nature of Code - Example 2.2 (Gravity Scaled by Mass)

#include <random>
#include <vector>
#include "SFML/Graphics.hpp"
#include "mover.hpp"


int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "NoC - Example 2.3");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    double initX = 0;
    double initY = HEIGHT/2;
    int numBalls = 100;

    // Instantiate RNG
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> unif(0.1, 75);

    std::vector<Mover> movers;
    std::vector<sf::CircleShape> balls;

    sf::Color white(255, 255, 255, 100);

    for(int i = 0; i < numBalls; i++)
    {
        double mass = unif(gen);
        Mover m(initX, initY, WIDTH, HEIGHT, mass, mass); // mass & size are related
        movers.push_back(m);

        sf::CircleShape b(mass);
        b.setPosition(initX, initY);
        b.setFillColor(white);
        balls.push_back(b);
    }

    // Forces
    JVector gravity(0, .5);
    JVector wind(0.5, 0);

    float normal = 1;
    float mu = 0.01;
    float frictionMag = mu * normal;
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
        for(int i = 0; i < numBalls; i++)
        {
            double mass = movers[i].mass;
            JVector g = JVector::mult(gravity, mass);
            JVector friction = movers[i].velocity.get();
            friction.mult(-1);
            friction.normalize();
            friction.mult(frictionMag);
            movers[i].applyForce(g);
            movers[i].applyForce(wind);
            movers[i].applyForce(friction);
            movers[i].update();
            movers[i].checkEdges();
            balls[i].setPosition(movers[i].position.x, movers[i].position.y);
            window.draw(balls[i]);
        }
        window.display();
    }
}
