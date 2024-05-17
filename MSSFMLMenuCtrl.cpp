#include "MSSFMLMenuCtrl.h"

MSSFMLMenuCtrl::MSSFMLMenuCtrl(Controller &c, MSSFMLMenuView &v) :ctrl(c), view(v)
{

}


// Function handles mouse actions and updates menu according to action
void MSSFMLMenuCtrl::show(sf::RenderWindow &window)
{
    sf::Event event;
    
    view.display(window);

    while(window.pollEvent(event))
    {
        // If asked close window
        if(event.type == sf::Event::Closed) {
            window.close();
        }
        else if(event.type == sf::Event::MouseButtonPressed)
        {
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