#ifndef _H_CARDINFOMANAGER_
#define _H_CARDINFOMANAGER_

#include <SFML/Graphics.hpp>
#include "common.h"
#include "card.h"

class CardInfoManager {
public:
    CardInfoManager();
    void Render(sf::RenderWindow* window);
    void ShowCard(int id);
private:
    sf::Texture CardToShow_texture;
    sf::Sprite  CardToShow_sprite;
    float _x;
    float _y;
};

#endif // _H_CARDINFOMANAGER_
