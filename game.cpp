#include "game.h"
#include <iostream>
#include <algorithm>
using namespace std;

Game *GameRef = NULL;

void net_func()
{
    GameRef->net.Update();
}

Game::Game(sf::RenderWindow *window)
{
    GameRef = this;
    this->window = window;
    playmat_texture.loadFromFile("data/playmat.png");
    playmat_sprite.setTexture(playmat_texture);
    playmat_sprite.setPosition(380, 10);
    playmat_sprite.setScale(.8, .8);

    deck[0].SetPosition(400, 160);
    deck[0].SetMargin(-0.1, -0.1);
    deck[1].SetPosition(910, 490);
    deck[1].SetMargin(0.1, -0.1);

    deck[1].SetWindow(window);
    deck[1].SetManager(&card_information);
    deck[1].SetField(player_field);
    deck[1].LoadDeck();
    deck[1].Shuffle();

    deck[0].SetWindow(window);
    deck[0].SetManager(&card_information);
    deck[0].LoadDeck();

    player_field = new Field(window);
    enemy_field  = new Field(window);

    current_phase = GP_CHOOSE_VANGUARD;
    deck[1].View();
}

Game::~Game()
{

}

void Game::InitObject()
{
    net.SetServerIP("192.168.2.4");
    net_thrd = new sf::Thread(&net_func);
    net_thrd->launch();
    /*
    cout << "Seleccione un ID" << endl;
    cin >> user_id;
    */
}

void Game::EndObject()
{

}

void Game::Update()
{
    if(net.IsSomePacketWaiting())
    {
        //Deberia pausar el juego hasta que mande la confirmacion
        GamePacket t = net.getPacket();
        if(t.game_action == PUT_ON_VANGUARD)
        {
            Card tc;
            //cout << t.card_id << endl;
            tc.SetCard(t.card_id);
            tc.SetWindow(window);
            tc.SetInfoManager(&card_information);
            player_field->AddCardToZone(tc, VANGUARD);
        }
        net.SendConfirmationToServer();
    }

    deck[1].Update();
    player_field->Update();
    enemy_field->Update();

    if(current_phase == GP_CHOOSE_VANGUARD) {
        if(deck[1].CardIsSelected()) {
           player_field->AddCardToZone(deck[1].GetSelectedCard(), VANGUARD);
           GamePacket aux;
           aux.card_id = deck[1].GetSelectedCard().getID();
           aux.game_action = PUT_ON_VANGUARD;
           net.SendPacket(aux);
           //cout << "Enviando paquete de starter vanguard" << endl;
           deck[1].Close();
        }
    }
}

void Game::Render()
{
    window->draw(playmat_sprite);
    player_field->Render();
    card_information.Render(window);
    deck[0].Render(window);
    deck[1].Render(window);
}
