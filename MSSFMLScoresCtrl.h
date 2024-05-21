#ifndef INC_278292_SNAKE_MSSFMLSCORESCTRL_H
#define INC_278292_SNAKE_MSSFMLSCORESCTRL_H

#include <fstream>
#include "MSSFMLScoresView.h"

class MSSFMLScoresCtrl{

    MSSFMLScoresView &view;

public:
    MSSFMLScoresCtrl(MSSFMLScoresView &);

    // Check if the click coordinates mach button coordinates
    bool inRangeOfButton(int col, int row) const;

    // Function handles mouse actions and updates menu according to action
    void show(sf::RenderWindow &);
};

#endif //INC_278292_SNAKE_MSSFMLSCORESCTRL_H