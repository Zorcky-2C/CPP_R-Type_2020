/*
** EPITECH PROJECT, 2020
** B_CPP_501_BDX_5_1_rtype_philippe_jacques_tatel
** File description:
** TODO: add description
*/

#ifndef B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_GAME_HPP
#define B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_GAME_HPP

#include <iostream>
#include "Clock.hpp"
#include "Room.hpp"
#include "UdpServer.hpp"

class Game
{
    public:
        Game(Room *room);
        ~Game();
        void Start();
        void handleReceive(std::string data, boost::asio::ip::udp::endpoint endpoint);
private:
        Clock _clock;
        Room *_room;
        std::shared_ptr<UdpServer> _server;
};

#endif //B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_GAME_HPP
