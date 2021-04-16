/*
** EPITECH PROJECT, 2020
** game
** File description:
** event
*/

#include "event.hpp"

sf::Event Event::getEvent()
{
    return _event;
}

void Event::setEvent(sf::Event event)
{
    _event = event;
}