/*
** EPITECH PROJECT, 2023
** B-CPP-501-BDX-5-1-rtype-philippe-jacques.tatel
** File description:
** Created by valentinbreiz,
*/

#ifndef B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_LOBBYSTATE_HPP
#define B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_LOBBYSTATE_HPP

#include "../Engine/State.hpp"
#include "GameState.hpp"
#include <boost/algorithm/string.hpp>

class StateMachine;

class LobbyState final : public State
{
    public:
        LobbyState(StateMachine& machine, sf::RenderWindow &window, bool replace = true);
        ~LobbyState();
        void pause() override;
        void resume() override;
        std::string askrequest(std::string request);
        void setrooms();
        void pollEvents(sf::Event event) override;
        void update() override;
        void draw() override;
    private:
        sf::Texture _bg_texture;
        sf::Sprite _bg;
        sf::Texture _window_texture;
        sf::Sprite _window;
        sf::Text _playerText;
        std::string _playerInput;
        std::string _rooms_str;
        std::vector<std::string> _rooms;
        bool _refresh;
        int _select_room;
        std::string _current_rooms;
        sf::Clock _clock;
};

#endif //B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_LOBBYSTATE_HPP
