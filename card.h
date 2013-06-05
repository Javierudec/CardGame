#ifndef _H_CARD_
#define _H_CARD_

#include <SFML/Graphics.hpp>
#include "common.h"
#include "infomanager.h"
#include <iostream>
using namespace std;

class Card {
public:
    Card();
    sf::Sprite getSprite();
    void SetCard(int id);
    bool Update();
    void SetWindow(sf::RenderWindow* window) { this->window = window; };
    void SetInfoManager(manager* info);
    int getID() { return id; };
    void setPosition(float x, float y);
private:
    sf::Texture texture;
    sf::Sprite  sprite;
    manager* info;
    bool isInside(int x, int y);
    bool bOnce;
    int id;
    float _width;
    float _height;
    int _x;
    int _y;
    sf::RenderWindow* window;
};

#endif // _H_CARD_
