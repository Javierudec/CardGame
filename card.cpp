#include "card.h"

Card::Card()
{
    bOnce = false;
    info = NULL;
}

void Card::SetCard(int id)
{
    this->id = id;
    texture.loadFromFile(texture_list[id]);
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(0.3f, 0.3));
    _width = sprite.getTextureRect().width * 0.3f;
    _height = sprite.getTextureRect().height * 0.3f;
}

void Card::SetInfoManager(manager* info)
{
    this->info = info;
}

sf::Sprite Card::getSprite()
{
    return sprite;
}

bool Card::Update()
{
    sf::Vector2i globalPosition = sf::Mouse::getPosition(*window);

    if(isInside(globalPosition.x, globalPosition.y))
    {
        if(!bOnce)
        {
            if(info != NULL) info->ShowCard(getID());
            bOnce = true;
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            return true;
        }
    }
    else
    {
        bOnce = false;
    }

    return false;
}

bool Card::isInside(int x, int y)
{
    return _x <= x &&
           _y <= y &&
           (_x + _width) >= x &&
           (_y + _height) >= y;
}

void Card::setPosition(float x, float y)
{
    _x = x;
    _y = y;
    sprite.setPosition(x, y);
}
