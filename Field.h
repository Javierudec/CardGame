#ifndef _H_FIELD_
#define _H_FIELD_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include "Card.h"

typedef enum {
    FRONT_REAR_LEFT,
    FRONT_REAR_RIGHT,
    BACK_REAR_LEFT,
    BACK_REAR_RIGHT,
    BACK_REAR_MIDDLE,
    VANGUARD,
} UnitZone;

class Field {
public:
    Field(sf::RenderWindow* window);
    void Render();
    void Update();
    void AddCardToZone(Card card, UnitZone zone);

private:
    sf::RenderWindow* window;
    Card unit_zone[6];
    bool busy_zone[6];
    float unit_zone_position[6][2];
};

#endif // _H_FIELD_
