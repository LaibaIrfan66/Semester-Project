#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace sf;

const int CELL = 20;
const int COLS = 30;
const int ROWS = 30;

int fruitX;
int fruitY;

void placeFruit(int snakeX[], int snakeY[], int length)
{
    bool onSnake = true;

    while (onSnake)
    {
        fruitX = rand() % COLS;
        fruitY = rand() % ROWS;

        onSnake = false;
        for (int i = 0; i < length; i++)
        {
            if (snakeX[i] == fruitX && snakeY[i] == fruitY)
                onSnake = true;
        }
    }
}

int main()
{
    srand(time(0));

    RenderWindow window(VideoMode({ COLS * CELL, ROWS * CELL }), "Snake Game");
    window.setFramerateLimit(60);

    int snakeX[900];
    int snakeY[900];
    int length = 3;

    snakeX[0] = 15;  snakeY[0] = 15;
    snakeX[1] = 14;  snakeY[1] = 15;
    snakeX[2] = 13;  snakeY[2] = 15;

    int dx = 1;
    int dy = 0;
    int score = 0;

    placeFruit(snakeX, snakeY, length);

    Clock clock;
    float timer = 0;
    float delay = 0.25f;

    RectangleShape box(Vector2f(CELL - 1, CELL - 1));

    while (window.isOpen())
    {
        while (const optional event = window.pollEvent())
        {
            if (event->is<Event::Closed>())
                window.close();
        }

       
        if (Keyboard::isKeyPressed(Keyboard::Key::Up) && dy == 0)
        {
            dx = 0;
            dy = -1;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Down) && dy == 0)
        {
            dx = 0;
            dy = 1;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Left) && dx == 0)
        {
            dx = -1;
            dy = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Right) && dx == 0)
        {
            dx = 1;
            dy = 0;
        }
        timer += clock.restart().asSeconds();
        if (timer >= delay)
        {
            timer = 0;

            
            int tailX = snakeX[length - 1];
            int tailY = snakeY[length - 1];

            for (int i = length - 1; i > 0; i--)
            {
                snakeX[i] = snakeX[i - 1];
                snakeY[i] = snakeY[i - 1];
            }

            snakeX[0] = snakeX[0] + dx;
            snakeY[0] = snakeY[0] + dy;

            
            if (snakeX[0] == fruitX && snakeY[0] == fruitY)
            {
                snakeX[length] = tailX;   
                snakeY[length] = tailY;
                length++;

                score = score + 10;
                cout << "Score: " << score << endl;

                placeFruit(snakeX, snakeY, length);
            }
        }

        window.clear(Color(40, 40, 40));

       
        box.setFillColor(Color::Red);
        box.setPosition(Vector2f(fruitX * CELL, fruitY * CELL));
        window.draw(box);

        for (int i = 0; i < length; i++)
        {
            if (i == 0)
                box.setFillColor(Color::Green);
            else
                box.setFillColor(Color(0, 150, 0));

            box.setPosition(Vector2f(snakeX[i] * CELL, snakeY[i] * CELL));
            window.draw(box);
        }

        window.display();
    }

    return 0;
}