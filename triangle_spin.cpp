#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#define PI asin(-1.0f)
#define CENTER 450
#define SPEED 4
void triangle_spin()
{
    sf::RenderWindow window(sf::VideoMode({ CENTER * 2, CENTER * 2 }), "Triangle SPIN");
    //sf::CircleShape shape(100.f);
    //sf::Color first = sf::Color(255, 255, 255, 255);
    //shape.setFillColor(first);
    //int id = 0;
    // create an array of 3 vertices that define a triangle primitive
    sf::VertexArray triangle(sf::PrimitiveType::Triangles, 3);

    // define the position of the triangle's points
    triangle[0].position = sf::Vector2f(10.f, 10.f);
    triangle[1].position = sf::Vector2f(100.f, 50.f);
    triangle[2].position = sf::Vector2f(100.f, 150.f);

    // define the color of the triangle's points
    triangle[0].color = sf::Color::White;
    triangle[1].color = sf::Color::White;
    triangle[2].color = sf::Color::White;

    sf::Clock clock;
    int counter = 0;
    //time in seconds from last frame to current frame
    float elapsed = 0.0f;
    //total elapsed time
    float timer = 0.0f;
    // no texture coordinates here, we'll see that later
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
                clock.stop();
            }
        }
        window.clear();
        window.draw(triangle);
        window.display();
        counter++;
        elapsed = clock.restart().asSeconds();
        timer += elapsed;
        triangle[0].position.x = CENTER + (cos(timer * SPEED) * CENTER);
        triangle[0].position.y = CENTER + (sin(timer * SPEED) * CENTER);
        triangle[1].position.x = CENTER + (cos(timer * SPEED + (PI * 4.0f / 3.0f)) * CENTER);
        triangle[1].position.y = CENTER + (sin(timer * SPEED + (PI * 4.0f / 3.0f)) * CENTER);
        triangle[2].position.x = CENTER + (cos(timer * SPEED + (PI * 8.0f / 3.0f)) * CENTER);
        triangle[2].position.y = CENTER + (sin(timer * SPEED + (PI * 8.0f / 3.0f)) * CENTER);
    }
}