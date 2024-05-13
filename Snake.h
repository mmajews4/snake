#ifndef INC_278292_SNAKE_SNAKE_H
#define INC_278292_SNAKE_SNAKE_H

#include <list>
class SnakeBoard;

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
    SnakeBoard &board;
    int snake_lengh; // Snake lengh at start

public:

    // Creates snake at ehe middle of the boadrd with set length
    Snake(int sl, SnakeBoard &);

    // Function returns what parto of snake is at a given coordinates
    SnakePart isPartOfSnake(int col, int row) const;

    // Displays snake on board
    void display() const;

    // Function updates snake state
    // - checks if after move, snake isn't out of board
    // - checks if after move, snake isn't in the obsticle
    // - moves snake in current Direction
    // - checks if snake eats apple
    // - updates game state
    void updateSnake();


};


#endif //INC_278292_SNAKE_SNAKE_H
