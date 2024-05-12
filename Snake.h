#ifndef INC_278292_SNAKE_SNAKE_H
#define INC_278292_SNAKE_SNAKE_H

#include "SnakeBoard.h"
#include <list>

enum SnakePart { HEAD, BODY, TAIL };
enum Direction { UP, RIGHT, DOWN, LEFT };

struct SnakeTile {
    int col;
    int row;
    SnakePart part;
};

class Snake {

    std::list<SnakeTile> snake; 
    SnakeBoard board;
    Direction currDir; // Curent direction in wchich snake moves
    int snake_lengh; // Snake lengh at start

public:

    // Creates snake at ehe middle of the boadrd with set length
    Snake(int sl, SnakeBoard &b);

    // Function checks if at secified coorrdinates there is snake
    // - returns 1 if it is
    // - returns 0 if not
    bool isPartOfSnake(int col, int row);

    // Displays snake on board
    void display();

    // Function updates snake state
    // - checks if after move, snake isn't out of board
    // - checks if after move, snake isn't in the obsticle
    // - moves snake in current Direction
    // - checks if snake eats apple
    // - updates game state
    void updateSnake();


};


#endif //INC_278292_SNAKE_SNAKE_H
