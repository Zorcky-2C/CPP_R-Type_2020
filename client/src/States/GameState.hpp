/*
** EPITECH PROJECT, 2023
** B_CPP_501_BDX_5_1_rtype_philippe_jacques_tatel
** File description:
** Created by valentinbreiz,
*/

#ifndef B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_GAMESTATE_HPP
#define B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_GAMESTATE_HPP

#include "../Engine/State.hpp"
#include "../Engine/StateMachine.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../Sprite/sprite.hpp"
#include "../Window/window.hpp"
#include "../Event/event.hpp"
#include "../Text/text.hpp"
#include "../Network/UdpClient.hpp"

class StateMachine;

class GameState final : public State
{
    public:
        GameState(StateMachine& machine, sf::RenderWindow &window, bool replace = true);
        ~GameState();
        void pause() override;
        void resume() override;
        void pollEvents(sf::Event event) override;
        void update() override;
        void draw() override;
        void setUpKey();
        void setDownKey();
        void setLeftKey();
        void setRightKey();
        void setAttackKey();
        void handleReceive(std::string data);
        void updatePlayersPos(std::vector<std::string> vector);
    private:
        sf::Event _event;
        Sprite _sprite;
        Window _window;
        Event _eventE;
        Text _text;
        int _key;
        sf::Vector2f _pos;
        sf::Vector2f _posTextScore;
        sf::Vector2f _posTextScorePoint;
        int _score;
        std::shared_ptr<UdpClient> _client;
        boost::asio::io_service io_service;

        std::vector<sf::Sprite> _ships;

        sf::Texture texture;
};

#endif //B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_GAMESTATE_HPP
