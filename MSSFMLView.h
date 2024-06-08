#ifndef INC_278292_SNAKE_MSSFMLVIEW_H
#define INC_278292_SNAKE_MSSFMLVIEW_H

#include "SnakeBoard.h"
#include "Snake.h"
#include <SFML/Graphics.hpp>

class MSSFMLView {

    SnakeBoard &board;
    Snake &snake;

    sf::Texture head_texture;
    sf::Texture straight_body_texture;
    sf::Texture turn_body_texture;
    sf::Texture tail_texture;
    sf::Texture apple_texture;
    sf::Texture obsticle_texture;
    sf::Texture background_texture;

    int window_width, window_height;    // In pixels
    int height, width; // in tiles
    int tile_size;

    void importTextures();

public:

    MSSFMLView(SnakeBoard &, Snake &);

    // Simple getters
    int getWindowHeight() const;
    int getWindowWidth() const;

    void display(sf::RenderWindow &) const;

};


#endif //INC_278292_SNAKE_MSSFMLVIEW_H
