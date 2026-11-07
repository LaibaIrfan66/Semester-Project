#include <SFML/Graphics.hpp>
#include <optional>
using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode({ 600, 600 }), "Snake Game");
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        while (const optional event = window.pollEvent())
        {
            if (event->is<Event::Closed>())
                window.close();
        }

        window.clear(Color(40, 40, 40));
        window.display();
    }

    return 0;
}