/*
** EPITECH PROJECT, 2020
** B_CPP_501_BDX_5_1_rtype_philippe_jacques_tatel
** File description:
** TODO: add description
*/

#ifndef B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_PLAYER_HPP
#define B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_PLAYER_HPP

#include <string>
#include <list>
#include "include.hpp"

class Room;
using con_handle_t = std::list<Connection>::iterator;

class Player
{
    public:
        Player(con_handle_t con_handle);
        Player(std::string name);
        ~Player();
        void setRoom(Room *room) { this->_room = room; };
        void setName(std::string name) { this->_name = name; };
        void setReady(bool ready) { this->_ready = ready; };
        std::string getName() { return (this->_name); };
        bool getReady() { return (this->_ready); };
        Room *getCurrentRoom() { return (this->_room); };
        void Send(std::string str);
    private:
        std::string _name;
        bool _ready;
        Room *_room;
        con_handle_t _con_handle;
};

#endif //B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_PLAYER_HPP
