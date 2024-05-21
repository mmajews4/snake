#ifndef INC_278292_SNAKE_MSSFMLSCORESVIEW_H
#define INC_278292_SNAKE_MSSFMLSCORESVIEW_H

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
/*
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
    bool active;
};

// Displayed text
struct DispText {
    int left_offset;
    int top_offset;
    int size;
    std::string string;
};*/

class MSSFMLScoresView {

    const int SCORES_OFFSET = 50;

    Button exit_button;
    DispText text;

public:
    MSSFMLScoresView();

    Button getButton() const;

    // Display best 10 scores
    void display(sf::RenderWindow &);

};

#endif