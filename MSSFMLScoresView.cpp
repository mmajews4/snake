#include "MSSFMLScoresView.h"

using namespace std;

MSSFMLScoresView::MSSFMLScoresView()
{
    exit_button = {30, 30, 5 ,550 ,0 ,0, 6, 30, "X", 0};    // width, height, outline, left_ofset, top_ofset, text_left_ofset, text_top_ofset, text_size, text, active
    text = {195, 100, 50, "Score: "};// left_offset, top_offset, size, string
}


Button MSSFMLScoresView::getButton() const
{
    return exit_button;
}


void MSSFMLScoresView::display(sf::RenderWindow &window)
{
    std::ifstream File("top10scores.txt");
    string line;

    // clear the window with black color
    window.clear(sf::Color::Black);

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
    text_view.setPosition(text.left_offset, text.top_offset);
    text_view.setFillColor(sf::Color(150, 150, 150));

    if (File.is_open()) {
        while (getline(File, line)) {
            cout << line << endl;

            text_view.setString(line);
            text.top_offset += SCORES_OFFSET;
            text_view.setPosition(text.left_offset, text.top_offset);
            window.draw(text_view);
        }
        File.close(); // Always close the file when done
    } else {
        cerr << "Unable to open file for reading" << endl;
    }
    

    // Create button
    sf::RectangleShape button_view(sf::Vector2f(exit_button.width, exit_button.height));
    button_view.setFillColor(sf::Color(220, 220, 220));
    button_view.setOutlineColor(sf::Color(120, 120, 120));
    text_view.setFillColor(sf::Color::Black);
    button_view.setPosition(exit_button.left_offset, exit_button.top_offset);
    button_view.setSize(sf::Vector2f(exit_button.width, exit_button.height));
    button_view.setOutlineThickness(exit_button.outline);
    text_view.setString(exit_button.text);
    text_view.setPosition(exit_button.left_offset + exit_button.text_left_ofset, exit_button.top_offset + exit_button.text_top_ofset);
    text_view.setCharacterSize(exit_button.text_size);
    window.draw(button_view);
    window.draw(text_view);


    // Display current frame
    window.display();
}