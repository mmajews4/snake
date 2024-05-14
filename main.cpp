#include <iostream>
#include <SFML/Graphics.hpp>
#include "Array2D.h"
#include "SnakeBoard.h"
#include "Snake.h"
#include "MSSFMLView.h"
#include "MSSFMLController.h"

using namespace std;

int main() {
    
    SnakeBoard board(20, 20, NORMAL);
    Snake snake(3, board);

    snake.debug_display();

    return 0;
}
