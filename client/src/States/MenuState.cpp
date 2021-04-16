/*
** EPITECH PROJECT, 2023
** B-CPP-501-BDX-5-1-rtype-philippe-jacques.tatel
** File description:
** Created by valentinbreiz,
*/

#include "../Engine/StateMachine.hpp"
#include "MenuState.hpp"
#include "LobbyState.hpp"
#include "OptionState.hpp"

MenuState::MenuState(StateMachine& machine, sf::RenderWindow &window, const bool replace)
        : State{ machine, window, replace }
{
    std::cout << "MenuState Ctor" << std::endl;

    std::string path = findFolder();

    if(!_machine._client->_font.loadFromFile(path + "/Ressources/Font/M 8pt.ttf")) {
        throw Exception("Cannot load texture");
    }
    _join_lobby.setFont(_machine._client->_font);
    _options.setFont(_machine._client->_font);
    _exit.setFont(_machine._client->_font);

    _join_lobby.setString("Join Lobby");
    _options.setString("Options");
    _exit.setString("Exit");

    _join_lobby.setColor(sf::Color::White);
    _options.setColor(sf::Color::White);
    _exit.setColor(sf::Color::White);

    _join_lobby.setCharacterSize(32);
    _options.setCharacterSize(32);
    _exit.setCharacterSize(32);

    _join_lobby.setPosition((sf::Vector2f){(800 / 2) - (208 / 2), 290});
    _options.setPosition((sf::Vector2f){(800 / 2) - (136 / 2), 350});
    _exit.setPosition((sf::Vector2f){(800 / 2) - (60 / 2), 410});

    _menu_index = 0;

    if(!_logo_texture.loadFromFile(path + "/Ressources/Images/logo.png")) {
        throw Exception("Cannot load texture");
    }
    
    _logo.setTexture(_logo_texture);
    _logo.setPosition((800 / 2) - (500 / 2), 100);

    if(!_bg_texture.loadFromFile(path + "/Ressources/Images/background.jpg")) {
        throw Exception("Cannot load texture");
    }

    _bg.setTexture(_bg_texture);

    if (!_buffer.loadFromFile("./client/Ressources/Music/soundMenuButton.wav")) {
        throw Exception("Can't load sound!");
    }
    _sound.setBuffer(_buffer);
}

MenuState::~MenuState()
{
    std::cout << "MenuState Dtor" << std::endl;
}

void MenuState::pause()
{
    std::cout << "MenuState Pause" << std::endl;
}

void MenuState::resume()
{
    std::cout << "MenuState Resume" << std::endl;
}

void MenuState::pollEvents(sf::Event event)
{
    switch (event.type) {
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Up) {
                if (this->_menu_index > 0)
                    _menu_index--;
                _sound.play();
            }
            if (event.key.code == sf::Keyboard::Down) {
                if (this->_menu_index < 2)
                    _menu_index++;
                _sound.play();
            }
            if (event.key.code == sf::Keyboard::Enter) {
                if (_menu_index == 0) {
                    _next = StateMachine::build<LobbyState>(_machine, _display, true);
                }
                else if (_menu_index == 1) {
                    // options ?
                    _next = StateMachine::build<OptionState>(_machine, _display, true);
                }
                else if (_menu_index == 2) {
                    _machine.quit();
                }
            }
            if (event.key.code == sf::Keyboard::Escape) {
                _machine.quit();
            }
            break;
        default:
            break;
    }
}

void MenuState::update()
{
    if (_menu_index == 0) {
        _join_lobby.setColor(sf::Color::Yellow);
        _options.setColor(sf::Color::White);
        _exit.setColor(sf::Color::White);
    }
    else if (_menu_index == 1) {
        _options.setColor(sf::Color::Yellow);
        _join_lobby.setColor(sf::Color::White);
        _exit.setColor(sf::Color::White);
    }
    else if (_menu_index == 2) {
        _exit.setColor(sf::Color::Yellow);
        _options.setColor(sf::Color::White);
        _join_lobby.setColor(sf::Color::White);
    }
}

void MenuState::draw()
{
    _display.draw(_bg);
    _display.draw(_join_lobby);
    _display.draw(_options);
    _display.draw(_exit);
    _display.draw(_logo);
    _display.display();
}