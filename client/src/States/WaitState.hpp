/*
** EPITECH PROJECT, 2023
** B-CPP-501-BDX-5-1-rtype-philippe-jacques.tatel
** File description:
** Created by valentinbreiz,
*/

#ifndef B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_WAITSTATE_HPP
#define B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_WAITSTATE_HPP

#include "../Engine/State.hpp"
#include "GameState.hpp"
#include <boost/algorithm/string.hpp>

class StateMachine;

class WaitState final : public State
{
    public:
        WaitState(StateMachine& machine, sf::RenderWindow &window, bool replace = true);
        ~WaitState();
        void pause() override;
        void resume() override;
        void pollEvents(sf::Event event) override;
        void update() override;
        void draw() override;
    private:
        sf::Texture _bg_texture;
        sf::Sprite _bg;
        sf::Texture _window_texture;
        sf::Sprite _window;
        sf::Text _text;
        sf::Text _text_room;
};

#endif //B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_WAITSTATE_HPP
