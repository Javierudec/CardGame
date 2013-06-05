#ifndef _NETWORK_H
#define _NETWORK_H

#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include "common.h"
#include <iostream>
using namespace std;

class Network {
public:
    Network();

    //Logic
    void Update();
    void SendPacket(GamePacket gamePacket);

    //Setters
    void SetNetworkCondition(Network_Condition cond);
    void SetServerIP(sf::IpAddress server)           { this->server = server; };

    bool IsSomePacketWaiting() { return bPacketWaiting; };
    GamePacket getPacket() { return lastPacket; };
    void SendConfirmationToServer();

private:
    Network_Condition net_cond;
    sf::IpAddress server;
    sf::IpAddress sender;
    unsigned short senderPort;
    int port;

    GamePacket lastPacket;
    bool bPacketWaiting;

};

#endif // _NETWORK_H
