#include "menu.h"

Menu* MenuRef = NULL;

void lan_click_func()
{
    gameState = GS_LanMenu;
}

Menu::Menu(sf::RenderWindow* window)
{
    MenuRef = this;

    this->window = window;

    lan_button.SetWindow(window);
    lan_button.SetFunctionOnClick(&lan_click_func);
    lan_button.setPosition(100, 100);
}

void Menu::Update()
{
    lan_button.Update();
}

void Menu::Render()
{
    window->draw(lan_button.getSprite());
}

void Menu::InitObject()
{

}

void Menu::EndObject()
{

}
