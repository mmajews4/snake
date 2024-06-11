#ifndef INC_278292_SNAKE_MSSFMLSCORESVIEW_H
#define INC_278292_SNAKE_MSSFMLSCORESVIEW_H

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Button.h"
#include "Controller.h"
#include "MSSFMLView.h"

// Displayed text
struct DisText {
    int left_offset;
    int top_offset;
    int size;
    std::string string;
};

class MSSFMLScoresView {

    const char* SCORE_FILE = "assets/files/top10scores.txt";
    const int SCORES_OFFSET = 55;
    const int LETTER_WIDTH = 20;

    std::vector<Button> exit_button;
    std::vector<DisText> saving_text;
    DisText text;
    GameFont &font;
    Controller &ctrl;
    MSSFMLView &snake_view;
    int numeration;

public:

    MSSFMLScoresView(GameFont &, Controller &, MSSFMLView &);

    Button getButton() const;

    // Display screen for saving socore
    void displayScoreSaving(std::string, sf::RenderWindow &);

    // Display best 10 scores
    void display(sf::RenderWindow &);

};

#endif