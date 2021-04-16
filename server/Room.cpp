/*
** EPITECH PROJECT, 2023
** B_CPP_501_BDX_5_1_rtype_philippe_jacques_tatel
** File description:
** Created by valentinbreiz,
*/

#include "Room.hpp"

Room::Room(std::string name) : _name(name)
{
}

Room::~Room()
{
}

void Room::Join(std::shared_ptr<Player> player)
{
    _participants.insert(player);
    player->setRoom(this);
}

void Room::Leave(std::shared_ptr<Player> player)
{
    _participants.erase(player);
    player->setRoom(nullptr);
}

bool Room::isAllPlayerReady()
{
    for (auto &i : _participants) {
        if (i->getReady() == false)
            return (false);
    }
    return (true);
}
