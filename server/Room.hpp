/*
** EPITECH PROJECT, 2023
** B_CPP_501_BDX_5_1_rtype_philippe_jacques_tatel
** File description:
** Created by valentinbreiz,
*/

#ifndef B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_ROOM_HPP
#define B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_ROOM_HPP

#include "Clock.hpp"
#include <exception>
#include <iostream>
#include <memory>
#include <set>
#include "Player.hpp"

class Room
{
    public:
        Room(std::string name);
        ~Room();
        std::string getName() { return (this->_name); }
        void Join(std::shared_ptr<Player> player);
        void Leave(std::shared_ptr<Player> player);
        std::set<std::shared_ptr<Player>> getPlayers() { return (this->_participants); }
        bool isAllPlayerReady();
    private:
        std::string _name;
        std::set<std::shared_ptr<Player>> _participants;
};


#endif //B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_ROOM_HPP
