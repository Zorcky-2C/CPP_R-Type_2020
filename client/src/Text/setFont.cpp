/*
** EPITECH PROJECT, 2020
** game
** File description:
** setFont
*/

#include "text.hpp"

void Text::setFont()
{
    std::string path = findFolder();
    _fontScores.loadFromFile(path + "/Ressources/Font/Lato-Black.ttf");
    _fontScoresPoint.loadFromFile(path + "/Ressources/Font/Lato-Black.ttf");
}