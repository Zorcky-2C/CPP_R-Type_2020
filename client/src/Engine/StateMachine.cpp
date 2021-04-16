/*
** EPITECH PROJECT, 2020
** indie_studio
** File description:
** file
*/

#include "StateMachine.hpp"
#include "State.hpp"

#include <iostream>

StateMachine::StateMachine() : _resume { false }, _running { false }
{
	std::cout << "StateMachine Ctor" << std::endl;
}

void StateMachine::run(std::unique_ptr<State> state)
{
	_running = true;
	_states.push(std::move(state));
}

void StateMachine::stateNotEmpty()
{
    auto temp = _states.top()->next();
    if (temp != nullptr) {
        if (temp->isReplacing())
            _states.pop();
        else
            _states.top()->pause();
        _states.push(std::move(temp));
    }
}

void StateMachine::nextState()
{
    if (_resume) {
        if (!_states.empty())
            _states.pop();
        if (!_states.empty())
            _states.top()->resume();
        _resume = false;
    }
	if (!_states.empty())
        this->stateNotEmpty();
}

void StateMachine::lastState()
{
    _resume = true;
}

void StateMachine::pollEvents(sf::Event event)
{
    _states.top()->pollEvents(event);
}

void StateMachine::update()
{
	_states.top()->update();
}

void StateMachine::draw()
{
	_states.top()->draw();
}

bool StateMachine::running() const
{
	return (_running);
}

void StateMachine::quit()
{
	_running = false;
}