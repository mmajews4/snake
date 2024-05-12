#ifndef INC_278292_SNAKE_SNAKEBOARD_H
#define INC_278292_SNAKE_SNAKEBOARD_H

#include "Array2D.h"
#include <iostream>
#include <iomanip>
#include <random>

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };
enum Field { EMPTY, APPLE, OBSTICLE};

class SnakeBoard {

    int width, height;
    int score;
    GameMode mode;
    GameState state;

    Array2D<Field> board {10, 10};

    // Generates apple
    // returns 1 if succesfully generated
    // returns 0 in not
    bool genApple();

    // Generates obsticles
    // returns 1 if succesfully generated
    // returns 0 in not
    bool genObsticles();

public:

    // Creates board
    SnakeBoard(int, int, GameMode);

    // Finish game
    // - if snake hits wall ora obsticle change gameState for FINISHED_LOSS
    // - save score(snake length)
    void finishGame(int);  

    // Updates game
    // - updates snake
    // - updates board if apple was eaten or obsticle moved
    void update();

    // Displays corrent state of the board and snake
    void debugDispaly() const;

};


#endif //INC_278292_SNAKE_SNAKEBOARD_H
