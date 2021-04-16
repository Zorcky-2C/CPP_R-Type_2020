/*
** EPITECH PROJECT, 2020
** game
** File description:
** sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <dirent.h>
#include <string.h>
#include <vector>

const char *findFolder();

class Sprite {
    public:
        /*Back*/
        std::vector<sf::Sprite> setSpriteStarLoop();
        std::vector<sf::Sprite> setSpriteStarLoop2();
        std::vector<sf::Sprite> setSpritePosStarLoop();
        std::vector<sf::Sprite> setSpritePosStarLoop2();
        sf::Sprite getSpriteStarBack(int index);
        sf::Sprite getSpriteStarBack2(int index);
        std::vector<sf::Vector2f> setPosSpriteStarLoop();
        void setStarMove();

        /*stageObstaclesUp*/
        std::vector<sf::Sprite> setSpriteStageObstaclesLoopUp();
        std::vector<sf::Sprite> setSpritePosStageObstaclesLoopUp();
        std::vector<sf::Vector2f> setPosSpriteStageObstaclesLoopUp();
        void setStageMoveUp();
        sf::Sprite getSpriteStageObstaclesUp(int index);


        /*stageObstaclesDown*/
        std::vector<sf::Sprite> setSpriteStageObstaclesLoopDown();
        std::vector<sf::Sprite> setSpritePosStageObstaclesLoopDown();
        std::vector<sf::Vector2f> setPosSpriteStageObstaclesLoopDown();
        void setStageMoveDown();
        sf::Sprite getSpriteStageObstaclesDown(int index);

        /*GameOver*/
        void setOverPos();
        sf::Sprite getSpriteOver();

        /*Hero*/
        sf::Sprite getSpriteHero();
        void setSpriteHeroPosition(sf::Vector2f newpos);
        void setHeroAttackMove();

        /*AttackHero*/
        sf::Sprite getSpriteAttack();
        void setSpriteAttackPosition(sf::Vector2f newpos);
        void setClockAttack();
        int getScoresPoint();

        /*AttackEnemy*/
        sf::Sprite getSpriteEnemyAttack();
        void setSpriteAttackEnemyPosition(sf::Vector2f newpos);

        /*Heart*/
        int getHearthPoint();

        /*Monster*/
        sf::Sprite getSpriteMonster();
        void setSpriteMonsterPosition(sf::Vector2f newpos);
        void setEnemyMove();
        void setEnemyMovePos();
        int setRandomNb();
        
        /*All Sprite*/
        void setAllSprite();
        void setMove();
        void setSpritePos();
        void setSpritePosBase();
        void setTextureSprite();
        void setSprite();
        void setRectSprite();
        int getNbKey();
        void setNbKey(int nb);

        /*Collision*/
        int setEnemyHeroColision();
        int setHeroEnemyColision();
        bool _cooll;
        bool _cooll2;

    private:
        /*Back*/
        std::vector<sf::Sprite> _starSpriteBack;
        sf::Texture _textureStarBack;
        std::vector<sf::Vector2f> _starBackPos;
        std::vector<sf::Sprite> _starSpriteBack2;
        sf::Texture _textureStarBack2;
        std::vector<sf::Vector2f> _starBackPos2;

        /*StageObstaclesUp*/
        sf::Texture _textureStageObstaclesUp;
        std::vector<sf::Sprite> _stageObstaclesSpritesUp;
        std::vector<sf::Vector2f> _stageObstaclesUpPos;

        /*StageObstaclesDown*/
        sf::Texture _textureStageObstaclesDown;
        std::vector<sf::Sprite> _stageObstaclesSpritesDown;
        std::vector<sf::Vector2f> _stageObstaclesDownPos;

        /*GameOver*/
        sf::Texture _textureOver;
        sf::Sprite _spriteOver;
        sf::RectangleShape _overShape;
        sf::IntRect _rectSourceSpriteOver;
        float _overY;
        float _overSpeed;
        sf::Vector2f _overSize;
        sf::Vector2f _spriteOverPos;

        /*AttackHero*/
        sf::Texture _textureAttack;
        sf::Sprite _spriteAttack;
        sf::IntRect _rectSourceSpriteAttack;
        sf::Vector2f _spriteAttackPos;

        /*AttackEnemy*/
        sf::Texture _textureAttackEnemy;
        sf::Sprite _spriteAttackEnemy;
        sf::IntRect _rectSourceSpriteAttackEnemy;
        sf::Vector2f _spriteAttackEnemyPos;
        float _enemyAttackX;
        sf::Vector2f _spriteMonsterAttackPos;
        int _nbKey;

        /*Hero*/
        sf::Texture _textureHero;
        sf::Sprite _spriteHero;
        sf::IntRect _rectSourceSpriteHero;
        sf::Vector2f _spriteHeroPos;

        /*Monster*/
        sf::Texture _textureMonster;
        sf::Sprite _spriteMonster;
        sf::RectangleShape _enemyShape;
        sf::IntRect _rectSourceSpriteMonster;
        sf::IntRect _rectSourceSpriteHeart;
        float _enemyX;
        float _enemySpeed;
        sf::Vector2f _enemySize;
        sf::Vector2f _spriteMonsterPos;
        int _randomPosMonster;

        /*Heart*/
        int _hearthPoint;

        /*Score*/
        int _pointScore;

        /*all*/
        sf::Clock _clock;
        sf::Clock _clockEnemy;
        sf::Vector2f _pos;
};

#endif /* !SPRITE_HPP_ */
