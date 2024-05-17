#include "MSSFMLController.h"

MSSFMLController::MSSFMLController(SnakeBoard &b, Snake &s, Controller &c, MSSFMLView &v) : board(b), snake(s), ctrl(c), view(v)
{
    displayInterval = sf::seconds(0.15);
    timeSinceLastDisplay = sf::Time::Zero;
    dir_changed = false;
}


// Function handles keyboard actions and updates board according to action
void MSSFMLController::play(sf::RenderWindow &window)
{
    sf::Event event;
    sf::Clock clock;

    while(window.pollEvent(event))
    {

        // If asked close window
        if(event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            if(event.key.code == sf::Keyboard::W) {
                if(ctrl.getNextDirection() != DOWN && dir_changed == false){
                    ctrl.changeDirection(UP);
                    dir_changed = true;
                }
            }
            else if(event.key.code == sf::Keyboard::S) {
                if(ctrl.getNextDirection() != UP && dir_changed == false){
                    ctrl.changeDirection(DOWN);
                    dir_changed = true;
                }
            }
            else if(event.key.code == sf::Keyboard::A) {
                if(ctrl.getNextDirection() != RIGHT && dir_changed == false){
                    ctrl.changeDirection(LEFT);
                    dir_changed = true;
                }
            }
            else if(event.key.code == sf::Keyboard::D) {
                if(ctrl.getNextDirection() != LEFT && dir_changed == false){
                    ctrl.changeDirection(RIGHT);
                    dir_changed = true;
                }
            }
        }
/*        else if(event.type == sf::Event::MouseButtonPressed)
        {
            // calculate on wich tile action was taken, floor to not count -0.xx as 0
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

            // Update window
            view.draw(window);
        }

        
*/    }

    // Measure the time elapsed since the last frame
    sf::Time dt = clock.restart();
    timeSinceLastDisplay += dt;

    // Check if it's time to update the display
    if (timeSinceLastDisplay >= displayInterval) 
    {
        ctrl.updateSnake();
        if(ctrl.getGameState() == RUNNING) view.display(window);

        // It makes sure snake turns only once in an update
        dir_changed = false;

        // Reset the timer
        timeSinceLastDisplay = sf::Time::Zero;
    }

}