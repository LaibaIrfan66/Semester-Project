#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <optional>
using namespace std;
using namespace sf;

bool hitBlackFruit(int headX, int headY, int blackX, int blackY)
{
    if (headX == blackX && headY == blackY)
        return true;
    return false;
}

bool onSnake(int x, int y, int snakeX[], int snakeY[], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (snakeX[i] == x && snakeY[i] == y)
            return true;
    }
    return false;
}

float level3(int score)
{
    float delay = 0.25f - score * 0.001f;

    if (delay < 0.08f)
        delay = 0.08f;

    return delay;
}

bool level4(int headX, int headY, int snakeX[], int snakeY[], int length)
{
    for (int i = 1; i < length; i++)
    {
        if (snakeX[i] == headX && snakeY[i] == headY)
            return true;
    }
    return false;
}

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
    int level = 1;
    int highScore = 0;
    int total = 0;

    bool gameOver = false;
    bool levelComplete = false;
    bool needBlack = false;
    bool saved = false;

    int fruitX = rand() % 30;
    int fruitY = rand() % 30;
    int blackX = -1;
    int blackY = -1;

    Clock clock;
    float timer = 0;
    float delay = 0.25f;

    RectangleShape box(Vector2f(19, 19));

    ifstream inFile("highscore.txt");
    if (inFile.is_open())
    {
        inFile >> highScore;
        inFile.close();
    }

    int board[30][30];
    for (int row = 0; row < 30; row++)
    {
        for (int col = 0; col < 30; col++)
        {
            board[row][col] = 1;
        }
    }

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

        if (Keyboard::isKeyPressed(Keyboard::Key::R) && (gameOver == true || levelComplete == true))
        {
            length = 3;
            snakeX[0] = 15;
            snakeY[0] = 15;
            snakeX[1] = 14;
            snakeY[1] = 15;
            snakeX[2] = 13;
            snakeY[2] = 15;
            dx = 1;
            dy = 0;
            score = 0;
            level = 1;
            total = 0;
            gameOver = false;
            saved = false;
            levelComplete = false;
            needBlack = false;
            fruitX = rand() % 30;
            fruitY = rand() % 30;
            blackX = -1;
            blackY = -1;
            timer = 0;
        }

        delay = 0.25f;
        if (level >= 3)
            delay = level3(score);

        timer = timer + clock.restart().asSeconds();

        if (timer >= delay && gameOver == false && levelComplete == false)
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

            if (gameOver == false && level >= 2 && hitBlackFruit(snakeX[0], snakeY[0], blackX, blackY))
            {
                gameOver = true;
                cout << "Black fruit eaten! Game Over! Score: " << score << endl;
            }

            if (gameOver == false && level == 4 && level4(snakeX[0], snakeY[0], snakeX, snakeY, length))
            {
                gameOver = true;
                cout << "Tail hit! Game Over! Score: " << score << endl;
            }

            if (gameOver == false && snakeX[0] == fruitX && snakeY[0] == fruitY)
            {
                snakeX[length] = tailX;
                snakeY[length] = tailY;
                length = length + 1;

                score = score + 10;
                total = total + 10;
                cout << "Score: " << score << endl;

                fruitX = rand() % 30;
                fruitY = rand() % 30;

                if (score >= 90)
                {
                    if (level == 1)
                    {
                        level = 2;
                        cout << "Level 1 Complete! Level 2 starts" << endl;

                        length = 3;
                        snakeX[0] = 15;
                        snakeY[0] = 15;
                        snakeX[1] = 14;
                        snakeY[1] = 15;
                        snakeX[2] = 13;
                        snakeY[2] = 15;
                        dx = 1;
                        dy = 0;
                        score = 0;

                        needBlack = true;
                    }
                    else if (level == 2)
                    {
                        level = 3;
                        cout << "Level 2 Complete! Level 3 starts" << endl;

                        length = 3;
                        snakeX[0] = 15;
                        snakeY[0] = 15;
                        snakeX[1] = 14;
                        snakeY[1] = 15;
                        snakeX[2] = 13;
                        snakeY[2] = 15;
                        dx = 1;
                        dy = 0;
                        score = 0;

                        needBlack = true;
                    }
                    else if (level == 3)
                    {
                        level = 4;
                        cout << "Level 3 Complete! Level 4 starts" << endl;

                        length = 3;
                        snakeX[0] = 15;
                        snakeY[0] = 15;
                        snakeX[1] = 14;
                        snakeY[1] = 15;
                        snakeX[2] = 13;
                        snakeY[2] = 15;
                        dx = 1;
                        dy = 0;
                        score = 0;

                        needBlack = true;
                    }
                    else
                    {
                        levelComplete = true;
                        cout << "Level 4 Complete! You Win!" << endl;
                    }
                }
                else if (level >= 2)
                {
                    needBlack = true;
                }
            }

            if (needBlack == true)
            {
                do
                {
                    blackX = rand() % 30;
                    blackY = rand() % 30;
                } while (onSnake(blackX, blackY, snakeX, snakeY, length) || (blackX == fruitX && blackY == fruitY));

                needBlack = false;
            }
        }

        if ((gameOver == true || levelComplete == true) && saved == false)
        {
            if (total > highScore)
            {
                highScore = total;
                ofstream outFile("highscore.txt");
                outFile << highScore;
                outFile.close();
            }
            saved = true;
            cout << "High Score: " << highScore << endl;
        }

        if (gameOver == true)
            window.setTitle("Snake Game - GAME OVER - Score: " + to_string(score) + " - Press R to restart");
        else if (levelComplete == true)
            window.setTitle("Snake Game - YOU WIN! - Press R to restart");
        else
            window.setTitle("Snake Game - Level " + to_string(level) + " - Score: " + to_string(score) + " / 90");

        window.clear(Color(70, 70, 70));

        for (int row = 0; row < 30; row++)
        {
            for (int col = 0; col < 30; col++)
            {
                if (board[row][col] == 1)
                {
                    box.setFillColor(Color(255, 235, 120));
                    box.setPosition(Vector2f(col * 20, row * 20));
                    window.draw(box);
                }
            }
        }

        if (levelComplete == false)
        {
            box.setFillColor(Color::Red);
            box.setPosition(Vector2f(fruitX * 20, fruitY * 20));
            window.draw(box);
        }

        if (level >= 2 && levelComplete == false)
        {
            box.setFillColor(Color::Black);
            box.setPosition(Vector2f(blackX * 20, blackY * 20));
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