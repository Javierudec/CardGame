#ifndef _H_INFO_MANAGER_
#define _H_INFO_MANAGER_

#include <SFML/Graphics.hpp>
#include "common.h"

class manager {
public:
    manager();
    void Render(sf::RenderWindow* window);
    void ShowCard(int id);
private:
    sf::Texture CardToShow_texture;
    sf::Sprite  CardToShow_sprite;
    float _x;
    float _y;
};

#endif // _H_INFO_MANAGER_
