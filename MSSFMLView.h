#ifndef INC_278292_SNAKE_MSSFMLVIEW_H
#define INC_278292_SNAKE_MSSFMLVIEW_H

#include "SnakeBoard.h"
#include "Snake.h"
#include <SFML/Graphics.hpp>

class MSSFMLView {

    Snake &snake;
    SnakeBoard &board;

    int window_width, window_height;    // In pixels
    int height, width; // in tiles
    int tile_size;
    

public:

    MSSFMLView(SnakeBoard &, Snake &);

    // Simple getters
    int getWindowHeight() const;
    int getWindowWidth() const;

    void display(sf::RenderWindow &) const;

};


#endif //INC_278292_SNAKE_MSSFMLVIEW_H
