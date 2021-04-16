/*
** EPITECH PROJECT, 2020
** B-CPP-501-BDX-5-1-rtype-philippe-jacques.tatel
** File description:
** setStageObjectSpritesDown
*/

#include "sprite.hpp"

std::vector<sf::Vector2f> Sprite::setPosSpriteStageObstaclesLoopDown()
{
    std::vector<sf::Vector2f> pos(13);
    int index = 0;
    while (index != 11) {
        if (index != 0)
            pos.at(index).x = 85 + pos.at(index - 1).x;
        else
            pos.at(index).x = 0;
        pos.at(index).y = 570;
        index++;
    }
    return pos;
}

std::vector<sf::Sprite> Sprite::setSpriteStageObstaclesLoopDown()
{
    std::vector<sf::Sprite> sprites(13);
    int index = 0;

    while (index != 11) {
        sprites.at(index).setTexture(_textureStageObstaclesDown);
        index++;
    }
    return sprites;
}


std::vector<sf::Sprite> Sprite::setSpritePosStageObstaclesLoopDown()
{
    int index = 0;
    while (index != 11) {
        _stageObstaclesSpritesDown.at(index).setPosition(_stageObstaclesDownPos.at(index));
        index++;
    }
    return _stageObstaclesSpritesDown;
}

void Sprite::setStageMoveDown()
{
    int index = 0;
    int posCalc = 885;
    while (index != 11) {
        if (_stageObstaclesSpritesDown.at(index).getPosition().x > -85) {
            _stageObstaclesDownPos.at(index).x -=  10;
        } else {
            if (index != 0) {
                posCalc -= 85;
                _stageObstaclesDownPos.at(index).x = posCalc;
            } else {
                _stageObstaclesDownPos.at(index).x = 800;
            }
        }
        index++;
    }
}