#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Snake.h"
#include "SnakeBoard.h"
#include <iostream>

enum GameState { RUNNING, FINISHED };

class Controller 
{
    Snake &snake;
    SnakeBoard &board;
    Direction next_move_dir;
    GameMode mode;
    GameState state;

    bool apple_eaten;

    int score;

    // Generates apple
    // returns 1 if succesfully generated
    // returns 0 in not
    bool genApple();


    // Function deletes Apple at col,row and generates a new one
    void eatApple(int col, int row);

public:
    Controller(SnakeBoard &, Snake &);

    Direction getNextDirection() const
    {
        return next_move_dir;
    }

    void changeDirection(Direction dir)
    {
        next_move_dir = dir;
    }

    // Function updates snake state
    // - checks if after move, snake isn't out of board
    // - checks if after move, snake isn't in the obsticle
    // - moves snake in current Direction
    // - checks if snake eats apple
    // - updates game state
    void updateSnake();
    
    // Finish game
    // - if snake hits wall ora obsticle change gameState for FINISHED_LOSS
    // - save score(snake length)
    void finishGame(int);  

    // Updates game
    // - updates snake
    // - updates board if apple was eaten or obsticle moved
    void update();

    // Displays currnet state of the snake and the board
    void debug_display() const;
};

#endif
