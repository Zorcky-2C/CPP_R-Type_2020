/*
** EPITECH PROJECT, 2020
** game
** File description:
** text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <sstream>

#include "../Sprite/sprite.hpp"

class Text {
    public:
    void setTextString();
    void setTextStringScores(int scores);
    void setFont();
    void setStyleText();
    void setPosScoresText(sf::Vector2f pos);
    void setPosScoresPointText(sf::Vector2f pos);
    sf::Text getTextScore();
    sf::Text getTextScorePoint();
    void setAllText();
    private:
    sf::Vector2f _textScoresPos;
    sf::Text _textScores;
    sf::Font _fontScores;
    sf::Vector2f _textScoresPointPos;
    sf::Text _textScoresPoint;
    sf::Font _fontScoresPoint;
};

#endif /* !TEXT_HPP_ */
