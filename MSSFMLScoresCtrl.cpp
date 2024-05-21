#include "MSSFMLScoresCtrl.h"

using namespace std;

MSSFMLScoresCtrl::MSSFMLScoresCtrl(MSSFMLScoresView &v) :view(v)
{

}

// Check if the click coordinates mach button coordinates
bool MSSFMLScoresCtrl::inRangeOfButton(int col, int row) const
{
    Button button = view.getButton();

    if(col >= button.left_offset && col < button.left_offset + button.width
    && row >= button.top_offset  && row < button.top_offset + button.height) return true;

    return false;
}


// Function handles mouse actions and updates menu according to action
void MSSFMLScoresCtrl::show(sf::RenderWindow &window)
{
    sf::Event event;

    while(window.pollEvent(event))
    {
        // If asked close window
        if(event.type == sf::Event::Closed) {
            window.close();
        }
        else if(event.type == sf::Event::MouseButtonPressed)
        {
            if(inRangeOfButton(event.mouseButton.x, event.mouseButton.y)) return;

            // Update window
            view.display(window);
        }
    }
}
