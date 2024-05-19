#ifndef INC_278292_SNAKE_MSSFMLMENU_H
#define INC_278292_SNAKE_MSSFMLMENU_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Controller.h"
#include "MSSFMLView.h"

enum ButtonFunction {EASY_BUTTON, NORMAL_BUTTON, HARD_BUTTON, PLAY, SCORES, DL_SCORES, NO_BUTTON};

struct Button {
    int width;
    int height;
    int outline;
    int left_offset;
    int top_offset;
    int text_left_ofset;
    int text_top_ofset;
    int text_size;
    std::string text;
};

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

    Button buttons[6];
    DispText text;

/*    sf::RectangleShape rectangle;
    sf::Font font;
    sf::Text text;
*/
public:
    MSSFMLMenuView(Controller&, MSSFMLView&);

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