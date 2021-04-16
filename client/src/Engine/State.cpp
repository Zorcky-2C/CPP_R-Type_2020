/*
** EPITECH PROJECT, 2020
** indie_studio
** File description:
** file
*/

#include "State.hpp"

State::State(StateMachine& machine, sf::RenderWindow &display, const bool replace)
: _machine { machine }, _display { display }, _replacing { replace }
{
    std::cout << "State Ctor" << std::endl;
}

State::~State()
{
    std::cout << "State Dtor" << std::endl;
}

std::unique_ptr<State> State::next()
{
	return (std::move(_next));
}

bool State::isReplacing() const
{
	return (_replacing);
}