#include "Button.h"

Button::Button(int width_,
        int height_,
        int outline_,
        int left_offset_,
        int top_offset_,
        int text_left_offset_,
        int text_top_offset_, 
        int text_size_,
        std::string text_,
        bool active_,
        GameFont &f) : font(f)
{
    width = width_;
    height = height_;
    outline = outline_;
    left_offset = left_offset_;
    top_offset = top_offset_;
    text_left_offset = text_left_offset_;
    text_top_offset = text_top_offset_;
    text_size = text_size_;
    text = text_;
    active = active_;
}



// checks if click cooridinates are on button
bool Button::inRangeOfButton(int col, int row) const
{
    if(col >= left_offset && col < left_offset + width
    && row >= top_offset  && row < top_offset + height) return true;

    return false;
}


bool Button::isActive() const
{
    return active;
}

void Button::setActive(bool active_status)
{
    active = active_status;
}

// Display button on screen
void Button::display(sf::RenderWindow &window)
{
    
    // Create a text object
    sf::Text text_view;
    text_view.setFont(font.font);
    text_view.setStyle(sf::Text::Bold);
    text_view.setFillColor(sf::Color(0, 0, 0));
    text_view.setCharacterSize(text_size);
    text_view.setString(text);
    text_view.setPosition(left_offset + text_left_offset, top_offset + text_top_offset);

    // Create buttons
    sf::RectangleShape button_view(sf::Vector2f(width, height));
    if(active) button_view.setFillColor(sf::Color(120, 120, 120));
    else button_view.setFillColor(sf::Color(180, 180, 180));
    button_view.setOutlineColor(sf::Color(120, 120, 120));
    button_view.setOutlineThickness(outline);
    button_view.setPosition(left_offset, top_offset);

    window.draw(button_view);
    window.draw(text_view);
}