#ifndef INC_278292_SNAKE_MSSFMLSCORESCTRL_H
#define INC_278292_SNAKE_MSSFMLSCORESCTRL_H

#include <fstream>
#include <sstream>
#include "MSSFMLScoresView.h"
#include "Controller.h"

class MSSFMLScoresCtrl{

    const uint MAX_NAME_LENGTH = 16;

    MSSFMLScoresView &view;
    Controller &ctrl;
    bool first_display;
    std::string name;

    // Function sanes scores to file
    void saveScoreToFile(std::string);

public:
    MSSFMLScoresCtrl(MSSFMLScoresView &, Controller &);

    // Check if the click coordinates mach button coordinates
    bool inRangeOfButton(int col, int row) const;

    // Allows player to write their name to be displayed near score
    void saveScore(sf::RenderWindow &);

    // Function handles mouse actions and updates menu according to action
    void show(sf::RenderWindow &);
};

#endif //INC_278292_SNAKE_MSSFMLSCORESCTRL_H