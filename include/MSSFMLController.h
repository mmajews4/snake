#ifndef INC_278292_SNAKE_MSSFMLCONTROLLER_H
#define INC_278292_SNAKE_MSSFMLCONTROLLER_H

#include "SnakeBoard.h"
#include "Snake.h"
#include "Controller.h"
#include "MSSFMLView.h"

class MSSFMLController {

    SnakeBoard &board;
    Snake &snake;
    Controller &ctrl;
    MSSFMLView &view;

    sf::Time displayInterval;
    sf::Time timeSinceLastDisplay;

    bool dir_changed;

public:
    MSSFMLController(SnakeBoard &, Snake&, Controller&, MSSFMLView &);

    // Function handles keyboard actions and updates board according to action
    void play(sf::RenderWindow &);

};

#endif //INC_278292_SNAKE_MSSFMLCONTROLLER_H
