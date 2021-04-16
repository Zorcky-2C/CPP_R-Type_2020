/*
** EPITECH PROJECT, 2020
** indie_studio
** File description:
** file
*/

#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include "GameState.hpp"
#include "../Engine/StateMachine.hpp"
#include "SplashState.hpp"

GameState::GameState(StateMachine& machine, sf::RenderWindow &window, const bool replace)
        : State{ machine, window, replace }, _window(window)
{
    std::cout << "GameState Ctor" << std::endl;
    std::string path = findFolder();
    if (!_machine._client->_music.openFromFile(path + "/Ressources/Music/gameMusic.ogg")) {
        std::cout << "Can't load music!\n";
    }
    _machine._client->_music.setVolume(20);
    _machine._client->_music.play();

    _sprite.setAllSprite();
    _window.setPointHearth(1);
    _sprite.setNbKey(0);
    _text.setAllText();
    _text.setFont();
    _posTextScore.y = 540.0f;
    _posTextScore.x = 10.f;

    _posTextScorePoint.x = 100.f;
    _posTextScorePoint.y = 540.0f;
    _text.setPosScoresText(_posTextScore);
    _text.setPosScoresPointText(_posTextScorePoint);

    _score = 0;

    texture.loadFromFile(path + "/Ressources/Images/spaceShip.gif");
    sf::IntRect rectSourceSpriteHero(0, 0, 35, 20);

    for (int i = 0; i < 4; i++) {
        sf::Sprite sprite;
        sprite.setTextureRect(rectSourceSpriteHero);
        sprite.setTexture(texture);
        _ships.push_back(sprite);
    }

    _client = std::make_shared<UdpClient>(io_service, this);

    std::thread t1([this] {
        try {
            io_service.run();
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    });
    t1.detach();
    std::thread t2([this] {
        while (_client == nullptr);
        _client->send("CLIENT OK");
    });
    t2.detach();
}

GameState::~GameState()
{
    std::cout << "GameState Dtor" << std::endl;
    exit(0);
}

void GameState::pause()
{
    std::cout << "Options Pause" << std::endl;
}

void GameState::resume()
{
    std::cout << "Options Resume" << std::endl;
}

void GameState::pollEvents(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
            _next = StateMachine::build<SplashState>(_machine, _display, true);
        }
        if (_client != nullptr && _machine._client->getColor() != "none") {
            auto pos = _sprite.getSpriteHero().getPosition();
            _client->send("POS " + _machine._client->getColor() + " " + std::to_string(pos.x) + " " + std::to_string(pos.y));
        }
    }
    _eventE.setEvent(event);
    setUpKey();
    setDownKey();
    setLeftKey();
    setRightKey();
    setAttackKey();
}

void GameState::update()
{
    _sprite.setEnemyHeroColision();
    _sprite.setHeroEnemyColision();
    _text.setTextString();
    _sprite.setMove();
    _window.setPointHearth(_sprite.getHearthPoint());
    _text.setTextStringScores(0);
    _window.setNbKey(_key);
}

void GameState::draw()
{
    _window.setNbKey(_sprite.getNbKey());
    _window.clearWindow(_sprite, _text);
    for (auto i = _ships.begin(); i != _ships.end(); i++) {
        _window.getWindow().draw(*i);
    }
    _window.getWindow().display();
}

void GameState::setUpKey()
{
    if (_eventE.getEvent().type == sf::Event::KeyPressed) {
        if (_eventE.getEvent().key.code == sf::Keyboard::Up) {
            _pos = _sprite.getSpriteHero().getPosition();
            _pos.y -= 20.f;
            if (_pos.y > 5) {
                _sprite.setSpriteHeroPosition(_pos);
            } else {
                _pos.y = 5;
            }
        }
    }
}

void GameState::setAttackKey()
{
    if (_eventE.getEvent().type == sf::Event::KeyPressed) {
        if (_eventE.getEvent().key.code == sf::Keyboard::A) {
            _sprite.setNbKey(1);
            sf::Vector2f pos;
            pos.x = _sprite.getSpriteHero().getPosition().x;
            pos.y = _sprite.getSpriteHero().getPosition().y;
            _sprite.setSpriteAttackPosition(pos);
        }
    }
}

void GameState::setDownKey()
{
    if (_eventE.getEvent().type == sf::Event::KeyPressed) {
        if (_eventE.getEvent().key.code == sf::Keyboard::Down) {
            _pos = _sprite.getSpriteHero().getPosition();
            _pos.y += 20.f;
            if (_pos.y < 565) {
                _sprite.setSpriteHeroPosition(_pos);
            } else {
                _pos.y = 565;
            }
        }
    }
}

void GameState::setLeftKey()
{
    if (_eventE.getEvent().type == sf::Event::KeyPressed) {
        if (_eventE.getEvent().key.code == sf::Keyboard::Left) {
            _pos = _sprite.getSpriteHero().getPosition();
            _pos.x -= 20.f;
            if (_pos.x > 0) {
                _sprite.setSpriteHeroPosition(_pos);
            } else {
                _pos.x = 0;
            }
        }
    }
}

void GameState::setRightKey()
{
    if (_eventE.getEvent().type == sf::Event::KeyPressed) {
        if (_eventE.getEvent().key.code == sf::Keyboard::Right) {
            _pos = _sprite.getSpriteHero().getPosition();
            _pos.x += 20.f;
            if (_pos.x < 765) {
                _sprite.setSpriteHeroPosition(_pos);
            } else {
                _pos.x = 765;
            }
        }
    }
}

void GameState::handleReceive(std::string data)
{
    std::vector<std::string> results;
    boost::algorithm::split(results, data, boost::is_any_of(" "));

    if (results[0] == "COLOR") {
        _machine._client->setColor(results[1]);
        std::cout << "Color=" << _machine._client->getColor() << std::endl;
    }
    else if (results[0] == "POS") {
        if (results[1] != _machine._client->getColor()) {
            std::cout << data << std::endl;
            updatePlayersPos(results);
        }
    }
    else {
        std::cout << "Received UDP Paquet: " << data << std::endl;
    }
}

void GameState::updatePlayersPos(std::vector<std::string> vector)
{
    if (vector[1] == "blue") {
        _ships[0].setPosition(std::stof(vector[2]), std::stof(vector[3]));
    }
    if (vector[1] == "red") {
        _ships[1].setPosition(std::stof(vector[2]), std::stof(vector[3]));
    }
    if (vector[1] == "yellow") {
        _ships[2].setPosition(std::stof(vector[2]), std::stof(vector[3]));
    }
    if (vector[1] == "green") {
        _ships[3].setPosition(std::stof(vector[2]), std::stof(vector[3]));
    }
}
