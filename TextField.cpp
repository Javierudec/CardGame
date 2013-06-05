#include "TextField.h"

TextField::TextField()
{
    rectangle = new sf::RectangleShape(sf::Vector2f(120, 20));
    rectangle->setPosition(0, 0);
    _x = 0;
    _y = 0;

    font.loadFromFile("data/arial.ttf");
    text_str = "192.168.2.4";
    text.setFont(font);
    text.setString(text_str);
    text.setCharacterSize(16); // in pixels, not points!
    // set the color
    text.setColor(sf::Color::Black);
    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text_margin_x = 1;
    text_margin_y = 1;
    text.setPosition(_x + text_margin_x, _y + text_margin_y);

    write_once = true;
}

void TextField::setPosition(float x, float y)
{
    _x = x;
    _y = y;
    rectangle->setPosition(_x, _y);
    text.setPosition(_x + text_margin_x, _y + text_margin_y);
}

void TextField::draw(sf::RenderWindow* window)
{
    window->draw(*rectangle);
    window->draw(text);
}

void TextField::Update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) aux_write_text("0");
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) aux_write_text("1");
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) aux_write_text("2");
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) aux_write_text("3");
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) aux_write_text("4");
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) aux_write_text("5");
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) aux_write_text("6");
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) aux_write_text("7");
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) aux_write_text("8");
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) aux_write_text("9");
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Period)) aux_write_text(".");
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
    {
        if(write_once)
        {
            if(text_str.size() > 0)
            {
                text_str = text_str.substr(0, text_str.size() - 1);
                text.setString(text_str);
            }
            write_once = false;
        }
    }
    else write_once = true;
}

void TextField::aux_write_text(string c)
{
    if(write_once) {
        text_str += c;
        text.setString(text_str);
        write_once = false;
    }
}
