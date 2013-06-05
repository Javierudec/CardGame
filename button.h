#ifndef _H_BUTTON_
#define _H_BUTTON_

#include <SFML/Graphics.hpp>
#include "common.h"

class Button {
public:
    Button();
    void setPosition(float x, float y);
    void Update();
    sf::Sprite getSprite() { return sprite; };
    void SetWindow(sf::RenderWindow* window) { this->window = window; };
    void SetFunctionOnClick(void (*func)());

private:
    sf::Texture       texture;
    sf::Sprite        sprite;
    float _x;
    float _y;
    sf::IntRect* state_idle;
    sf::IntRect* state_pressed;
    sf::IntRect* state_over;
    bool isInside(int x, int y);
    bool bOnce;
    bool bPressed;
    sf::RenderWindow* window;
    float _width;
    float _height;
    void (*func)();
};

#endif // _H_BUTTON_
