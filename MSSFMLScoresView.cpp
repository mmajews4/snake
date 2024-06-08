#include "MSSFMLScoresView.h"

using namespace std;

MSSFMLScoresView::MSSFMLScoresView(GameFont &f, Controller &c) : font(f), ctrl(c)
{
    saving_text.emplace_back(DisText{195, 100, 50, ""});// left_offset, top_offset, size, string
    saving_text.emplace_back(DisText{150, 200, 40, "Type your name:"});
    saving_text.emplace_back(DisText{300, 300, 40, ""});

    exit_button.emplace_back(30, 30, 5 ,550 ,20 ,7, 0, 24, "X", false, font);    // width, height, outline, left_ofset, top_ofset, text_left_ofset, text_top_ofset, text_size, text, active
    text = {50, 20, 48, ""};

    numeration = 1;
}


Button MSSFMLScoresView::getButton() const
{
    return exit_button[0];
}


// Display screen for saving socore
void MSSFMLScoresView::displayScoreSaving(string name, sf::RenderWindow &window)
{
    // clear the window with black color
    window.clear(sf::Color::Black);

    // Create a text object
    sf::Text text_view;
    text_view.setFont(font.font);
    text_view.setStyle(sf::Text::Bold);
    text_view.setFillColor(sf::Color(250, 250, 250));

    saving_text[0].string = "Score: " + to_string(ctrl.getScore());
    saving_text[2].string = name;
    saving_text[2].left_offset = 300 - (name.size()*LETTER_WIDTH/2);

    for(int iterator = 0; iterator < 3; iterator++)
    {
        text_view.setCharacterSize(saving_text[iterator].size);
        text_view.setPosition(saving_text[iterator].left_offset, saving_text[iterator].top_offset);
        text_view.setString(saving_text[iterator].string);
        window.draw(text_view);
    }

    // Display current frame
    window.display();
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
            else text_view.setPosition(text.left_offset - 27, text.top_offset);
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
