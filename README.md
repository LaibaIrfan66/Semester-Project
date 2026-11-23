# Snake Game

This is my semester project for Programming Fundamentals. It is a 2D Snake game made in C++ using SFML in Visual Studio.

Made by:Laiba Irfan

## About the game

The player moves a snake around the screen and eats fruit to grow and score points. The game has 4 levels, and each level adds a new rule. The player needs 90 points to finish a level.

## Controls

- Arrow keys: move the snake
- R: restart the game after game over or after winning

## Features

- 4 levels, each with a new rule
- Red fruit gives 10 points and makes the snake longer
- The score and level are shown in the title of the game window
- The game restarts from Level 1 when you press R

## The levels

- Level 1: Normal game. The game ends if the snake hits the boundary.
- Level 2: A black fruit appears. If the snake eats it, the game ends.
- Level 3: The snake gets faster every time it eats a fruit.
- Level 4: The game also ends if the snake hits its own tail.

## What I used

- C++
- SFML 3.1.0
- Visual Studio 2026
- GitHub

## How to compile and run

1. Install Visual Studio 2022 with the "Desktop development with C++" option.
2. Download SFML 3.1.0 (Visual C++ 17, 64-bit) from sfml-dev.org and extract it to C:\SFML. Check that C:\SFML\include and C:\SFML\lib exist.
3. Open SnakeGame/Snake Game.slnx in Visual Studio.
4. At the top, set the configuration to Debug and x64.
5. The project settings are already saved, but if there are errors, check these in the project Properties:
   - C/C++ > General > Additional Include Directories: C:\SFML\include
   - Linker > General > Additional Library Directories: C:\SFML\lib
   - C/C++ > Language > C++ Language Standard: ISO C++17
   - Linker > Input > Additional Dependencies: sfml-graphics-d.lib, sfml-window-d.lib, sfml-system-d.lib
6. Copy sfml-graphics-d-3.dll, sfml-window-d-3.dll and sfml-system-d-3.dll from C:\SFML\bin into the folder where the .exe is built (SnakeGame\x64\Debug).
7. Press F5 to run the game.
