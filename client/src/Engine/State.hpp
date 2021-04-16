/*
** EPITECH PROJECT, 2020
** indie_studio
** File description:
** file
*/

#ifndef INDIE_STUDIO_STATE_HPP
#define INDIE_STUDIO_STATE_HPP

#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>

class StateMachine;

class State
{
    public:
        State(StateMachine& machine, sf::RenderWindow &display, bool replace = true);
        virtual ~State();
        State(const State&) = delete;
        State& operator=(const State&) = delete;
        virtual void pause() = 0;
        virtual void resume() = 0;
        virtual void pollEvents(sf::Event event) = 0;
        virtual void update() = 0;
        virtual void draw() = 0;
        std::unique_ptr<State> next();
        bool isReplacing() const;
    protected:
        StateMachine& _machine;
        sf::RenderWindow& _display;
        bool _replacing;
        std::unique_ptr<State> _next;
};

#endif //INDIE_STUDIO_STATE_HPP
