/*
** EPITECH PROJECT, 2020
** B_CPP_501_BDX_5_1_rtype_philippe_jacques_tatel
** File description:
** TODO: add description
*/

#include "Player.hpp"
#include <memory>

Player::Player(con_handle_t con_handle) :  _room(NULL), _ready(false), _con_handle(con_handle)
{
}

Player::Player(std::string name) : _name(name), _room(NULL), _ready(false)
{
}

Player::~Player()
{
}

void Player::Send(std::string str)
{
    auto buff = std::make_shared<std::string>(str);
    boost::asio::async_write(_con_handle->socket, boost::asio::buffer(*buff),[this](boost::system::error_code ec, std::size_t /*length*/) { });
}
