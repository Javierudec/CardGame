#ifndef _COMMON_H_
#define _COMMON_H_

#include <string>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>

using namespace std;

#define TOTAL_CARDS 1
#define MAX_PLAYERS 2
#define MAX_CARDS 50

typedef enum {
    GS_None,
    GS_Game,
    GS_Menu,
    GS_LanMenu,
} GameState;

typedef enum {
    GP_CHOOSE_VANGUARD,
} GAME_PHASE;

typedef enum {
    Net_Server,
    Net_Client,
} Network_Condition;

typedef enum {
    PUT_ON_VANGUARD,
} Game_Action;

struct GamePacket {
    int user_id;
    int card_id;
    Game_Action game_action;
};

extern GameState gameState;
extern GameState lastGameState;

extern int user_id;
extern sf::IpAddress opponent_ip;
extern int opponent_port;
extern int player_port;

extern string texture_list[];

#endif // _COMMON_H_
