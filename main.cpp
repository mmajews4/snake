#include <iostream>
#include <SFML/Graphics.hpp>
#include "Array2D.h"
#include "SnakeBoard.h"
#include "Snake.h"
#include "MSSFMLView.h"
#include "MSSFMLController.h"
#include "Controller.h"

using namespace std;

int main() {
    
    SnakeBoard board(20, 20, NORMAL);
    Snake snake(5, board.getWidth()/2, board.getHeight()/2);
    Controller ctrl(board, snake);

    MSSFMLView view(board, snake);
    MSSFMLController win_ctrl (board, snake, ctrl, view);

    sf::RenderWindow window(sf::VideoMode(view.getWindowWidth(), view.getWindowHeight()), "Snake", sf::Style::Titlebar | sf::Style::Close);

    ctrl.debug_display();  
/*    view.display(window);
    ctrl.updateSnake();
    ctrl.debug_display();
    ctrl.updateSnake();
    ctrl.debug_display();  
    ctrl.updateSnake();
    ctrl.debug_display();
    ctrl.updateSnake();
    ctrl.debug_display();  
    ctrl.updateSnake();
    ctrl.debug_display();
    ctrl.updateSnake();
    view.display(window);*/

    while (window.isOpen())
    {
        win_ctrl.play(window);
    }

    return 0;
}
