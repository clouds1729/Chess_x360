# Chess

This is a simple chess game implementation using the SFML (Simple and Fast Multimedia Library) library in C++.

## Features
- Fully functional chess game with standard rules and moves
- Supports castling and en passant captures
- Displays the current board position
- Allows you to move pieces by clicking and dragging

## Prerequisites
- C++ compiler (e.g., GCC, Clang, MSVC)
- SFML library installed on your system

## How to Build
1. Clone the repository or download the source files.
2. Ensure you have the SFML library installed on your system.
3. Compile the code using your preferred C++ compiler and linker. For example, using GCC:
   ```
   g++ -std=c++11 -o chess main.cpp Connector.cpp -lsfml-graphics -lsfml-window -lsfml-system
   ```
4. Run the compiled executable:
   ```
   ./chess
   ```

## Usage
- The game board is displayed with the initial chess position.
- To move a piece, click and drag the piece to the desired destination.
- The game will automatically check for valid moves and update the board accordingly.
- Castling and en passant captures are supported.

## Code Structure
- `main.cpp`: The main entry point of the program, which sets up the SFML window and game loop.
- `Connector.hpp`: Defines the `Connector` class, which handles the chess logic and piece movement.
- `Connector.cpp`: Implements the `Connector` class and its member functions.

## Acknowledgments
This project was created using the SFML library, which can be found at [https://www.sfml-dev.org/](https://www.sfml-dev.org/).
