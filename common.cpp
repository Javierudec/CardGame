#include "common.h"

GameState gameState = GS_None;
GameState lastGameState = GS_None;

int user_id = 0;
sf::IpAddress opponent_ip;
int opponent_port = 50001;
int player_port = 50001;

string texture_list[] = {"data/cards/card_001.jpg",
                         "data/cards/card_002.jpg",
                         "data/cards/card_003.jpg",
                         "data/cards/card_004.jpg",
                         "data/cards/card_005.jpg",
                         "data/cards/card_006.jpg",
                         "data/cards/card_007.jpg",
                         "data/cards/card_008.jpg",
                         "data/cards/card_009.jpg",
                         "data/cards/card_010.jpg",
                         "data/cards/card_011.jpg",
                         "data/cards/card_012.jpg",
                         "data/cards/card_013.jpg",
                         "data/cards/card_014.jpg",
                         "data/cards/card_015.jpg",
                         "data/cards/card_016.jpg",
                         "data/cards/card_017.jpg",
                         "data/cards/card_018.jpg"};
