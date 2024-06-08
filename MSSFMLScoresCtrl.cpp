#include "MSSFMLScoresCtrl.h"

using namespace std;

MSSFMLScoresCtrl::MSSFMLScoresCtrl(MSSFMLScoresView &v, Controller &c) :view(v), ctrl(c)
{
    first_display = true;
}

// Check if the click coordinates mach button coordinates
bool MSSFMLScoresCtrl::inRangeOfButton(int col, int row) const
{
    Button button = view.getButton();

    if(button.inRangeOfButton(col, row)) return true;

    return false;
}


// Function sanes scores to file
void MSSFMLScoresCtrl::saveScoreToFile(string name)
{
    vector<Score> scoreboard(10);

    ifstream File("top10scores.txt");
    string line;
    int number;
    Score buffer;
    Score current_score;
    current_score.number = ctrl.getScore();
    current_score.name = name;

    if(File.is_open()) {
        // Read contsnts of the file
        for(int score_nr = 0; score_nr < 10; score_nr++) 
        {
            if(getline(File, line)){
                stringstream divided_string(line);

                // Divide line into number and name, skip whitespace(space)
                divided_string >> number;
                getline(divided_string >> ws, scoreboard[score_nr].name); 
                scoreboard[score_nr].number = number;
            } 
            else 
            {
                scoreboard[score_nr].number = 0; // Handle case where less than 10 scores are present
            }
        }

        File.close(); // Close the file when done
    } else {
        cerr << "Unable to open file for reading" << endl;
    }

    // Add current score
    for (int score_nr = 0; score_nr < 10; ++score_nr) {
        if (current_score.number > scoreboard[score_nr].number) {
            buffer.number = scoreboard[score_nr].number;
            buffer.name = scoreboard[score_nr].name;
            scoreboard[score_nr].number = current_score.number;
            scoreboard[score_nr].name = current_score.name;
            current_score.number = buffer.number;
            current_score.name = buffer.name;
        }
    }

    // Reopen the file in output mode to overwrite scoreboard
    std::ofstream outfile("top10scores.txt", std::ios::out | std::ios::trunc);
    if (outfile.is_open()) {
        for (const auto& score : scoreboard) {
            // Save necesairy information to file, compensate for different lenghts of scores 
            if(score.number >= 100)
                outfile << score.number << " " << score.name << "\n";
            else if(score.number >= 10)
                outfile << score.number << "   " << score.name << "\n";
            else 
                outfile << score.number << "     " << score.name << "\n";
        }
        outfile.close(); // Close the file after writing
    } else {
        std::cerr << "Unable to open file for writing" << std::endl;
    }

    ctrl.setGameState(MENU);
}


void MSSFMLScoresCtrl::saveScore(sf::RenderWindow &window)
{
    sf::Event event;

    if(first_display)
    {
        first_display = false;
        name = "";
        view.displayScoreSaving(name, window);
    }

    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed) {
            window.close();
        }
        // Handle text input
        if (event.type == sf::Event::TextEntered) {
            // Handle backspace
            if (event.text.unicode == '\b' && !name.empty()) {
                name.pop_back();
            } else if (event.text.unicode < 128) { // ASCII check
                // Append character
                if(name.size() < MAX_NAME_LENGTH) name += static_cast<char>(event.text.unicode);
            }
            // Update the displayed text
            view.displayScoreSaving(name, window);
        }
        // saving that name
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Enter)
            {
                saveScoreToFile(name);
                first_display = true;
                ctrl.setGameState(MENU);
            }
        }
    }

}


// Function handles mouse actions and updates menu according to action
void MSSFMLScoresCtrl::show(sf::RenderWindow &window)
{
    sf::Event event;

    if(first_display)
    {
        first_display = false;
        view.display(window);
    }

    while(window.pollEvent(event))
    {
        // If asked close window
        if(event.type == sf::Event::Closed) {
            window.close();
        }
        else if(event.type == sf::Event::MouseButtonPressed)
        {
            if(inRangeOfButton(event.mouseButton.x, event.mouseButton.y))
            {
                // At exit clear te screan and set socore window to starting state
                window.clear(sf::Color::Black);
                first_display = true;
                ctrl.setGameState(MENU);
                return;
            }

            // Update window
            view.display(window);
        }
    }
}
