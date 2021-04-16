/*
** EPITECH PROJECT, 2020
** B-CPP-501-BDX-5-1-rtype-philippe-jacques.tatel
** File description:
** setStageObstaclesSprites
*/

#include "sprite.hpp"

std::vector<sf::Vector2f> Sprite::setPosSpriteStageObstaclesLoopUp()
{
    std::vector<sf::Vector2f> pos(13);
    int index = 0;
    while (index != 11) {
        if (index != 0)
            pos.at(index).x = 85 + pos.at(index - 1).x;
        else
            pos.at(index).x = 0;
        pos.at(index).y = 0;
        index++;
    }
    return pos;
}

std::vector<sf::Sprite> Sprite::setSpriteStageObstaclesLoopUp()
{
    std::vector<sf::Sprite> sprites(13);
    int index = 0;

    while (index != 11) {
        sprites.at(index).setTexture(_textureStageObstaclesUp);
        index++;
    }
    return sprites;
}


std::vector<sf::Sprite> Sprite::setSpritePosStageObstaclesLoopUp()
{
    int index = 0;
    while (index != 11) {
        _stageObstaclesSpritesUp.at(index).setPosition(_stageObstaclesUpPos.at(index));
        index++;
    }
    return _stageObstaclesSpritesUp;
}

void Sprite::setStageMoveUp()
{
    int index = 0;
    int posCalc = 885;
    while (index != 11) {
        if (_stageObstaclesSpritesUp.at(index).getPosition().x > -85) {
            _stageObstaclesUpPos.at(index).x -=  10;
        } else {
            if (index != 0) {
                posCalc -= 85;
                _stageObstaclesUpPos.at(index).x = posCalc;
            } else {
                _stageObstaclesUpPos.at(index).x = 800;
            }
        }
        index++;
    }
}