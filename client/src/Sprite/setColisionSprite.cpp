/*
** EPITECH PROJECT, 2020
** game
** File description:
** setColisionSprite
*/

#include "sprite.hpp"

bool collision(int x,int y, int x2, int y2)
{
    int collision = (x-x2)*(x-x2) + (y-y2)*(y-y2);
    if (collision > 10*10)
        return false;
    else
        return true;
}

bool collision2(int x,int y, int x2, int y2)
{
    int collision = (x-x2)*(x-x2) + (y-y2)*(y-y2);
    if (collision > 25*25)
        return false;
    else
        return true;
}

int Sprite::setEnemyHeroColision()
{
    _cooll = collision(_spriteAttackEnemy.getPosition().x, _spriteAttackEnemy.getPosition().y,
            _spriteHero.getPosition().x, _spriteHero.getPosition().y);
    if (_cooll == true)
        _hearthPoint--;
    return _hearthPoint;
}

int Sprite::setHeroEnemyColision()
{
    _cooll2 = collision2(_spriteMonster.getPosition().x, _spriteMonster.getPosition().y,
            _spriteAttack.getPosition().x, _spriteAttack.getPosition().y);
    if (_cooll2 == true) {
        _pointScore++;
    }
    return _pointScore;
}