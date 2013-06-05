#ifndef _H_MENU_
#define _H_MENU_

#include <SFML/Graphics.hpp>
#include "button.h"

class Menu {
public:
    Menu(sf::RenderWindow* window);
    void Update();
    void Render();
    void InitObject();
    void EndObject();

private:
    sf::RenderWindow* window;
    Button lan_button;
};

#endif // _H_MENU_
