#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

#include "common.h"
#include "game.h"
#include "lan_mode.h"
#include "menu.h"

using namespace std;

#define FPS 30

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 640), "Cardfight Vanguard! Ver1.0");
    sf::Clock clock;

    Menu* menu = new Menu(&window);
    LanModeWindow* lanmode = new LanModeWindow(&window);
    Game* game = new Game(&window);

    gameState = GS_Menu;
    while(window.isOpen())
    {
        //game logic
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(gameState != lastGameState)
        {
            if(lastGameState == GS_Game) game->EndObject();
            else if(lastGameState == GS_Menu) menu->EndObject();
            else if(lastGameState == GS_LanMenu) lanmode->EndObject();

            if(gameState == GS_Game) game->InitObject();
            else if(gameState == GS_Menu) menu->InitObject();
            else if(gameState == GS_LanMenu) lanmode->InitObject();

            lastGameState = gameState;
        }

        if(gameState == GS_Game) game->Update();
        else if(gameState == GS_LanMenu) lanmode->Update();
        else if(gameState == GS_Menu) menu->Update();

        window.clear();
        //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        if(gameState == GS_Game) game->Render();
        else if(gameState == GS_Menu) menu->Render();
        else if(gameState == GS_LanMenu) lanmode->Render();

        window.display();

        //FPS handling
        sf::Time elapsed = clock.getElapsedTime();
        if(elapsed.asSeconds() < (1.0f / FPS))
        {
            sf::Time sleep_time = sf::seconds(1.0/FPS - elapsed.asSeconds());
            sf::sleep(sleep_time);
            clock.restart();
        }

    }

    return 0;
}
