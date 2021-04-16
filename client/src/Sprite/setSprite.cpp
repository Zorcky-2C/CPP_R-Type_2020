/*
** EPITECH PROJECT, 2020
** game
** File description:
** setSprite
*/

#include "sprite.hpp"



//Error verification on load file (bool verif)
void Sprite::setTextureSprite()
{
    std::string path = findFolder();
    _textureOver.loadFromFile(path + "/Ressources/Images/gameover.jpg");
    _textureAttack.loadFromFile(path + "/Ressources/Images/spaceShipAttack.png");
    _textureAttackEnemy.loadFromFile(path + "/Ressources/Images/monsterAttack.gif"); //a enlever
    _textureHero.loadFromFile(path + "/Ressources/Images/spaceShip.gif");
    _textureMonster.loadFromFile(path + "/Ressources/Images/monster.gif"); //a enlever
    _textureStarBack.loadFromFile(path + "/Ressources/Images/star_flare.png");
    _textureStarBack2.loadFromFile(path + "/Ressources/Images/star_flare_default.png");
    _textureStageObstaclesUp.loadFromFile(path + "/Ressources/Images/obstaclesUp2.jpg");
    _textureStageObstaclesDown.loadFromFile(path + "/Ressources/Images/obstaclesDown2.jpg");
}

void Sprite::setSprite()
{
    sf::Sprite spriteOver(_textureOver);
    sf::Sprite spriteAttack(_textureAttack);
    sf::Sprite spriteAttackEnemy(_textureAttackEnemy);
    sf::Sprite spriteHero(_textureHero);
    sf::Sprite spriteMonster(_textureMonster);

    sf::Sprite spriteStageObstaclesUp2(_textureStageObstaclesUp);
    sf::Sprite spriteStageObstaclesUp1(_textureStageObstaclesUp);

    _starSpriteBack = setSpriteStarLoop();
    _starSpriteBack2 = setSpriteStarLoop2();

    _stageObstaclesSpritesUp = setSpriteStageObstaclesLoopUp();
    _stageObstaclesSpritesDown = setSpriteStageObstaclesLoopDown();


    _pointScore = 0;
    _hearthPoint = 1;

    _spriteHeroPos.x = 120.f;
    _spriteHeroPos.y = 120.f;
    _spriteAttackPos.x = 170.f;
    _spriteAttackPos.y = 170.f;
    _spriteAttackEnemyPos.x = 170.f;
    _spriteAttackEnemyPos.y = 170.f;

    _enemyX = 750.f;
    _spriteMonsterPos.y = 120.f;

    _enemyAttackX = 750.f;
    _spriteMonsterAttackPos.y = 120.f;

    _starBackPos = setPosSpriteStarLoop();
    _starBackPos2 = setPosSpriteStarLoop();

    _stageObstaclesUpPos = setPosSpriteStageObstaclesLoopUp();
    _stageObstaclesDownPos = setPosSpriteStageObstaclesLoopDown();

    _spriteOver = spriteOver;
    _spriteAttack = spriteAttack;
    _spriteAttackEnemy = spriteAttackEnemy;
    _spriteHero = spriteHero;
    _spriteMonster = spriteMonster;
}

void Sprite::setRectSprite()
{
    sf::IntRect rectSourceSprite(0, 0, 18, 15);
    sf::IntRect rectSourceSpriteEnemy(20, 15, 30, 31);
    sf::IntRect rectSourceSpriteHero(32, 0, 35, 20);
    sf::IntRect rectSourceSpriteHeart(0, 0, 305, 300);
    sf::IntRect rectSourceSpriteMonster(0, 0, 35, 35);    
    
    _rectSourceSpriteAttack = rectSourceSprite;
    _rectSourceSpriteAttackEnemy = rectSourceSpriteEnemy;
    _rectSourceSpriteHero = rectSourceSpriteHero;
    _rectSourceSpriteMonster = rectSourceSpriteMonster;

    _spriteAttack.setTextureRect(_rectSourceSpriteAttack);
    _spriteAttackEnemy.setTextureRect(_rectSourceSpriteAttackEnemy);
    _spriteHero.setTextureRect(_rectSourceSpriteHero);
    _spriteMonster.setTextureRect(_rectSourceSpriteMonster);
}

void Sprite::setAllSprite()
{
    setTextureSprite();
    setOverPos();
    setEnemyMovePos();
    setSprite();
    setRectSprite();
}

void Sprite::setSpritePos()
{
    _starSpriteBack = setSpritePosStarLoop();
    _starSpriteBack2 = setSpritePosStarLoop2();
    _stageObstaclesSpritesUp = setSpritePosStageObstaclesLoopUp();
    _stageObstaclesSpritesDown = setSpritePosStageObstaclesLoopDown();
    
    _spriteAttack.setPosition(_spriteAttackPos.x, _spriteAttackPos.y);
    _spriteOver.setPosition(_overY, _spriteOverPos.y);
    _spriteMonster.setPosition(_enemyX, _spriteMonsterPos.y);
    _spriteAttackEnemy.setPosition(_enemyAttackX, _spriteMonsterAttackPos.y);
    _spriteHero.setPosition(_spriteHeroPos.x, _spriteHeroPos.y);
}

void Sprite::setMove()
{
    setClockAttack();
    setSpritePos();
}
