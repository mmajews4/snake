#ifndef INC_278292_SNAKE_SNAKEBOARD_H
#define INC_278292_SNAKE_SNAKEBOARD_H

#include "Array2D.h"
#include <iostream>
#include <iomanip>
#include <random>

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum Field { EMPTY, APPLE, OBSTICLE };

class SnakeBoard {

    int width, height;
    int score;

    Array2D<Field> board {10, 10};

    // Generates obsticles
    // returns 1 if succesfully generated
    // returns 0 in not
    bool genObsticles();

public:

    // Creates board
    SnakeBoard(int, int);

    void resetBoard();

    int getWidth() const;
    int getHeight() const;
    Field getBoardState(int col, int row) const;
    void setBoardState(int col, int row, Field state);
};


#endif //INC_278292_SNAKE_SNAKEBOARD_H
