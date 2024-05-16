#include "MSSFMLController.h"

MSSFMLController::MSSFMLController(SnakeBoard &b, Snake &s, Controller &c, MSSFMLView &v) : board(b), snake(s), ctrl(c), view(v)
{
    displayInterval = sf::seconds(0.2f); // 1 second
    timeSinceLastDisplay = sf::Time::Zero;
}


// Function handles mouse actions and updates board according to action
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
                if(ctrl.getNextDirection() != DOWN) ctrl.changeDirection(UP);
                std::cout<< "UP" << std::endl;
            }
            else if(event.key.code == sf::Keyboard::S) {
                if(ctrl.getNextDirection() != UP) ctrl.changeDirection(DOWN);
            }
            else if(event.key.code == sf::Keyboard::A) {
                if(ctrl.getNextDirection() != RIGHT) ctrl.changeDirection(LEFT);
            }
            else if(event.key.code == sf::Keyboard::D) {
                if(ctrl.getNextDirection() != LEFT) ctrl.changeDirection(RIGHT);
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

 //   std::cout << timeSinceLastDisplay.asMilliseconds() << std::endl;

    // Check if it's time to update the display
    if (timeSinceLastDisplay >= displayInterval) {


        std::cout << timeSinceLastDisplay.asMilliseconds() << std::endl;

        ctrl.updateSnake();
        view.display(window);

        // Reset the timer
        timeSinceLastDisplay = sf::Time::Zero;
    }

}