/*
** EPITECH PROJECT, 2020
** indie_studio
** File description:
** file
*/

#ifndef INDIE_STUDIO_STATEMACHINE_HPP
#define INDIE_STUDIO_STATEMACHINE_HPP

#include "State.hpp"
#include <memory>
#include <stack>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Network/TcpClient.hpp"
#include "../Client.hpp"
#include "../Exception.hpp"

class StateMachine
{
    public:
        StateMachine();
        void run(std::unique_ptr<State> state);
        void nextState();
        void stateNotEmpty();
        void lastState();
        void pollEvents(sf::Event event);
        void update();
        void draw();
        bool running() const;
        void quit();
        std::shared_ptr<Client> _client;
        template <typename T>
        static std::unique_ptr<T> build(StateMachine& machine, sf::RenderWindow& window, bool replace = true);
    private:
        std::stack<std::unique_ptr<State>> _states;
        bool _resume;
        bool _running;
};

template <typename T>
std::unique_ptr<T> StateMachine::build(StateMachine& machine, sf::RenderWindow& display, bool replace)
{
	return std::make_unique<T>(machine, display, replace);
}

#endif //INDIE_STUDIO_STATEMACHINE_HPP
