/*
** EPITECH PROJECT, 2020
** $
** File description:
** setSpriteMonster
*/

#include "sprite.hpp"


void Sprite::setEnemyMovePos()
{
    _enemyX = _enemyShape.getPosition().x;

    _enemyShape.setTexture(&_textureMonster);
    _enemyShape.setSize(_enemySize);

    _enemySpeed = 15;
}


void Sprite::setEnemyMove()
{
    if (_enemyX > 0) {
        _enemyX -= _enemySpeed * 0.9;
    } else {
        _enemyX = 800;
        _spriteMonsterPos.y = setRandomNb();
        
    }
    if (_enemyAttackX > 0) {
        _enemyAttackX -= 150 * 0.8;;
    } else {
        _enemyAttackX = _enemyX - 100.f;
        _spriteMonsterAttackPos.y = _spriteMonsterPos.y;
    }
}

void Sprite::setSpriteMonsterPosition(sf::Vector2f newpos)
{
    _spriteMonsterPos = newpos;
}

int Sprite::setRandomNb()
{
    _randomPosMonster = rand() % 500 + 10;
    return _randomPosMonster;
}