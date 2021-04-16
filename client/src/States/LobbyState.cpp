/*
** EPITECH PROJECT, 2023
** B-CPP-501-BDX-5-1-rtype-philippe-jacques.tatel
** File description:
** Created by valentinbreiz,
*/

#include "LobbyState.hpp"
#include "../Engine/StateMachine.hpp"
#include "../Clock.hpp"
#include "WaitState.hpp"
#include "MenuState.hpp"
#include <thread>
#include <list>

LobbyState::LobbyState(StateMachine& machine, sf::RenderWindow &window, const bool replace) : State{ machine, window, replace }
{
    std::cout << "LobbyState Ctor" << std::endl;
    _select_room = 0;
    std::string path = findFolder();

    if(!_window_texture.loadFromFile(path + "/Ressources/Images/lobby.png")) {
        throw Exception("Cannot load texture");
    }
    _window.setTexture(_window_texture);
    _window.setPosition((sf::Vector2f){(800 / 2) - (543 / 2), (600 / 2) - (346 / 2)});

    if(!_bg_texture.loadFromFile(path + "/Ressources/Images/background.jpg")) {
        throw Exception("Cannot load texture");
    }
    _bg.setTexture(_bg_texture);

    _playerInput = "";

    _playerText.setColor(sf::Color::Black);
    _playerText.setCharacterSize(8);
    _playerText.setPosition((sf::Vector2f){225, 446});

    _refresh = true;

    _clock.restart();

    std::thread t1([this] {
        try {
            boost::asio::io_service io_service;
            tcp::resolver r(io_service);

            _machine._client->_tcpclient = std::make_shared<TcpClient>(io_service);
            _machine._client->_tcpclient->start(r.resolve(tcp::resolver::query("127.0.0.1", "4242")));
            io_service.run();
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    });
    t1.detach();
}

LobbyState::~LobbyState()
{
    std::cout << "LobbyState Dtor" << std::endl;
    _refresh = false;
}

void LobbyState::setrooms()
{
    _rooms_str = askrequest("LIST_ROOM\n");

    if (_rooms_str == "NO_ROOM") {
        _rooms_str = "";
    }
    else {
        boost::algorithm::split(_rooms, _rooms_str, boost::is_any_of(":"));
    }
}

std::string LobbyState::askrequest(std::string request)
{
    _machine._client->_tcpclient->startWrite(request);
    return (_machine._client->_tcpclient->waitForResponse());
}

void LobbyState::pause()
{
    std::cout << "LobbyState Pause" << std::endl;
}

void LobbyState::resume()
{
    std::cout << "LobbyState Resume" << std::endl;
}

void LobbyState::pollEvents(sf::Event event)
{
    switch (event.type) {
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Enter) {
                if (_playerInput.size() > 0) {
                    askrequest("ADD_ROOM " + _playerInput + "\n");
                    _playerInput.clear();
                }
                else if (_playerInput.empty()) {
                    _machine._client->setRoomName(_current_rooms);
                    askrequest("JOIN_ROOM " + _current_rooms + "\n");
                    _next = StateMachine::build<WaitState>(_machine, _display, true);
                }
                break;
            }
            if (event.key.code == sf::Keyboard::Down && _select_room < _rooms.size() - 2)
                _select_room = _select_room + 1;
            if (event.key.code == sf::Keyboard::Up  && _select_room > 0)
                _select_room = _select_room - 1;
            if (event.key.code == sf::Keyboard::Escape) {
                _next = StateMachine::build<MenuState>(_machine, _display, true);
            }
            break;
        case sf::Event::TextEntered:
            if (event.text.unicode == '\b') {
                if (!_playerInput.empty()) {
                    _playerInput.resize(_playerInput.size() - 1);
                    _playerText.setString(_playerInput);
                }
            }
            else if (event.text.unicode < 0x80 && event.text.unicode != ' ') {
                if (_playerInput.size() < 11) {
                    _playerText.setFont(_machine._client->_font);
                    _playerInput += event.text.unicode;
                    _playerText.setString(_playerInput);
                }
            }
            break;
        default:
            break;
    }
}
void LobbyState::update()
{
    if (_playerInput == "\r") {
        _playerInput.clear();
    }
    if (_clock.getElapsedTime().asSeconds() > 1) {
        if (this->_machine._client->_tcpclient != nullptr && this->_machine._client->_tcpclient->isConnected()) {
            setrooms();
        }
        _clock.restart();
    }
}

void LobbyState::draw()
{
    _display.draw(_bg);
    _display.draw(_window);

    float y = 170;
    int i = 0;
    for (auto &_room : _rooms) {
        sf::Text room;
        room.setFont(_machine._client->_font);
        room.setColor(sf::Color::Black);
        room.setCharacterSize(16);
        if (i == _select_room) {
            room.setString("> " + _room);
            _current_rooms = _room;
        }
        else {
            room.setString(_room);
        }
        room.setPosition((sf::Vector2f){149, y});
        i = i + 1;
        y += 19;
        _display.draw(room);
    }
    _display.draw(_playerText);
    _display.display();
}