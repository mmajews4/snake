#include "MSSFMLView.h"

#include <iostream>

using namespace std;

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


void MSSFMLView::importTextures()
{
    sf::Texture head_texture;
    sf::Texture straight_body_texture;
    sf::Texture turn_body_texture;
    sf::Texture tail_texture;
    sf::Texture apple_texture;
    sf::Texture obsticle_texture;
    sf::Texture background_texture;

    if (!head_texture.loadFromFile("textures/snake_head.png")) {
        cerr << "Unable to load head texture" << endl;
        return;
    }
    if (!straight_body_texture.loadFromFile("textures/snake_body_straight.png")) {
        cerr << "Unable to load straight body texture" << endl;
        return;
    }
    if (!turn_body_texture.loadFromFile("textures/snake_body_right.png")) {
        cerr << "Unable to load turn body texture" << endl;
        return;
    }
    if (!tail_texture.loadFromFile("textures/snake_tail.png")) {
        cerr << "Unable to load tail texture" << endl;
        return;
    }
    if (!apple_texture.loadFromFile("textures/snake_apple,png")) {
        cerr << "Unable to load apple texture" << endl;
        return;
    }
    if (!obsticle_texture.loadFromFile("textures/snake_obsticle.png")) {
        cerr << "Unable to load obsticle texture" << endl;
        return;
    }
    if (!background_texture.loadFromFile("textures/snake_board.png")) {
        cerr << "Unable to load background texture" << endl;
        return;
    }
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
                    //rectangle.setFillColor(sf::Color(0, 155, 0));
                    rectangle.setTexture(&head_texture);
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
                    rectangle.setFillColor(sf::Color(50, 50, 50));
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