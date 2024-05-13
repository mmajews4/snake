#include "SnakeBoard.h"

using namespace std;

// Creates board
SnakeBoard::SnakeBoard(int w, int h, GameMode m)
{
    width = w;
    height = h;
    mode = m;
    state = RUNNING;
    board.resize(height, width);

    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            board[row][col] = EMPTY;
        }
    }
    
    


//    genApple();
}


int SnakeBoard::getWidth() const
{
    return width;
}

int SnakeBoard::getHeight() const
{
    return height;
}

// Generates apple
bool SnakeBoard::genApple()
{
/*   
    // Generacja losowej liczby
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> rand_width(0, width-1);
    uniform_int_distribution<mt19937::result_type> rand_height(0, height-1);

    int col = rand_width(rng);
    int row = rand_height(rng);
    // returns 0 if the place has mine already
    if(board[row][col].hasMine) return false;

    board[row][col].hasMine = true;
    // returns 1 if succesfully generated
    return true;
*/
    return false;
}


// Generates obsticles
bool SnakeBoard::genObsticles()
{
    return false;
}


// Finish game
// - if snake hits wall ora obsticle change gameState for FINISHED_LOSS
// - save score(snake length)
void SnakeBoard::finishGame(int s)
{
    score = s;
}  


// Updates game
// - updates snake
// - updates board if apple was eaten or obsticle moved
void SnakeBoard::update(){

}

// Displays corrent state of the board and snake
void SnakeBoard::debugDisplay(Snake &snake) const
{
    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            switch(snake.isPartOfSnake(col, row)){
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
            switch(board[row][col]){
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