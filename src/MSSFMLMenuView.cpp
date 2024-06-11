#include "MSSFMLMenuView.h"

using namespace std;

MSSFMLMenuView::MSSFMLMenuView(Controller &c, MSSFMLView &sv, GameFont &f) : ctrl(c), snake_view(sv), font(f)
{
    buttons.emplace_back(112, 50, 5 ,100 ,200 ,15, 6, 30, "EASY", 0, font);    // width, height, outline, left_ofset, top_ofset, text_left_ofset, text_top_ofset, text_size, text, active
    buttons.emplace_back(136, 50, 5 ,232 ,200 , 2, 6, 30, "NORMAL", 0, font); 
    buttons.emplace_back(112, 50, 5 ,388 ,200 ,13, 6, 30, "HARD", 0, font);
    buttons.emplace_back(400, 50, 5 ,100 ,270 ,162, 6, 30, "PLAY", 0, font); 
    buttons.emplace_back(400, 50, 5 ,100 ,340 ,137, 6, 30, "SCORES", 0, font); 
    text = {195, 100, 50, "Score: "};// left_offset, top_offset, size, string
}



Button MSSFMLMenuView::getButton(ButtonFunction button_fuction) const
{
    return buttons[static_cast<int>(button_fuction)];
}


void MSSFMLMenuView::display(sf::RenderWindow &window)
{
    // Clear background 
    //window.clear(sf::Color::Black);
    snake_view.displayBackground(window);

    // Display currnet game mode
    for(int iterator = 0; iterator < 3; iterator++){ buttons[iterator].setActive(false); }
    if(ctrl.getGameMode() == EASY) buttons[static_cast<int>(EASY_BUTTON)].setActive(true);
    else if(ctrl.getGameMode() == NORMAL) buttons[static_cast<int>(NORMAL_BUTTON)].setActive(true);
    else if(ctrl.getGameMode() == HARD) buttons[static_cast<int>(HARD_BUTTON)].setActive(true);

    // Create a text object
    sf::Text text_view;
    text_view.setFont(font.font);
    text_view.setStyle(sf::Text::Bold);
    text_view.setCharacterSize(text.size);
    text.string = "Score: " + to_string(ctrl.getScore());
    text_view.setString(text.string);
    text_view.setPosition(text.left_offset, text.top_offset);
    text_view.setFillColor(sf::Color::White);
    text_view.setOutlineColor(sf::Color(100,100,100));
    text_view.setOutlineThickness(3);
    if(ctrl.getScore() != 0) window.draw(text_view);


    for(int button = 0; button < (int)buttons.size(); button++)
    {
        buttons[button].display(window);
    }

    // Display current frame
    window.display();
}