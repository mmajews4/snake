#include <iostream>
#include <SFML/Graphics.hpp>
#include "Array2D.h"
#include "SnakeBoard.h"
#include "Snake.h"
#include "Controller.h"
#include "MSSFMLView.h"
#include "MSSFMLController.h"
#include "MSSFMLMenuView.h"
#include "MSSFMLMenuCtrl.h"


using namespace std;

int main() {
    
    SnakeBoard board(20, 20, NORMAL);
    Snake snake(5, board.getWidth()/2, board.getHeight()/2);
    Controller ctrl(board, snake);

    MSSFMLView view(board, snake);
    MSSFMLController win_ctrl(board, snake, ctrl, view);
    MSSFMLMenuView menu_view(ctrl, view);
    MSSFMLMenuCtrl menu_ctrl(ctrl, menu_view);

    sf::RenderWindow window(sf::VideoMode(view.getWindowWidth(), view.getWindowHeight()), "Snake");

    while (window.isOpen())
    {
        if(ctrl.getGameState() == RUNNING) win_ctrl.play(window);

        if(ctrl.getGameState() == FINISHED) menu_ctrl.show(window);
    }

    return 0;
}
