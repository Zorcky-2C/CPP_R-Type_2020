/*
** EPITECH PROJECT, 2020
** game
** File description:
** window
*/

#include "window.hpp"

Window::Window(sf::RenderWindow &window) : _window(window)
{
}

sf::RenderWindow &Window::getWindow()
{
    return _window;
}

int Window::setNbKey(int nbKey)
{
    _keyNb = nbKey;
    return _keyNb;
}

int Window::setPointHearth(int hearthPoint)
{
    _hearthPoint = hearthPoint;
    return _hearthPoint;   
}


void Window::clearWindow(Sprite sprite, Text text)
{
    _window.clear(sf::Color::Black);
    _index = 0;
    while (_index != 290) {
        _window.draw(sprite.getSpriteStarBack(_index));
        _window.draw(sprite.getSpriteStarBack2(_index));
        _index++;
    }
    _index = 0;
    while (_index != 11) {
        _window.draw(sprite.getSpriteStageObstaclesUp(_index));
        _index++;
    }
    _index = 0;
    while (_index != 11) {
        _window.draw(sprite.getSpriteStageObstaclesDown(_index));
        _index++;
    }
    _index = 0;
    _window.draw(sprite.getSpriteHero());
    _window.draw(sprite.getSpriteMonster());

    if (_keyNb == 1) {
        _window.draw(sprite.getSpriteAttack());
    }

    _window.draw(sprite.getSpriteEnemyAttack());
    _window.draw(text.getTextScore());
    _window.draw(text.getTextScorePoint());
    /*if(_hearthPoint <= 0) {
        _window.draw(sprite.getSpriteOver());
    }*/
}
