#include "MSSFMLMenuView.h"

using namespace std;

MSSFMLMenuView::MSSFMLMenuView(Controller &c, MSSFMLView &sv) : ctrl(c), snake_view(sv)
{
    buttons[0] = {112, 50, 5 ,100 ,200 ,15, 6, 30, "EASY"};    // width, height, outline, left_ofset, top_ofset, text_left_ofset, text_top_ofset, text_size, text
    buttons[1] = {136, 50, 5 ,232 ,200 , 2, 6, 30, "NORMAL"}; 
    buttons[2] = {112, 50, 5 ,388 ,200 ,13, 6, 30, "HARD"};
    buttons[3] = {400, 50, 5 ,100 ,270 ,162, 6, 30, "PLAY"}; 
    buttons[4] = {400, 50, 5 ,100 ,340 ,137, 6, 30, "SCORES"}; 
    buttons[5] = {400, 50, 5 ,100 ,410 ,35, 6, 30, "DOWNLOAD SCORES"};
    text = {195, 100, 50, "Score: "};// left_offset, top_offset, size, string
}


void MSSFMLMenuView::display(sf::RenderWindow &window)
{
    // Load the font
    sf::Font font;
 //   if (!font.loadFromFile("../arial.ttf")) {
        if (!font.loadFromFile("arial.ttf")) {
            std::cerr << "Failed to load font." << std::endl;
            exit(EXIT_FAILURE);
        }
//    }

    // Create a text object
    sf::Text text_view;
    text_view.setFont(font);
    text_view.setStyle(sf::Text::Bold);
    text_view.setCharacterSize(text.size);
    text_view.setFillColor(sf::Color(200, 200, 200));


    // clear the window with black color
//    window.clear(sf::Color::Black);

    text.string = "Score: " + to_string(ctrl.getScore());
    text_view.setString(text.string);
    text_view.setPosition(text.left_offset, text.top_offset);
    text_view.setFillColor(sf::Color(100, 100, 100));
    window.draw(text_view);

    // Create buttons
    sf::RectangleShape button_view(sf::Vector2f(buttons[0].width, buttons[0].height));
    button_view.setFillColor(sf::Color(220, 220, 220));
    button_view.setOutlineColor(sf::Color(120, 120, 120));
    text_view.setFillColor(sf::Color(0, 0, 0));

    for(const auto& button: buttons)
    {
        button_view.setPosition(button.left_offset, button.top_offset);
        button_view.setSize(sf::Vector2f(button.width, button.height));
        button_view.setOutlineThickness(button.outline);
        text_view.setString(button.text);
        text_view.setPosition(button.left_offset + button.text_left_ofset, button.top_offset + button.text_top_ofset);
        text_view.setCharacterSize(button.text_size);
        window.draw(button_view);
        window.draw(text_view);
    }

    // Display current frame
    window.display();
}