#include "CardInfoManager.h"

CardInfoManager::CardInfoManager()
{
    CardToShow_texture.loadFromFile("data/cards/back.jpg");
    CardToShow_sprite.setTexture(CardToShow_texture);
    _x = 0;
    _y = 0;
}

void CardInfoManager::Render(sf::RenderWindow* window)
{
    window->draw(CardToShow_sprite);
}

void CardInfoManager::ShowCard(int id)
{
    CardToShow_texture.loadFromFile(texture_list[id]);
    CardToShow_sprite.setTexture(CardToShow_texture);
}
