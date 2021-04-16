/*
** EPITECH PROJECT, 2020
** $
** File description:
** setBackSprite
*/

#include "sprite.hpp"

std::vector<sf::Vector2f> Sprite::setPosSpriteStarLoop()
{
    std::vector<sf::Vector2f> pos(300);
    int index = 0;
    while (index != 290) {
        pos.at(index).x = rand() % 800;
        pos.at(index).y = rand() % 600;
        index++;
    }
    return pos;
}


std::vector<sf::Sprite> Sprite::setSpriteStarLoop()
{
    std::vector<sf::Sprite> sprites(300);
    int index = 0;

    while (index != 290) {
        sprites.at(index).setTexture(_textureStarBack);
        index++;
    }
    return sprites;
}

std::vector<sf::Sprite> Sprite::setSpriteStarLoop2()
{
    std::vector<sf::Sprite> sprites(300);
    int index = 0;

    while (index != 290) {
        sprites.at(index).setTexture(_textureStarBack2);
        index++;
    }
    return sprites;
}

std::vector<sf::Sprite> Sprite::setSpritePosStarLoop()
{
    int index = 0;

    while (index != 290) {
        _starSpriteBack.at(index).setPosition(_starBackPos.at(index));
        _starSpriteBack.at(index).setScale(0.05, 0.05);
        index++;
    }
    return _starSpriteBack;
}

std::vector<sf::Sprite> Sprite::setSpritePosStarLoop2()
{
    int index = 0;

    while (index != 290) {
        _starSpriteBack2.at(index).setPosition(_starBackPos2.at(index));
        _starSpriteBack2.at(index).setScale(0.05, 0.05);
        index++;
    }
    return _starSpriteBack2;
}

void Sprite::setStarMove()
{
    int index = 0;
    while (index != 290) {
        if (_starSpriteBack.at(index).getPosition().x > 0) {
            _starBackPos.at(index).x -= 2 * 5;
        } else {
            _starBackPos.at(index).x = rand() % 800;
            _starBackPos.at(index).y = rand() % 600;
        }
        if (_starSpriteBack2.at(index).getPosition().x > 0) {
            _starBackPos2.at(index).x -= 2 * 5;
        } else {
            _starBackPos2.at(index).x = rand() % 800;
            _starBackPos2.at(index).y = rand() % 600;
        }
        index++;
    }
}