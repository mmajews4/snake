#include "MSSFMLController.h"

MSSFMLController::MSSFMLController(SnakeBoard &b, Snake &s, Controller &c, MSSFMLView &v) : board(b), snake(s), ctrl(c), view(v)
{
    displayInterval = sf::seconds(ctrl.getGameSpeed());
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

        // If asked, close window
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
            if(event.key.code == sf::Keyboard::S) {
                if(ctrl.getNextDirection() != UP && dir_changed == false){
                    ctrl.changeDirection(DOWN);
                    dir_changed = true;
                }
            }
            if(event.key.code == sf::Keyboard::A) {
                if(ctrl.getNextDirection() != RIGHT && dir_changed == false){
                    ctrl.changeDirection(LEFT);
                    dir_changed = true;
                }
            }
            if(event.key.code == sf::Keyboard::D) {
                if(ctrl.getNextDirection() != LEFT && dir_changed == false){
                    ctrl.changeDirection(RIGHT);
                    dir_changed = true;
                }
            }
        }   
    }

    // Measure the time elapsed since the last frame
    sf::Time dt = clock.restart();
    timeSinceLastDisplay += dt;

    // Check if it's time to update the display
    if (timeSinceLastDisplay >= displayInterval) 
    {
        ctrl.updateSnake();
        
        view.display(window);

        // It makes sure snake turns only once in an update
        dir_changed = false;

        // Update game speed in case it changed
        displayInterval = sf::seconds(ctrl.getGameSpeed());

        // Reset the timer
        timeSinceLastDisplay = sf::Time::Zero;
    }

}