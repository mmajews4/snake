#ifndef INC_278292_SNAKE_MSSFMLMENU_H
#define INC_278292_SNAKE_MSSFMLMENU_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "Controller.h"
#include "MSSFMLView.h"
#include "Button.h"

enum ButtonFunction {EASY_BUTTON, NORMAL_BUTTON, HARD_BUTTON, PLAY, SCORES_BUTTON, NO_BUTTON};


// Displayed text
struct DispText {
    int left_offset;
    int top_offset;
    int size;
    std::string string;
};

class MSSFMLMenuView {

    Controller &ctrl;
    MSSFMLView &snake_view;

    std::vector<Button> buttons;
    DispText text;
    GameFont &font;

/*    sf::RectangleShape rectangle;
    sf::Text text;
*/
public:
    MSSFMLMenuView(Controller&, MSSFMLView&, GameFont&);

    Button getButton(ButtonFunction button_fuction) const; 

    // Function displays menu
    // - score
    // - GemeMode buttons
    // - Play button
    // - Scoreboard button
    // - Downoload scores to file button
    void display(sf::RenderWindow &);

};

#endif