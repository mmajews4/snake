#include "MSSFMLView.h"

#include <iostream>

MSSFMLView::MSSFMLView(SnakeBoard &b, Snake &s) : board(b), snake(s)
{
    window_width = 600, window_height = 600;
    height = board.getHeight();
    width = board.getWidth();
    tile_size = window_width/width;
}


int MSSFMLView::getWindowHeight() const
{
    return window_height;
}

int MSSFMLView::getWindowWidth() const
{
    return window_width;
}


void MSSFMLView::display(sf::RenderWindow &window) const 
{
    // clear the window with black color
    window.clear(sf::Color::Black);
    
    // create rectangle object
    sf::RectangleShape rectangle(sf::Vector2f(tile_size, tile_size));
    rectangle.setFillColor(sf::Color(0, 255, 0));

    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){

            rectangle.setPosition(col*tile_size, row*tile_size);

            switch(snake.isPartOfSnake(col, row)){
                case HEAD:
                    rectangle.setFillColor(sf::Color(0, 155, 0));
                    window.draw(rectangle);
                    continue;
                case BODY:
                    rectangle.setFillColor(sf::Color(0, 255, 0));
                    window.draw(rectangle);
                    continue;
                case TAIL:
                    rectangle.setFillColor(sf::Color(0, 200, 0));
                    window.draw(rectangle);
                    continue;
                case NONE:
                    break;
            }    
            switch(board.getBoardState(col, row)){
                case APPLE:
                    rectangle.setFillColor(sf::Color(255, 0, 0));
                    window.draw(rectangle);
                    break;
                case OBSTICLE:
                    rectangle.setFillColor(sf::Color(100, 100, 100));
                    window.draw(rectangle);
                    break;
                case EMPTY:
                    rectangle.setFillColor(sf::Color(10, 10, 10));
                    window.draw(rectangle);
                    break;
            }
        }
    }
    // Display the content
    window.display();
}