#include "Snake.h"

using namespace std;

// Creates snake at ehe middle of the boadrd with set length
Snake::Snake(int sl, int col, int row)
{
    snake_lengh = sl;

    // Dać zabezpieczenie przez za małą planszą
    snake.push_back({col, row, HEAD, UP});
    for(int added_lengh = 1; added_lengh < snake_lengh - 1; added_lengh ++)
    {
        snake.push_back({col, row+added_lengh, BODY, UP});
    }
    snake.push_back({col, row+(snake_lengh-1), TAIL, UP});
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


// Returns where is head
SnakeTile Snake::getSnakeHead() const
{
    return snake.front();
}


void Snake::moveSnake(Direction next_move_dir, bool apple_eaten)
{
    SnakeTile first_element = snake.front();

    // Change the previous first element to be body
    first_element.part = BODY;
    snake.front() = first_element;

    // Add new first element acording to snake direction
    switch(next_move_dir){
        case UP:
            snake.push_front({first_element.col, first_element.row-1, HEAD, next_move_dir});
            break;
        case RIGHT:
            snake.push_front({first_element.col+1, first_element.row, HEAD, next_move_dir});
            break;
        case DOWN:
            snake.push_front({first_element.col, first_element.row+1, HEAD, next_move_dir});
            break;
        case LEFT:
            snake.push_front({first_element.col-1, first_element.row, HEAD, next_move_dir});
            break;   
    }

    // If the apple is at position of head, eat apple and don't remove tail
    if(!apple_eaten)
    {
        // pop last element
        snake.pop_back();

        // change the current last element to be tail
        SnakeTile last_element = snake.back();
        last_element.part = TAIL;
        snake.back() = last_element;
    }
}
