#include "button.h"

Button::Button()
{
    texture.loadFromFile("data/button.png");
    sprite.setTexture(texture);
    _width = 128;
    _height = 64;

    state_idle    = new sf::IntRect(0,0,128,64);
    state_pressed = new sf::IntRect(0,64,128,64);;
    state_over    = new sf::IntRect(0,128,128,64);

    sprite.setTextureRect(*state_idle);

    bPressed = false;
}

void Button::setPosition(float x, float y)
{
    _x = x;
    _y = y;
    sprite.setPosition(_x, _y);
}

void Button::Update()
{
    sf::Vector2i globalPosition = sf::Mouse::getPosition(*window);

    if(isInside(globalPosition.x, globalPosition.y))
    {
        if(!bOnce)
        {
            sprite.setTextureRect(*state_over);
            bOnce = true;
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            bPressed = true;
            sprite.setTextureRect(*state_pressed);
        }
        else
        {
            if(bPressed)
            {
                func();
                bPressed = false;
            }

            bPressed = false;
        }
    }
    else
    {
        sprite.setTextureRect(*state_idle);
        bOnce = false;
        bPressed = false;
    }

}

bool Button::isInside(int x, int y)
{
    return _x <= x &&
           _y <= y &&
           (_x + _width) >= x &&
           (_y + _height) >= y;
}

void Button::SetFunctionOnClick(void (*func)())
{
    this->func = func;
}
