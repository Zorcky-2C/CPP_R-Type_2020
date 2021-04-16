/*
** EPITECH PROJECT, 2020
** game
** File description:
** setAttackSprite
*/

#include "sprite.hpp"

void Sprite::setNbKey(int nbKey)
{
    _nbKey = nbKey;
}

void Sprite::setHeroAttackMove()
{
    if (_spriteAttack.getPosition().x < 600) {
        _spriteAttackPos.x += 50 * 1;
    } else {
        _spriteAttackPos.y = _spriteHero.getPosition().y;
        _spriteAttackPos.x = _spriteHero.getPosition().x + 80.f;
        setNbKey(0);
    }
}

void Sprite::setSpriteAttackPosition(sf::Vector2f newpos)
{
    _spriteAttackPos = newpos;
}

void Sprite::setSpriteAttackEnemyPosition(sf::Vector2f newpos)
{
    _spriteAttackEnemyPos = newpos;
}


void Sprite::setClockAttack()
{
    if (_clock.getElapsedTime().asSeconds() > 0.1f){
        if (_rectSourceSpriteAttack.left >= 35) {
            _rectSourceSpriteAttack.left = 17;
        } else {
            _rectSourceSpriteAttack.left = 17;
        }
        _spriteAttack.setTextureRect(_rectSourceSpriteAttack);
        _spriteAttackEnemy.setPosition(_spriteMonsterPos.x, _spriteMonsterPos.y);
        _clock.restart();
        setEnemyMove();
        setHeroAttackMove();
        setStarMove();
        setStageMoveUp();
        setStageMoveDown();
    }
}
