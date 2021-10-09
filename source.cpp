#include <SFML/Graphics.hpp>
int main()
{
    sf::RenderWindow window(sf::VideoMode(1100, 1100), "SFML Works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(102, 153, 255));
        shape.setFillColor(sf::Color(255, 102, 102));
        window.draw(shape);
        window.display();
    }

    return 0;
}
//255, 102, 217