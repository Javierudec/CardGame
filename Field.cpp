#include "Field.h"

Field::Field(sf::RenderWindow* window) {
    this->window = window;

    for(int i = 0; i < 6; i++)
        busy_zone[i] = false;

    unit_zone_position[0][0] = 520; unit_zone_position[0][1] = 480;
    unit_zone_position[1][0] = 790; unit_zone_position[1][1] = 480;
    unit_zone_position[2][0] = 520; unit_zone_position[2][1] = 600;
    unit_zone_position[3][0] = 790; unit_zone_position[3][1] = 600;
    unit_zone_position[4][0] = 658; unit_zone_position[4][1] = 600;
    unit_zone_position[5][0] = 658; unit_zone_position[5][1] = 480;
}

void Field::Render() {
    for(int i = 0; i < 6; i++) {
        if(busy_zone[i]) {
            window->draw(unit_zone[i].getSprite());
        }
    }
}

void Field::Update() {
    for(int i = 0; i < 6; i++) {
        if(busy_zone[i])
            unit_zone[i].Update();
    }
}

void Field::AddCardToZone(Card card, UnitZone zone) {
    unit_zone[(int)zone] = card;
    unit_zone[(int)zone].setPosition(unit_zone_position[(int)zone][0],
                                     unit_zone_position[(int)zone][1]);
    busy_zone[(int)zone] = true;
}
