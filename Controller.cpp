#include "Controller.h"

using namespace std;

Controller::Controller(SnakeBoard &b, Snake &s) : board(b), snake(s)
{
    state = FINISHED;
    mode = HARD;
    game_speed = 0.15;
    score = 0;
    next_move_dir = UP;
    apple_eaten = false;
    while(!genApple()){}
}


// Sets game to its starting position
void Controller::resetGame()
{
    int obsticles_to_generate;

    board.resetBoard(mode);
    snake.resetSnake(board.getWidth()/2, board.getHeight()/2);

    state = RUNNING;
    next_move_dir = UP;
    apple_eaten = false;

    if(mode == EASY)
    {
        game_speed = 0.15;
    }
    else if (mode == NORMAL)
    {
        game_speed = 0.125;
        obsticles_to_generate = 2;
    }
    else if (mode == HARD)
    {
        game_speed = 0.10;
        obsticles_to_generate = 4;
    }

    while(obsticles_to_generate > 0)
    {
        obsticles_to_generate -= genObsticle();
    }

    while(!genApple()){}
}


// Generates apple
bool Controller::genApple()
{  
    // Generacja losowej liczby
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> rand_width(0, board.getWidth()-1);
    uniform_int_distribution<mt19937::result_type> rand_height(0, board.getHeight()-1);

    int col = rand_width(rng);
    int row = rand_height(rng);
    // returns 0 if the place has already apple, obsticle or is part of snake
    if(board.getBoardState(col, row) != EMPTY || snake.isPartOfSnake(col, row) != NONE) return false;

    board.setBoardState(col, row, APPLE);

    // returns 1 if succesfully generated
    return true;
}


// Generates obsticle
bool Controller::genObsticle()
{  
    // Generacja losowej liczby
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<mt19937::result_type> rand_lengh(1, MAX_OBSTICLE_LENGH);

    int lengh_to_place = rand_lengh(rng);

    uniform_int_distribution<mt19937::result_type> rand_width(0, board.getWidth()-lengh_to_place-2);
    uniform_int_distribution<mt19937::result_type> rand_height(0, board.getHeight()-lengh_to_place-2);
    uniform_int_distribution<mt19937::result_type> rand_direction(0, 1);

    int col = rand_width(rng);
    int row = rand_height(rng);
    Direction dir = static_cast<Direction>(rand_direction(rng));

    cout << col << ", " << row << ", l:" << lengh_to_place << ", d:" << dir;

    // returns 0 if the place already is obsticle or is part of snake
    for(int lengh = 0; lengh < lengh_to_place; lengh++)
    {
        if(dir == UP    && (board.getBoardState(col, row+lengh) != EMPTY || snake.isPartOfSnake(col, row+lengh) != NONE)) return false;
        if(dir == RIGHT && (board.getBoardState(col+lengh, row) != EMPTY || snake.isPartOfSnake(col+lengh, row) != NONE)) return false;
        // it shouldn't be achead of snake at start
        if(col+lengh == board.getWidth()/2) return false;
    }


    
    cout << " GOOD1 ";

    for(int lengh = 0; lengh < lengh_to_place; lengh++)
    {
        if(dir == UP)    board.setBoardState(col, row+lengh, OBSTICLE);
        if(dir == RIGHT) board.setBoardState(col+lengh, row, OBSTICLE);
    }

    cout << "GOOD2" <<endl;

    // returns 1 if succesfully generated
    return true;
}


// If apple is at a given place
// - deletes Apple at col,row 
// - generates a new one
// - update score
void Controller::eatApple(int col, int row)
{
    if(board.getBoardState(col, row) == APPLE)
    {
        board.setBoardState(col, row, EMPTY);
        while(!genApple()){}
        apple_eaten = true;
    }

    score = snake.getSnakeLengh(); 
}


// Simple getters and setters
int Controller::getScore()
{
    return score;
}

Direction Controller::getNextDirection() const
{
    return next_move_dir;
}

GameState Controller::getGameState() const
{
    return state;
}

void Controller::changeDirection(Direction dir)
{
    next_move_dir = dir;
}

void Controller::setGameMode(GameMode set_mode)
{
    mode = set_mode;
}

float Controller::getGameSpeed() const
{
    return game_speed;
}


// Finish game
// - if snake hits wall ora obsticle change gameState for FINISHED
// - save score(snake length)
void Controller::finishGame(int s)
{

}  


// - when game is running updates snake
// - when game finished it shows menu
void Controller::play(){

}


// - checks if after move, snake isn't out of board
// - checks if after move, snake isn't in the obsticle
// - chceks if snakde didn't hit himself
// - returns 0 if there was no collision and 1 if it happened
bool Controller::checkCollision(SnakeTile head) const
{
    if((next_move_dir == LEFT  && head.col <= 0)
    or (next_move_dir == RIGHT && head.col >= board.getWidth()-1)
    or (next_move_dir == UP    && head.row <= 0)
    or (next_move_dir == DOWN  && head.row >= board.getHeight()-1)) return true;

    if((next_move_dir == LEFT  && board.getBoardState(head.col-1, head.row) == OBSTICLE)
    or (next_move_dir == RIGHT && board.getBoardState(head.col+1, head.row) == OBSTICLE)
    or (next_move_dir == UP    && board.getBoardState(head.col, head.row-1) == OBSTICLE)
    or (next_move_dir == DOWN  && board.getBoardState(head.col, head.row+1) == OBSTICLE)) return true;

    if(snake.checkBodyCollision(next_move_dir)) return true;

    return false;
}


// Function updates snake state
// - checks collisions
// - moves snake in current Direction
// - checks if snake eats apple
// - updates game state
void Controller::updateSnake()
{
    // - moves snake in current Direction
    SnakeTile head = snake.getSnakeHead();

    // checks colisons and updates game state
    if(checkCollision(head))
    {
        state = FINISHED;
        debug_display();
        return;
    }

    snake.moveSnake(next_move_dir, apple_eaten);

    // - checks if snake eats apple
    apple_eaten = false;
    eatApple(head.col, head.row);





   /* SnakeTile first_element = snake.snake.front();

    if(board.getBoardState(first_element.col, first_element.row) == APPLE)
    {
        board.eatApple(first_element.col, first_element.row);

        bool check_apple = true;
        while(check_apple)
        { 
            check_apple = false;
            // Check if apple didn't generate inside snake
            for(const auto& iterator: snake.snake) // It goes through every element on the list and chceks if it maches given positon
            {
                if(board.getBoardState(iterator.col, iterator.row) == APPLE)
                {
                    board.eatApple(iterator.col, iterator.row);
                    check_apple = true;      
                }
            }
        }
        return;
    }*/
}


// Displays currnet state of the snake and the board
void Controller::debug_display() const
{
    for(int row = 0; row < board.getHeight(); row++){
        for(int col = 0; col < board.getWidth(); col++){
            cout << " ";
            switch(snake.isPartOfSnake(col, row)){
                case HEAD:
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
        }
        cout << endl;
    }
    cout << endl;
}
