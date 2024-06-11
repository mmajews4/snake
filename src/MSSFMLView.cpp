#include "MSSFMLView.h"

#include <iostream>

using namespace std;

MSSFMLView::MSSFMLView(SnakeBoard &b, Snake &s) : board(b), snake(s)
{
    window_width = 600, window_height = 600;
    height = board.getHeight();
    width = board.getWidth();
    tile_size = window_width/width;
    importTextures();
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
    if (!head_texture.loadFromFile("assets/textures/snake_head.png")) {
        cerr << "Unable to load head texture" << endl;
        return;
    }
    if (!straight_body_texture.loadFromFile("assets/textures/snake_body_straight.png")) {
        cerr << "Unable to load straight body texture" << endl;
        return;
    }
    if (!turn_body_texture.loadFromFile("assets/textures/snake_body_right.png")) {
        cerr << "Unable to load turn body texture" << endl;
        return;
    }
    if (!tail_texture.loadFromFile("assets/textures/snake_tail.png")) {
        cerr << "Unable to load tail texture" << endl;
        return;
    }
    if (!apple_texture.loadFromFile("assets/textures/snake_apple.png")) {
        cerr << "Unable to load apple texture" << endl;
        return;
    }
    if (!obsticle_texture.loadFromFile("assets/textures/snake_obsticle.png")) {
        cerr << "Unable to load obsticle texture" << endl;
        return;
    }
    if (!board_texture.loadFromFile("assets/textures/snake_board2.png")) {
        cerr << "Unable to load background texture" << endl;
        return;
    }
    if (!background_texture.loadFromFile("assets/textures/snake_board.png")) {
        cerr << "Unable to load background texture" << endl;
        return;
    }
}


void MSSFMLView::displayBackground(sf::RenderWindow &window) const 
{
    // create background
    sf::RectangleShape background(sf::Vector2f(window_width, window_height));
    background.setPosition(0,0);
    background.setTexture(&background_texture);
    window.draw(background);
}


void MSSFMLView::display(sf::RenderWindow &window) const 
{
    // create board
    sf::RectangleShape board_view(sf::Vector2f(window_width, window_height));
    board_view.setPosition(0,0);
    board_view.setTexture(&board_texture);
    window.draw(board_view);
    
    // create rectangle object
    sf::RectangleShape rectangle(sf::Vector2f(tile_size, tile_size));
    // change tile origin for easier rotation
    rectangle.setOrigin(tile_size/2, tile_size/2);

    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){

            rectangle.setPosition(col*tile_size + (tile_size/2), row*tile_size + (tile_size/2));
            
            switch(board.getBoardState(col, row)){
                case APPLE:
                    rectangle.setTexture(&apple_texture);
                    window.draw(rectangle);
                    break;
                case OBSTICLE:
                    rectangle.setTexture(&obsticle_texture);
                    window.draw(rectangle);
                    break;
                case EMPTY:
                    break;
            }
        }
    }

    list<SnakeTile> snake_tile = snake.getSnake();
    Direction prev_direction = UP;

    for(const auto& tile: snake_tile)
    {
        rectangle.setPosition(tile.col*tile_size + (tile_size/2), tile.row*tile_size + (tile_size/2));

        switch(tile.part){
            case HEAD:
                rectangle.setTexture(&head_texture);
                if     (tile.direction == LEFT) rectangle.setRotation(0.0f);
                else if(tile.direction == UP)   rectangle.setRotation(90.0f);
                else if(tile.direction == RIGHT)rectangle.setRotation(180.0f);
                else if(tile.direction == DOWN) rectangle.setRotation(270.0f);
                break;
            case BODY:
                if(prev_direction == tile.direction)
                {
                    rectangle.setTexture(&straight_body_texture);
                    if     (tile.direction == LEFT) rectangle.setRotation(0.0f);
                    else if(tile.direction == DOWN) rectangle.setRotation(90.0f);
                    else if(tile.direction == RIGHT)rectangle.setRotation(180.0f);
                    else if(tile.direction == UP)   rectangle.setRotation(270.0f);
                } 
                else
                {
                    rectangle.setTexture(&turn_body_texture);
                    if     ((prev_direction == RIGHT && tile.direction == DOWN ) 
                          ||(prev_direction == UP    && tile.direction == LEFT )) rectangle.setRotation(0.0f);
                    else if((prev_direction == LEFT  && tile.direction == DOWN )
                          ||(prev_direction == UP    && tile.direction == RIGHT)) rectangle.setRotation(270.0f);
                    else if((prev_direction == LEFT  && tile.direction == UP   )
                          ||(prev_direction == DOWN  && tile.direction == RIGHT)) rectangle.setRotation(180.0f);
                    else if((prev_direction == DOWN  && tile.direction == LEFT )
                          ||(prev_direction == RIGHT && tile.direction == UP   )) rectangle.setRotation(90.0f);
                }
                break;
            case TAIL:
                rectangle.setTexture(&tail_texture);
                if     (prev_direction == LEFT) rectangle.setRotation(180.0f);
                else if(prev_direction == DOWN) rectangle.setRotation(90.0f);
                else if(prev_direction == RIGHT)rectangle.setRotation(0.0f);
                else if(prev_direction == UP)   rectangle.setRotation(270.0f);
                break;
            case NONE:
                break;
        }
        prev_direction = tile.direction;
        window.draw(rectangle);
    }

    // Display the content
    window.display();
}