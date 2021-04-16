/*
** EPITECH PROJECT, 2020
** game
** File description:
** setText
*/

#include "text.hpp"

void Text::setStyleText()
{
    _textScores.setStyle(sf::Text::Bold | sf::Text::Underlined);
    _textScoresPoint.setStyle(sf::Text::Bold);
    _textScores.setFillColor(sf::Color::White);
    _textScoresPoint.setFillColor(sf::Color::White);
    _textScores.setCharacterSize(24);
    _textScoresPoint.setCharacterSize(24);
}

void Text::setAllText()
{
    setStyleText();
    _textScoresPos.y = 540.0f;
    _textScoresPos.x = 10.f;
    _textScoresPointPos.x = 100.f;
    _textScoresPointPos.y = 540.0f;

    setPosScoresPointText(_textScoresPointPos);
    setPosScoresText(_textScoresPos);

    setFont();

    _textScores.setFont(_fontScores);
    _textScoresPoint.setFont(_fontScoresPoint);
}

void Text::setPosScoresText(sf::Vector2f pos)
{
    _textScores.setPosition(pos);
}

void Text::setPosScoresPointText(sf::Vector2f pos)
{
    _textScoresPoint.setPosition(pos);
}

void Text::setTextStringScores(int scores)
{
    std::stringstream ss;
    ss << scores;
    _textScoresPoint.setString(ss.str().c_str());
}

void Text::setTextString()
{
    _textScores.setString("Scores:");
}

sf::Text Text::getTextScore()
{
    return _textScores;
}

sf::Text Text::getTextScorePoint()
{
    return _textScoresPoint;
}