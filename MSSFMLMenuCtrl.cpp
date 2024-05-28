#include "MSSFMLMenuCtrl.h"

using namespace std;

MSSFMLMenuCtrl::MSSFMLMenuCtrl(Controller &c, MSSFMLMenuView &v) :ctrl(c), view(v)
{
    first_display = true;
}


ButtonFunction MSSFMLMenuCtrl::buttonClicked(int col, int row) const
{
    int button_number = 0;
    ButtonFunction button_func = static_cast<ButtonFunction>(button_number); 

    while(button_func != NO_BUTTON)
    {
        Button button = view.getButton(button_func);

        if(button.inRangeOfButton(col,row)) return button_func;

        button_number++;
        button_func = static_cast<ButtonFunction>(button_number);
    }

    return NO_BUTTON;
}


void MSSFMLMenuCtrl::buttonAction(int col, int row)
{
    switch(buttonClicked(col, row))
    {
        case EASY_BUTTON:
            cout << "EASY" << endl;
            ctrl.setGameMode(EASY);
            break;
        case NORMAL_BUTTON:
            cout << "NORMAL" << endl;
            ctrl.setGameMode(NORMAL);
            break;
        case HARD_BUTTON:
            cout << "HARD" << endl;
            ctrl.setGameMode(HARD);
            break;
        case PLAY:
            cout << "PLAY" << endl;
            ctrl.resetGame();
            break;
        case SCORES_BUTTON:
            cout << "SCORES" << endl;
  //          scores.saveScoreToFile();
            ctrl.setGameState(SCORES);
            break;
        case NO_BUTTON:
            cout << "NO_BUTTON" << endl;
            break;
    }
}


// Function handles mouse actions and updates menu according to action
void MSSFMLMenuCtrl::show(sf::RenderWindow &window)
{
    sf::Event event;

    if(first_display)
    {
        first_display = false;
        view.display(window);
    }

    while(window.pollEvent(event))
    {
        // If asked close window
        if(event.type == sf::Event::Closed) {
            window.close();
        }
        else if(event.type == sf::Event::MouseButtonPressed)
        {
            buttonAction(event.mouseButton.x, event.mouseButton.y);
            
            if(ctrl.getGameState() != FINISHED)
            {
                first_display = true;
                return;
            }

            cout << ctrl.getGameState() << endl;

            // Update window
            view.display(window);
        }
    }
}
