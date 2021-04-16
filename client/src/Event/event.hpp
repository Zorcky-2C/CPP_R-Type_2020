/*
** EPITECH PROJECT, 2020
** game
** File description:
** event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "../Sprite/sprite.hpp"

#include <iostream>

class Event{
    public:
    sf::Event getEvent();
    void setEvent(sf::Event event);
    private:
    sf::Event _event;
    sf::Vector2f _pos;
    Sprite _sprite;
};

#endif /* !EVENT_HPP_ */
