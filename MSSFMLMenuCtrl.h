#ifndef INC_278292_SNAKE_MSSFMLMENUCTRL_H
#define INC_278292_SNAKE_MSSFMLMENUCTRL_H

#include "Controller.h"
#include "MSSFMLMenuView.h"

class MSSFMLMenuCtrl{

    Controller &ctrl;
    MSSFMLMenuView &view;

    bool first_display;


    ButtonFunction inRangeOfButton(int col, int row) const;

    void buttonAction(int col, int row);

public:
    MSSFMLMenuCtrl(Controller&, MSSFMLMenuView &);

    // Function handles mouse actions and updates menu according to action
    void show(sf::RenderWindow &);
};

#endif //INC_278292_SNAKE_MSSFMLMENUCTRL_H