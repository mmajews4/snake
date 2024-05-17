#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Snake.h"
#include "SnakeBoard.h"
#include <iostream>

enum GameState { RUNNING, FINISHED };

class Controller 
{
    SnakeBoard &board;
    Snake &snake;
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

    // - checks if after move, snake isn't out of board
    // - checks if after move, snake isn't in the obsticle
    // - chceks if snakde didn't hit himself
    // - returns 0 if there was no collision and 1 if it happened
    bool checkCollision(SnakeTile head) const;

public:
    Controller(SnakeBoard &, Snake &);

    Direction getNextDirection() const;
    GameState getGameState() const;
    int getScore();

    // Changes currnet direction of snake
    void changeDirection(Direction dir);


    // - when game is running updates snake
    // - when game finished it shows menu
    void play();


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