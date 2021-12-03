#include <SFML/Graphics.hpp>
#include <iostream>
#include "Vec2f.h"
#include "Circle.h"


int main()
{
    Shape* myCircle = new Circle( Vec2f(0,0), 0.0f);
    sf::RenderWindow window(sf::VideoMode(200, 200), "Asteroids (not)");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //myCircle->show();
        myCircle->show(window);
        window.display();
    }

    return 0;
}
