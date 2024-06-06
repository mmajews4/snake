#include "MSSFMLScoresView.h"

using namespace std;

MSSFMLScoresView::MSSFMLScoresView(GameFont &f) : font(f)
{
    exit_button.emplace_back(30, 30, 5 ,550 ,20 ,7, 0, 24, "X", false, font);    // width, height, outline, left_ofset, top_ofset, text_left_ofset, text_top_ofset, text_size, text, active
    text = {230, 20, 48, ""};// left_offset, top_offset, size, string
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
    text_view.setFillColor(sf::Color(250, 250, 250));

    if (File.is_open()) {
        // Read contsnts of the file
        for(int score_nr = 0; score_nr < 10; score_nr++) 
        {
            if(getline(File, line)){
                string << score_nr + 1 << ".  " << line;
            } else {
                string << score_nr + 1 << ".  "; // Handle case where less than 10 scores are present
            }
            text_view.setString(string.str());
            string.str(""); 
            // Compenaste for wider than rest nr 10
            if(score_nr < 9)text_view.setPosition(text.left_offset, text.top_offset);
            else text_view.setPosition(text.left_offset - 25, text.top_offset);
            text.top_offset += SCORES_OFFSET;
            window.draw(text_view);
        }
        text.top_offset -= 10*SCORES_OFFSET;

        File.close(); // Close the file when done
    } else {
        cerr << "Unable to open file for reading" << endl;
    }

    // Display exit button
    exit_button[0].display(window);

    // Display current frame
    window.display();
}