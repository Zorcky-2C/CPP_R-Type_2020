/*
** EPITECH PROJECT, 2020
** game
** File description:
** setGameOver
*/

#include "sprite.hpp"


void Sprite::setOverPos()
{
    _overY = _overShape.getPosition().x;
    _overSize.x = 800;
    _overSize.y = 600;

    _overShape.setTexture(&_textureOver);
    _overShape.setSize(_overSize);
}