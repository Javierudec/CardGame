#include "lan_mode.h"

LanModeWindow* LanRef = NULL;

void guest_onclick()
{
    LanRef->SetGuest();
}

void host_onclick()
{
    LanRef->SetHost();
}

void host_waiting()
{
    cout << "Waiting for a player..." << std::endl;
    // Create a socket to receive a message from anyone
    sf::UdpSocket socket;

    // Listen to messages on the specified port
    if (socket.bind(player_port) != sf::Socket::Done)
         return;
    cout << "Server is listening to port " << 0 << ", waiting for a message... " << endl;

    // Wait for a message
    bool in;
    size_t received;
    sf::IpAddress sender;
    unsigned short senderPort;
    if (socket.receive(&in, sizeof(in), received, sender, senderPort) != sf::Socket::Done)
        return;
    cout << "Confirmation received. " << senderPort << endl;
    opponent_ip = sender;
    //opponent_port = senderPort;
    bool out = true;
    if (socket.send(&out, sizeof(out), opponent_ip, opponent_port) != sf::Socket::Done)
        return;
    cout << "Message sent to the client: \"" << endl;
    gameState = GS_Game;
}

LanModeWindow::LanModeWindow(sf::RenderWindow* window)
{
    LanRef = this;
    this->window = window;

    host_button.SetWindow(window);
    host_button.setPosition(100, 100);
    host_button.SetFunctionOnClick(&host_onclick);
    guest_button.SetWindow(window);
    guest_button.setPosition(200, 200);
    guest_button.SetFunctionOnClick(&guest_onclick);
}

void LanModeWindow::Update()
{
    host_button.Update();
    guest_button.Update();
    host_ip_textfield.Update();
}

void LanModeWindow::Render()
{
    window->draw(host_button.getSprite());
    window->draw(guest_button.getSprite());
    host_ip_textfield.draw(window);
}

void LanModeWindow::InitObject()
{

}

void LanModeWindow::EndObject()
{

}

void LanModeWindow::SetHost()
{
    player_port = 8008;
    opponent_port = 8008;

    thread = new sf::Thread(&host_waiting);
    thread->launch();
}

void LanModeWindow::SetGuest()
{

    player_port = 8008;
    opponent_port = 8008;

    //player_port = 50001;
    //opponent_port = 50001;
    opponent_ip = host_ip_textfield.getText();
    sf::UdpSocket socket;
    thread = new sf::Thread(&host_waiting);
    thread->launch();
    //Send an answer to the client
    bool out = true;
    if (socket.send(&out, sizeof(out), opponent_ip, opponent_port) != sf::Socket::Done)
        return;
    cout << "Message sent to the client: \"" << endl;

}
