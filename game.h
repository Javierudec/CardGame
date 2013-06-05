#ifndef _H_GAME_
#define _H_GAME_H

#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include "common.h"
#include "card.h"
#include "deck.h"
#include "CardInfoManager.h"
#include "Field.h"
#include "network.h"

class Game {
public:
    Game(sf::RenderWindow* window);
    ~Game();
    void InitObject();
    void EndObject();
    void Update();
    void Render();

    Network net;

private:
    sf::RenderWindow* window;
    sf::Texture       playmat_texture;
    sf::Sprite        playmat_sprite;
    Deck              deck[MAX_PLAYERS];
    manager card_information;
    Card test;
    Card test2;
    Field* player_field;
    Field* enemy_field;
    GAME_PHASE current_phase;


    sf::Thread* net_thrd;
};

#endif // _H_GAME_
