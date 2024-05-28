#include "MSSFMLScoresView.h"

using namespace std;

MSSFMLScoresView::MSSFMLScoresView(GameFont &f) : font(f)
{
    exit_button.emplace_back(30, 30, 5 ,550 ,20 ,7, 0, 24, "X", false, font);    // width, height, outline, left_ofset, top_ofset, text_left_ofset, text_top_ofset, text_size, text, active
    text = {150, 50, 30, ""};// left_offset, top_offset, size, string
    numeration = 1;
}


Button MSSFMLScoresView::getButton() const
{
    return exit_button[0];
}


void MSSFMLScoresView::display(sf::RenderWindow &window)
{
    std::ifstream File("top10scores.txt");
    string line;
    stringstream string;

    // clear the window with black color
    window.clear(sf::Color::Black);

    // Create a text object
    sf::Text text_view;
    text_view.setFont(font.font);
    text_view.setStyle(sf::Text::Bold);
    text_view.setCharacterSize(text.size);
    text_view.setPosition(text.left_offset, text.top_offset);
    text_view.setFillColor(sf::Color(150, 150, 150));

    if (File.is_open()) {
        while (getline(File, line)) 
        {
            string << numeration << ". " << line;
            text_view.setString(string.str());
            string.str(""); 
            text.top_offset += SCORES_OFFSET;
            text_view.setPosition(text.left_offset, text.top_offset);
            window.draw(text_view);
            numeration++;
        }
        File.close(); // Always close the file when done
    } else {
        cerr << "Unable to open file for reading" << endl;
    }
    numeration = 1;

    // Display exit button
    exit_button[0].display(window);

    // Display current frame
    window.display();
}