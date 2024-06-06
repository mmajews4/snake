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

    board.resetBoard();
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

    // returns 0 if the place already is obsticle or is part of snake
    for(int lengh = 0; lengh < lengh_to_place; lengh++)
    {
        if(dir == UP    && (board.getBoardState(col, row+lengh) != EMPTY || snake.isPartOfSnake(col, row+lengh) != NONE)) return false;
        if(dir == RIGHT && (board.getBoardState(col+lengh, row) != EMPTY || snake.isPartOfSnake(col+lengh, row) != NONE)) return false;
        // it shouldn't be achead of snake at start
        if(col+lengh == board.getWidth()/2) return false;
    }

    for(int lengh = 0; lengh < lengh_to_place; lengh++)
    {
        if(dir == UP)    board.setBoardState(col, row+lengh, OBSTICLE);
        if(dir == RIGHT) board.setBoardState(col+lengh, row, OBSTICLE);
    }

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

void Controller::setGameState(GameState s)
{
    state = s;
}

void Controller::changeDirection(Direction dir)
{
    next_move_dir = dir;
}

void Controller::setGameMode(GameMode set_mode)
{
    mode = set_mode;
}

GameMode Controller::getGameMode() const
{
    return mode;
}

float Controller::getGameSpeed() const
{
    return game_speed;
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
        addScoreToFile();
        state = FINISHED;
        return;
    }

    snake.moveSnake(next_move_dir, apple_eaten);

    // - checks if snake eats apple
    apple_eaten = false;
    eatApple(head.col, head.row);
}


void Controller::addScoreToFile()
{
    std::vector<int> scoreboard(10);

    std::ifstream File("top10scores.txt");
    string line;
    int buffer;
    int current_score = score;

    if(File.is_open()) {
        // Read contsnts of the file
        for(int score_nr = 0; score_nr < 10; score_nr++) 
        {
            if(getline(File, line)){
                scoreboard[score_nr] = std::stoi(line);
            } else {
                scoreboard[score_nr] = 0; // Handle case where less than 10 scores are present
            }
        }

        File.close(); // Close the file when done
    } else {
        cerr << "Unable to open file for reading" << endl;
    }

    // Add current score
    for (int score_nr = 0; score_nr < 10; ++score_nr) {
        if (current_score > scoreboard[score_nr]) {
            buffer = scoreboard[score_nr];
            scoreboard[score_nr] = current_score;
            current_score = buffer;
        }
    }

    // Reopen the file in output mode to overwrite scoreboard
    std::ofstream outfile("top10scores.txt", std::ios::out | std::ios::trunc);
    if (outfile.is_open()) {
        for (const auto& score : scoreboard) {
            outfile << score << "\n";
        }
        outfile.close(); // Close the file after writing
    } else {
        std::cerr << "Unable to open file for writing" << std::endl;
    }
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
