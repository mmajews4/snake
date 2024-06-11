#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Array2D.h"
#include "SnakeBoard.h"
#include "Snake.h"
#include "Controller.h"
#include "MSSFMLView.h"
#include "MSSFMLController.h"
#include "MSSFMLMenuView.h"
#include "MSSFMLMenuCtrl.h"
#include "MSSFMLScoresView.h"
#include "MSSFMLScoresCtrl.h"

using namespace std;

int main() {
    
    // Initialize all classes
    SnakeBoard board(20, 20);
    Snake snake(5, board.getWidth()/2, board.getHeight()/2);
    Controller ctrl(board, snake);

    GameFont font;
    MSSFMLView view(board, snake);
    MSSFMLController win_ctrl(board, snake, ctrl, view);
    MSSFMLScoresView scores_view(font, ctrl, view);
    MSSFMLScoresCtrl scores_ctrl(scores_view, ctrl);
    MSSFMLMenuView menu_view(ctrl, view, font);
    MSSFMLMenuCtrl menu_ctrl(ctrl, menu_view);

    // Render window
    sf::RenderWindow window(sf::VideoMode(view.getWindowWidth(), view.getWindowHeight()), "Snake", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    // Run prgram acording to game status
    while (window.isOpen())
    {
        if(ctrl.getGameState() == RUNNING) win_ctrl.play(window);

        if(ctrl.getGameState() == FINISHED) scores_ctrl.saveScore(window);

        if(ctrl.getGameState() == MENU) menu_ctrl.show(window);

        if(ctrl.getGameState() == SCORES) scores_ctrl.show(window);
    }

    return 0;
}
