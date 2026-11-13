# Semester-Project
2D Snake game in C++ using SFML
# Snake Game

This is a 2D Snake game made in C++ using SFML. It is my semester project for Programming Fundamentals.

Author: Laiba Irfan

## About the game

The player moves a snake around the screen using the arrow keys. The snake eats fruit and grows. The game will have 4 levels, and each level has a new rule.

- Level 1: Basic game. The game ends if the snake hits the boundary. Score 200 to go to the next level.
- Level 2: A black fruit appears. If the snake eats it, the game ends.
- Level 3: The snake's speed increases slowly.
- Level 4: The game also ends if the snake hits its own tail.

## What is done so far

- Set up Visual Studio with SFML
- Made the game window
- Drew the snake on a grid
- Made the snake move with the arrow keys


## How the code works

- The window is 600 x 600 pixels and is divided into a 30 x 30 grid.
- The snake is stored in two arrays, one for x positions and one for y positions.
- A loop moves each part of the snake to the place of the part in front of it. Then the head moves one square.
- A timer controls the speed of the snake.
- the arrow keys are used to move the snake.

## Tools used

C++, SFML 3.1.0, Visual Studio 2026, GitHub
