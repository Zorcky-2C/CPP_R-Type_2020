/*
** EPITECH PROJECT, 2023
** B_CPP_501_BDX_5_1_rtype_philippe_jacques_tatel
** File description:
** Created by valentinbreiz,
*/

#include <iostream>
#include "UdpClient.hpp"
#include "../States/GameState.hpp"

UdpClient::UdpClient(boost::asio::io_service &io_service, GameState *state) : _state(state)
{
    _remote_endpoint = new boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 4444);
    _socket = new boost::asio::ip::udp::socket(io_service);
    _socket->open(boost::asio::ip::udp::v4());
    memset(_data, 0, _max_length);
    startReceive();
}

UdpClient::~UdpClient()
{
    _socket->close();
}

void UdpClient::startReceive()
{
    _socket->async_receive_from(boost::asio::buffer(_data, _max_length), *_remote_endpoint,
                                boost::bind(&UdpClient::handleReceive, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void UdpClient::handleReceive(const boost::system::error_code& error, std::size_t)
{
    if (!error || error == boost::asio::error::message_size) {
        _state->handleReceive(_data);
        memset(_data, 0, _max_length);
    }
    else {
        std::cout << "Error hanleReceive" << std::endl;
    }
    startReceive();
}

void UdpClient::handleSend(boost::shared_ptr<std::string>, const boost::system::error_code& error, std::size_t)
{
    if (!error) {

    }
    else {
        std::cout << "Error: " << error.message() << "\n";
    }
    startReceive();
}

void UdpClient::send(std::string str)
{
    //std::cout << "Sending:" << str << std::endl;
    boost::shared_ptr<std::string> message(new std::string(str));
    _socket->async_send_to(boost::asio::buffer(*message), *_remote_endpoint, boost::bind(&UdpClient::handleSend, this, message, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}