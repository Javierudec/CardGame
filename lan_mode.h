#ifndef _LAN_H
#define _LAN_H

#include <SFML/Graphics.hpp>
#include "button.h"
#include "TextField.h"
#include <iostream>
#include <SFML/Network.hpp>
using namespace std;

class LanModeWindow {
public:
    LanModeWindow(sf::RenderWindow* window);
    void Update();
    void Render();
    void InitObject();
    void EndObject();

    void SetHost();
    void SetGuest();

private:
    sf::RenderWindow* window;
    Button host_button;
    Button guest_button;
    TextField host_ip_textfield;
    sf::Thread* thread;
};

#endif // _LAN_H
