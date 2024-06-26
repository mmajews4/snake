#ifndef INC_278292_SNAKE_SNAKE_H
#define INC_278292_SNAKE_SNAKE_H

#include <list>
#include <iostream>
#include "SnakeBoard.h"


enum SnakePart { NONE, HEAD, BODY, TAIL };
enum Direction { UP, RIGHT, DOWN, LEFT };

struct SnakeTile {
    int col;
    int row;
    SnakePart part;
    Direction direction; // Here to make better animation
};

class Snake {

    std::list<SnakeTile> snake; 

    int snake_lengh; // Snake lengh at start

public:

    // Creates snake at ehe middle of the boadrd with set length
    Snake(int sl, int col, int row);

    // Resets Snake to its starting position
    void resetSnake(int col, int row);

    // Function returns what part of snake is at a given coordinates
    SnakePart isPartOfSnake(int col, int row) const;

    // Returns where is head
    SnakeTile getSnakeHead() const;

    // Returns snake lengh for score
    int getSnakeLengh() const;

    // Returns snake
    std::list<SnakeTile> getSnake() const;

    // Checks if snake hit himself
    bool checkBodyCollision(Direction dir) const;
    
    // Moves snake in current Direction
    void moveSnake(Direction next_move_dir, bool apple_eaten);
};


#endif //INC_278292_SNAKE_SNAKE_H
