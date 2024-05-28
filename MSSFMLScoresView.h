#ifndef INC_278292_SNAKE_MSSFMLSCORESVIEW_H
#define INC_278292_SNAKE_MSSFMLSCORESVIEW_H

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Button.h"

// Displayed text
struct DisText {
    int left_offset;
    int top_offset;
    int size;
    std::string string;
};

class MSSFMLScoresView {

    const int SCORES_OFFSET = 50;

    std::vector<Button> exit_button;
    DisText text;
    GameFont &font;
    int numeration;

public:
    MSSFMLScoresView(GameFont &);

    Button getButton() const;

    // Display best 10 scores
    void display(sf::RenderWindow &);

};

#endif