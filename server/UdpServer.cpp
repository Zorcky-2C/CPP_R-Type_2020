/*
** EPITECH PROJECT, 2023
** B_CPP_501_BDX_5_1_rtype_philippe_jacques_tatel
** File description:
** Created by valentinbreiz,
*/

#include <iostream>
#include "UdpServer.hpp"
#include "Game.hpp"

UdpServer::UdpServer(boost::asio::io_service& io_service, Game *game) : _socket(io_service, boost::asio::ip::udp::endpoint
(boost::asio::ip::udp::v4(), 4444)), _game(game)
{
    std::cout << "Running UDP Server at 127.0.0.1:" << 4444 << std::endl;
    startReceive();
}

void UdpServer::startReceive()
{
    _socket.async_receive_from(boost::asio::buffer(_data, _max_length), _remote_endpoint,boost::bind
    (&UdpServer::handleReceive, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void UdpServer::handleReceive(const boost::system::error_code& error, std::size_t)
{
    if (!error || error == boost::asio::error::message_size) {
        if (std::string(_data) == "CLIENT OK") {
            addClient(_remote_endpoint);
        }
        else {
            _game->handleReceive(_data, _remote_endpoint);
        }
        memset(_data, 0, _max_length);
    }
    else {
        std::cout << "Error hanleReceive" << std::endl;
    }
    startReceive();
}

void UdpServer::handleSend(boost::shared_ptr<std::string>, const boost::system::error_code& error, std::size_t)
{
    if (!error) {

    }
    else {
        std::cout << "Error: " << error.message() << "\n";
    }
    startReceive();
}

void UdpServer::send(std::string str, boost::asio::ip::udp::endpoint endpoint)
{
    //std::cout << "Sending:" << str << std::endl;
    boost::shared_ptr<std::string> message(new std::string(str));
    _socket.async_send_to(boost::asio::buffer(*message), endpoint, boost::bind(&UdpServer::handleSend,
    this, message, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void UdpServer::addClient(boost::asio::ip::udp::endpoint endpoint)
{
    std::string color_to_add = "blue";

    if (_clients.size() == 4) {
        std::cout << "Too many clients" << std::endl;
        return;
    }
    for (auto i = _clients.begin(); i != _clients.end(); i++) {
        if (i->first == "blue")
            color_to_add = "red";
        if (i->first == "red")
            color_to_add = "yellow";
        if (i->first == "yellow")
            color_to_add = "green";
    }
    _clients.push_back(std::pair<std::string, boost::asio::ip::udp::endpoint>(color_to_add, endpoint));
    send("COLOR " + color_to_add, endpoint);
}

bool UdpServer::clientExists(boost::asio::ip::udp::endpoint endpoint)
{
    for (auto i = _clients.begin(); i != _clients.end(); i++) {
        if (i->second == endpoint) {
            return (true);
        }
    }
    return (false);
}

void UdpServer::sendToAll(std::string data)
{
    for (auto i = _clients.begin(); i != _clients.end(); i++) {
        send(data, i->second);
    }
}