#include "Snake.h"

// Creates snake at ehe middle of the boadrd with set length
Snake::Snake(int sl, SnakeBoard &b) : board(b)
{
    snake_lengh = sl;
    
    // Dać zabezpieczenie przez za małą planszą
    snake.push_back({1, 1, HEAD, UP});
    snake.push_back({board.getWidth()/2, board.getHeight()/2-1, BODY, UP});
    snake.push_back({board.getWidth()/2, board.getHeight()/2-2, TAIL, UP});
}


// Function returns what parto of snake is at a given coordinates
SnakePart Snake::isPartOfSnake(int col, int row) const
{
    for(const auto& iterator: snake) // It goes through every element on the list and chceks if it maches given positon
    {
        if(iterator.col == col && iterator.row == row)
        {
            return iterator.part;
        }
    }
    return NONE;
}


// Displays snake on board
void Snake::display() const
{

}


// Function updates snake state
// - checks if after move, snake isn't out of board
// - checks if after move, snake isn't in the obsticle
// - moves snake in current Direction
// - checks if snake eats apple
// - updates game state
void Snake::updateSnake()
{

}