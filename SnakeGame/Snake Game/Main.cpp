#include <SFML/Graphics.hpp>
#include <optional>
using namespace std;
using namespace sf;

const int CELL = 20;   
const int COLS = 30;   
const int ROWS = 30;  

int main()
{
    RenderWindow window(VideoMode({ COLS * CELL, ROWS * CELL }), "Snake Game");
    window.setFramerateLimit(60);

    
    int snakeX[900];
    int snakeY[900];
    int length = 3;

    snakeX[0] = 15;  snakeY[0] = 15;   
    snakeX[1] = 14;  snakeY[1] = 15;   
    snakeX[2] = 13;  snakeY[2] = 15;   

    RectangleShape box(Vector2f(CELL - 1, CELL - 1));

    while (window.isOpen())
    {
        while (const optional event = window.pollEvent())
        {
            if (event->is<Event::Closed>())
                window.close();
        }

        window.clear(Color(40, 40, 40));

        for (int i = 0; i < length; i++)
        {
            if (i == 0)
                box.setFillColor(Color::Green);       // head
            else
                box.setFillColor(Color(0, 150, 0));   // body

            box.setPosition(Vector2f(snakeX[i] * CELL, snakeY[i] * CELL));
            window.draw(box);
        }

        window.display();
    }

    return 0;
}