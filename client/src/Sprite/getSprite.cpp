/*
** EPITECH PROJECT, 2020
** game
** File description:
** sprite
*/

#include "sprite.hpp"

sf::Sprite Sprite::getSpriteAttack()
{
    return _spriteAttack;
}

sf::Sprite Sprite::getSpriteEnemyAttack()
{
    return _spriteAttackEnemy;
}

sf::Sprite Sprite::getSpriteMonster()
{
    return _spriteMonster;
}

sf::Sprite Sprite::getSpriteHero()
{
    return _spriteHero;
}

int Sprite::getScoresPoint()
{
    return _pointScore;
}

sf::Sprite Sprite::getSpriteOver()
{
    return _spriteOver;
}


int Sprite::getHearthPoint()
{
    return _hearthPoint;
}

int Sprite::getNbKey()
{
    return _nbKey;
}

sf::Sprite Sprite::getSpriteStarBack(int index)
{
    return _starSpriteBack.at(index);
}

sf::Sprite Sprite::getSpriteStarBack2(int index)
{
    return _starSpriteBack2.at(index);
}

sf::Sprite Sprite::getSpriteStageObstaclesUp(int index)
{
    return _stageObstaclesSpritesUp.at(index);
}

sf::Sprite Sprite::getSpriteStageObstaclesDown(int index)
{
    return _stageObstaclesSpritesDown.at(index);
}