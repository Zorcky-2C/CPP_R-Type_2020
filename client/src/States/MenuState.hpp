/*
** EPITECH PROJECT, 2023
** B-CPP-501-BDX-5-1-rtype-philippe-jacques.tatel
** File description:
** Created by valentinbreiz,
*/
#ifndef B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_MENUSTATE_HPP
#define B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_MENUSTATE_HPP

#include "../Engine/State.hpp"
#include "GameState.hpp"

class StateMachine;

class MenuState final : public State
{
    public:
        MenuState(StateMachine& machine, sf::RenderWindow &window, bool replace = true);
        ~MenuState();
        void pause() override;
        void resume() override;
        void pollEvents(sf::Event event) override;
        void update() override;
        void draw() override;
    private:
        sf::Text _join_lobby;
        sf::Text _options;
        sf::Text _exit;
        sf::Texture _logo_texture;
        sf::Sprite _logo;
        sf::Texture _bg_texture;
        sf::Sprite _bg;
        int _menu_index;
        sf::Sound _sound;
        sf::SoundBuffer _buffer;
};

#endif //B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_MENUSTATE_HPP
