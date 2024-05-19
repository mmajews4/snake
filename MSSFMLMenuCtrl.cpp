#include "MSSFMLMenuCtrl.h"

using namespace std;

MSSFMLMenuCtrl::MSSFMLMenuCtrl(Controller &c, MSSFMLMenuView &v) :ctrl(c), view(v)
{
    first_display = true;
}


ButtonFunction MSSFMLMenuCtrl::inRangeOfButton(int col, int row) const
{
    int button_number = 0;
    ButtonFunction button_func = static_cast<ButtonFunction>(button_number); 

    while(button_func != NO_BUTTON)
    {
        Button button = view.getButton(button_func);

        if(col >= button.left_offset && col < button.left_offset + button.width
        && row >= button.top_offset  && row < button.top_offset + button.height) return button_func;

        button_number++;
        button_func = static_cast<ButtonFunction>(button_number);
    }

    return NO_BUTTON;
}


void MSSFMLMenuCtrl::buttonAction(int col, int row)
{
    switch(inRangeOfButton(col, row))
    {
        case EASY_BUTTON:
            cout << "EASY" << endl;
            break;
        case NORMAL_BUTTON:
            cout << "NORMAL" << endl;
            break;
        case HARD_BUTTON:
            cout << "HARD" << endl;
            break;
        case PLAY:
            cout << "PLAY" << endl;
            break;
        case SCORES:
            cout << "SCORES" << endl;
            break;
        case DL_SCORES:
            cout << "DL_SCORES" << endl;
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
/*            // calculate on wich tile action was taken, floor to not count -0.xx as 0
            tile_press_col = floor((event.mouseButton.x - view.getLeftOffset())/view.tileLength());
            tile_press_row = floor((event.mouseButton.y - view.getTopOffset())/view.tileLength());

            // Do action acording to things pressed
            if(!(tile_press_col >= 0 && tile_press_col < board.getBoardWidth() && tile_press_row >= -1 && tile_press_row < board.getBoardHeight()))
            {
            }
            else if(tile_press_row == -1)
            {
                board.restart();
            }
            else if(event.mouseButton.button == sf::Mouse::Left)
            {
                board.revealField(tile_press_row, tile_press_col);
            }
            else if(event.mouseButton.button == sf::Mouse::Right)
            {
                board.toggleFlag(tile_press_row, tile_press_col);
            }
*/
            // Update window
            view.display(window);
        }
    }
}
