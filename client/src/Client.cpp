/*
** EPITECH PROJECT, 2023
** B-CPP-501-BDX-5-1-rtype-philippe-jacques.tatel
** File description:
** Created by valentinbreiz,
*/

#include "Client.hpp"

Client::Client()
{
    _volume = 20;
    _position = (800 / 2) - (169 / 2) + 59 - (11 / 2) + (((138 - 59) / 21) * 7);
    _color = "none";
}

Client::~Client()
{

}

int Client::getVolume()
{
    return _volume;
}

void Client::volumeUp()
{
    _volume = _volume + 5;
    if (_volume >= 100)
        _volume = 100;
}

void Client::volumeDown()
{
    _volume = _volume - 5;
    if (_volume <= 0)
        _volume = 0;
}

float Client::getSliderPos()
{
    return _position;
}

void Client::setSliderPos(float position)
{
    _position = position;
}