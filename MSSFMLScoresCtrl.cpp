#include "MSSFMLScoresCtrl.h"

using namespace std;

MSSFMLScoresCtrl::MSSFMLScoresCtrl(MSSFMLScoresView &v, Controller &c) :view(v), ctrl(c)
{
    first_display = true;
}

// Check if the click coordinates mach button coordinates
bool MSSFMLScoresCtrl::inRangeOfButton(int col, int row) const
{
    Button button = view.getButton();

    if(button.inRangeOfButton(col, row)) return true;

    return false;
}


// Function sanes scores to file
void MSSFMLScoresCtrl::saveScoresToFile()
{
    
}


// Function handles mouse actions and updates menu according to action
void MSSFMLScoresCtrl::show(sf::RenderWindow &window)
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
            if(inRangeOfButton(event.mouseButton.x, event.mouseButton.y))
            {
                // At exit clear te screan and set socore window to starting state
                window.clear(sf::Color::Black);
                first_display = true;
                ctrl.setGameState(FINISHED);
                return;
            }

            // Update window
            view.display(window);
        }
    }
}
