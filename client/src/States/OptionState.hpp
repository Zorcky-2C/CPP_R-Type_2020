/*
** EPITECH PROJECT, 2020
** B-CPP-501-BDX-5-1-rtype-philippe-jacques.tatel
** File description:
** OptionState
*/

#ifndef B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_OPTIONSTATE_HPP
#define B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_OPTIONSTATE_HPP

#include "../Engine/State.hpp"
#include "GameState.hpp"
#include <boost/algorithm/string.hpp>

class StateMachine;

class OptionState final : public State
{
    public:
        OptionState(StateMachine& machine, sf::RenderWindow &window, bool replace = true);
        ~OptionState();
        void pause() override;
        void resume() override;
        void pollEvents(sf::Event event) override;
        void update() override;
        void draw() override;

    protected:
    private:
        sf::Event _event;
        Sprite _sprite;
        Window _window;
        Text _text;
        int _key;
        sf::Texture _bg_texture;
        sf::Sprite _bg;
        sf::Texture _logo_texture;
        sf::Sprite _logo;
        sf::Texture _popup_texture;
        sf::Sprite _popup;
        sf::Texture _slider_texture;
        sf::Sprite _slider;
};

#endif //B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_OPTIONSTATE_HPP
