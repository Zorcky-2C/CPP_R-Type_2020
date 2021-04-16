/*
** EPITECH PROJECT, 2020
** game
** File description:
** window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "../Sprite/sprite.hpp"
#include "../Text/text.hpp"

class Window {
    public:
        Window(sf::RenderWindow &window);
        sf::RenderWindow &getWindow();
        void clearWindow(Sprite sprite, Text text);
        int setPointHearth(int hearthPoint);
        int setNbKey(int nbKey);
    private:
        sf::RenderWindow &_window;
        int _hearthPoint;
        int _scoresPoint;
        int _keyNb;
        int _index;
};

#endif /* !WINDOW_HPP_ */
