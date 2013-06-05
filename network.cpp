#include "network.h"

Network::Network()
{
    port = 50001;
    bPacketWaiting = false;
}

void Network::SetNetworkCondition(Network_Condition cond)
{
    net_cond = cond;
}

void Network::Update()
{
    while(1) {
        // Create a socket to receive a message from anyone
        sf::UdpSocket socket;

        // Listen to messages on the specified port
        if (socket.bind(player_port) != sf::Socket::Done)
            return;
        cout << "Server is listening to port " << port << ", waiting for a message... " << endl;

        // Wait for a message
        GamePacket in;
        size_t received;
        //sf::IpAddress sender;
        //unsigned short senderPort;
        if (socket.receive(&in, sizeof(in), received, sender, senderPort) != sf::Socket::Done)
            return;
        cout << "Message received from client " << endl;

        bPacketWaiting = true;
        lastPacket = in;
    }
}

void Network::SendConfirmationToServer()
{
    sf::UdpSocket socket;
    //Send an answer to the client
    bool out = true;
    if (socket.send(&out, sizeof(out), opponent_ip, opponent_port) != sf::Socket::Done)
        return;
    cout << "Message sent to the client: \"" << endl;
    bPacketWaiting = false;
}

void Network::SendPacket(GamePacket gamePacket)
{
    // Create a socket for communicating with the server
    sf::UdpSocket socket;

    // Send a message to the server

    if (socket.send(&gamePacket, sizeof(gamePacket), opponent_ip, opponent_port) != sf::Socket::Done)
        return;
    cout << "Message sent to the server: \"" << endl;
}
