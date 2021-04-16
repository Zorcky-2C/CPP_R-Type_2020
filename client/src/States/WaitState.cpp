/*
** EPITECH PROJECT, 2023
** B-CPP-501-BDX-5-1-rtype-philippe-jacques.tatel
** File description:
** Created by valentinbreiz,
*/

#include "WaitState.hpp"
#include "../Engine/StateMachine.hpp"
#include "LobbyState.hpp"
#include <thread>

WaitState::WaitState(StateMachine& machine, sf::RenderWindow &window, const bool replace) : State{ machine, window, replace }
{
    std::cout << "WaitState Ctor" << std::endl;

    std::string path = findFolder();

    if(!_window_texture.loadFromFile(path + "/Ressources/Images/wait.png")) {
        throw Exception("Cannot load texture");
    }
    _window.setTexture(_window_texture);
    _window.setPosition((sf::Vector2f){(800 / 2) - (273 / 2), (600 / 2) - (83 / 2)});
    if(!_bg_texture.loadFromFile(path + "/Ressources/Images/background.jpg")) {
        throw Exception("Cannot load texture");
    }
    _bg.setTexture(_bg_texture);

    _text.setFont(machine._client->_font);
    _text.setString("Status: NOT READY");
    _text.setColor(sf::Color::Black);
    _text.setCharacterSize(8);
    _text.setPosition((sf::Vector2f){(800 / 2) - (94 / 2), 340});

    _text_room.setFont(machine._client->_font);
    _text_room.setString("room " + _machine._client->getRoomName() + ".");
    _text_room.setColor(sf::Color::Black);
    _text_room.setCharacterSize(8);
    _text_room.setPosition((sf::Vector2f){433, 302});

    _machine._client->setReady(false);
}

WaitState::~WaitState()
{
    std::cout << "WaitState Dtor" << std::endl;
    _machine._client->_tcpclient->stop();
}

void WaitState::pause()
{
    std::cout << "WaitState Pause" << std::endl;
}

void WaitState::resume()
{
    std::cout << "WaitState Resume" << std::endl;
}

void WaitState::pollEvents(sf::Event event)
{
    switch (event.type) {
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Space) {
                if (_machine._client->getReady() == false) {
                    _text.setString("Status: READY");
                    _machine._client->setReady(true);
                    _machine._client->_tcpclient->startWrite("SET_READY true\n");
                }
                else {
                    _text.setString("Status: NOT READY");
                    _machine._client->setReady(false);
                    _machine._client->_tcpclient->startWrite("SET_READY false\n");
                }
            }
            if (event.key.code == sf::Keyboard::Escape) {
                _machine._client->setReady(false);
                _machine._client->_tcpclient->startWrite("LEAVE_ROOM\n");
                _next = StateMachine::build<LobbyState>(_machine, _display, true);
            }
        default:
            break;
    }
}
void WaitState::update()
{
    std::string str = _machine._client->_tcpclient->getReturn();

    if (str == "GAMESTART" || str.rfind("Updating ") == 0) {
        _next = StateMachine::build<GameState>(_machine, _display, true);
    }
}

void WaitState::draw()
{
    _display.draw(_bg);
    _display.draw(_window);
    _display.draw(_text);
    _display.draw(_text_room);
    _display.display();
}