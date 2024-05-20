#include "SnakeBoard.h"

using namespace std;

// Creates board
SnakeBoard::SnakeBoard(int w, int h, GameMode mode)
{
    width = w;
    height = h;
    
    resetBoard(mode);
}


void SnakeBoard::resetBoard(GameMode mode)
{
    board.resize(height, width);

    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            board[row][col] = EMPTY;
        }
    }
}


int SnakeBoard::getWidth() const
{
    return width;
}

int SnakeBoard::getHeight() const
{
    return height;
}

Field SnakeBoard::getBoardState(int col, int row) const
{
    return board[row][col];
}


void SnakeBoard::setBoardState(int col, int row, Field state)
{
    board[row][col] = state;
}


// Generates obsticles
bool SnakeBoard::genObsticles()
{
    return false;
}

