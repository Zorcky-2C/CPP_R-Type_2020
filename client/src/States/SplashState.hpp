/*
** EPITECH PROJECT, 2020
** indie_studio
** File description:
** file
*/

#ifndef INDIE_STUDIO_SPLASHSTATE_HPP
#define INDIE_STUDIO_SPLASHSTATE_HPP

#include "../Engine/State.hpp"
#include "GameState.hpp"

class StateMachine;

class SplashState final : public State
{
    public:
        SplashState(StateMachine& machine, sf::RenderWindow &window, bool replace = true);
        ~SplashState();
        void pause() override;
        void resume() override;
        void pollEvents(sf::Event event) override;
        void update() override;
        void draw() override;
    private:
        //std::shared_ptr<gui::ProgressBar> _progressbar;
};

#endif //INDIE_STUDIO_SPLASHSTATE_HPP
