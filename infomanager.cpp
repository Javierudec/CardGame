
#include "infomanager.h"

manager::manager()
{
    CardToShow_texture.loadFromFile("data/cards/back.jpg");
    CardToShow_sprite.setTexture(CardToShow_texture);
    CardToShow_sprite.setScale(0.7, 0.7);
    _x = 10;
    _y = 10;
    CardToShow_sprite.setPosition(_x, _y);
}

void manager::Render(sf::RenderWindow* window)
{
    window->draw(CardToShow_sprite);
}

void manager::ShowCard(int id)
{
    CardToShow_texture.loadFromFile(texture_list[id]);
    CardToShow_sprite.setTexture(CardToShow_texture);
}
