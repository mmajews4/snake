#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Snake.h"
#include "SnakeBoard.h"
#include <iostream>

enum GameState { RUNNING, FINISHED, SCORES };

class Controller 
{
    const int MAX_OBSTICLE_LENGH = 5;

    SnakeBoard &board;
    Snake &snake;
    Direction next_move_dir;
    GameMode mode;
    GameState state;

    bool apple_eaten;
    int score;
    float game_speed;

    // Generates apple
    // returns 1 if succesfully generated
    // returns 0 in not
    bool genApple();


    // Generates obsticles
    // returns 1 if succesfully generated
    // returns 0 in not
    bool genObsticle();


    // Function deletes Apple at col,row and generates a new one
    void eatApple(int col, int row);

    // - checks if after move, snake isn't out of board
    // - checks if after move, snake isn't in the obsticle
    // - chceks if snakde didn't hit himself
    // - returns 0 if there was no collision and 1 if it happened
    bool checkCollision(SnakeTile head) const;

public:
    Controller(SnakeBoard &, Snake &);

    // Sets game to its starting position
    void resetGame();

    Direction getNextDirection() const;
    GameState getGameState() const;
    void setGameState(GameState);
    int getScore();
    void setGameMode(GameMode set_mode);
    GameMode getGameMode() const;
    float getGameSpeed() const;

    // Changes currnet direction of snake
    void changeDirection(Direction dir);

    // Function updates snake state
    // - checks if after move, snake isn't out of board
    // - checks if after move, snake isn't in the obsticle
    // - moves snake in current Direction
    // - checks if snake eats apple
    // - updates game state
    void updateSnake();

    // Displays currnet state of the snake and the board
    void debug_display() const;
};

#endif
