/*
** EPITECH PROJECT, 2020
** B-CPP-501-BDX-5-1-rtype-philippe-jacques.tatel
** File description:
** OptionState
*/

#include "OptionState.hpp"
#include "MenuState.hpp"
#include "../Engine/StateMachine.hpp"

OptionState::OptionState(StateMachine& machine, sf::RenderWindow &window, const bool replace)
        : State{ machine, window, replace }, _window(window)
{
    std::cout << "OptionState Ctor" << std::endl;
    std::string path = findFolder();

    if (!_bg_texture.loadFromFile(path + "/Ressources/Images/background.jpg")) {
        std::cout << "Can't load texture!\n";
        // erreur...
    }
    _bg.setTexture(_bg_texture);
    if (!_logo_texture.loadFromFile(path + "/Ressources/Images/logo.png")) {
        std::cout << "Can't load texture!\n";
        // erreur...
    }
    _logo.setTexture(_logo_texture);
    _logo.setPosition((800 / 2) - (500 / 2), 100);
    if (!_popup_texture.loadFromFile(path + "/Ressources/Images/options.png")) {
        std::cout << "Can't load texture!\n";
        // erreur...
    }
    _popup.setTexture(_popup_texture);
    _popup.setPosition((800 / 2) - (169 / 2), (600 / 2));
    if (!_slider_texture.loadFromFile(path + "/Ressources/Images/slider.png")) {
        std::cout << "Can't load texture!\n";
        // erreur...
    }
    _slider.setTexture(_slider_texture);
    _slider.setPosition(_machine._client->getSliderPos(), (600 / 2) + 59 - (21 / 2));
    /*
        pxSlider : x11 y21
        pxPopup : x169 y89
        pxPopup slider bar: from  x59 y59   to  x138 y59
        nb volume levels: 21
    */
}

OptionState::~OptionState()
{
}

void OptionState::pause()
{
    std::cout << "OptionState Pause" << std::endl;
}

void OptionState::resume()
{
    std::cout << "OptionState Resume" << std::endl;
}

void OptionState::pollEvents(sf::Event event)
{

    switch (event.type) {
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Left && (_slider.getPosition().x - (11 / 2))  > ((800 / 2) - (169 / 2) + 59 - (11 / 2))) {
                _slider.move(-((138 - 59) / 21), 0);
                _machine._client->setSliderPos(_slider.getPosition().x);
                _machine._client->volumeDown();
                _machine._client->_music.setVolume(_machine._client->getVolume());
            }
            if (event.key.code == sf::Keyboard::Right && _slider.getPosition().x <= (((800 / 2) - (169 / 2) + 138 - (11 / 2)))) {
                _slider.move(((138 - 59) / 21), 0);
                _machine._client->setSliderPos(_slider.getPosition().x);
                _machine._client->volumeUp();
                _machine._client->_music.setVolume(_machine._client->getVolume());
            }
            if (event.key.code == sf::Keyboard::Escape)
                _next = StateMachine::build<MenuState>(_machine, _display, true);
    }
}

void OptionState::update()
{
}

void OptionState::draw()
{
    _display.draw(_bg);
    _display.draw(_logo);
    _display.draw(_popup);
    _display.draw(_slider);
    _display.display();
}