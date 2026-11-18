#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <optional>
using namespace std;
using namespace sf;

int main()
{
    srand(time(0));

    RenderWindow window(VideoMode({ 600, 600 }), "Snake Game");
    window.setFramerateLimit(60);

    int snakeX[900];
    int snakeY[900];
    int length = 3;

    snakeX[0] = 15;
    snakeY[0] = 15;
    snakeX[1] = 14;
    snakeY[1] = 15;
    snakeX[2] = 13;
    snakeY[2] = 15;

    int dx = 1;
    int dy = 0;
    int score = 0;

    bool gameOver = false;
    bool levelComplete = false;

    int fruitX = rand() % 30;
    int fruitY = rand() % 30;

    Clock clock;
    float timer = 0;

    RectangleShape box(Vector2f(19, 19));

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

        timer = timer + clock.restart().asSeconds();

        if (timer >= 0.2 && gameOver == false && levelComplete == false)
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

            if (snakeX[0] < 0 || snakeX[0] >= 30 || snakeY[0] < 0 || snakeY[0] >= 30)
            {
                gameOver = true;
                cout << "Game Over! Score: " << score << endl;
            }

            if (gameOver == false && snakeX[0] == fruitX && snakeY[0] == fruitY)
            {
                snakeX[length] = tailX;
                snakeY[length] = tailY;
                length = length + 1;

                score = score + 10;
                cout << "Score: " << score << endl;

                fruitX = rand() % 30;
                fruitY = rand() % 30;

                if (score >= 90)
                {
                    levelComplete = true;
                    cout << "Level 1 Complete!" << endl;
                }
            }
        }

        if (gameOver == true)
            window.setTitle("Snake Game - GAME OVER - Score: " + to_string(score));
        else if (levelComplete == true)
            window.setTitle("Snake Game - LEVEL 1 COMPLETE - Score: " + to_string(score));
        else
            window.setTitle("Snake Game - Level 1 - Score: " + to_string(score) + " / 90");

        window.clear(Color(40, 40, 40));

        if (levelComplete == false)
        {
            box.setFillColor(Color::Red);
            box.setPosition(Vector2f(fruitX * 20, fruitY * 20));
            window.draw(box);
        }

        for (int i = 0; i < length; i++)
        {
            if (gameOver == true)
                box.setFillColor(Color(120, 120, 120));
            else if (i == 0)
                box.setFillColor(Color::Green);
            else
                box.setFillColor(Color(0, 150, 0));

            if (snakeX[i] >= 0 && snakeX[i] < 30 && snakeY[i] >= 0 && snakeY[i] < 30)
            {
                box.setPosition(Vector2f(snakeX[i] * 20, snakeY[i] * 20));
                window.draw(box);
            }
        }

        window.display();
    }

    return 0;
}