#include "Snake.h"

using namespace std;

// Creates snake at ehe middle of the boadrd with set length
Snake::Snake(int sl, SnakeBoard &b) : board(b)
{
    snake_lengh = sl;
    
    // Dać zabezpieczenie przez za małą planszą
    snake.push_back({board.getWidth()/2, board.getHeight()/2, HEAD, UP});
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


// Displays currnet state of the snake and the board
void Snake::debug_display() const
{
    for(int row = 0; row < board.getHeight(); row++){
        for(int col = 0; col < board.getWidth(); col++){
            switch(isPartOfSnake(col, row)){
                case SnakePart::HEAD:
                    cout << "H";
                    continue;
                case BODY:
                    cout << "B";
                    continue;
                case TAIL:
                    cout << "T";
                    continue;
                case NONE:
                    break;
            }    
            switch(board.getBoardState(col, row)){
                case APPLE:
                    cout << "A";
                    break;
                case OBSTICLE:
                    cout << "O";
                    break;
                case EMPTY:
                    cout << "_";
                    break;
                default:
                    cout << "#";
                    break;
            }
            cout << " ";
        }
        cout << endl;
    }
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