#ifndef INC_278292_SNAKE_MSSFMLSCORESCTRL_H
#define INC_278292_SNAKE_MSSFMLSCORESCTRL_H

#include <fstream>
#include "MSSFMLScoresView.h"
#include "Controller.h"

class MSSFMLScoresCtrl{

    MSSFMLScoresView &view;
    Controller &ctrl;
    bool first_display;

public:
    MSSFMLScoresCtrl(MSSFMLScoresView &, Controller &);

    // Check if the click coordinates mach button coordinates
    bool inRangeOfButton(int col, int row) const;

    // Function sanes scores to file
    void saveScoresToFile();

    // Function handles mouse actions and updates menu according to action
    void show(sf::RenderWindow &);
};

#endif //INC_278292_SNAKE_MSSFMLSCORESCTRL_H