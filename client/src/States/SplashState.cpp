/*
** EPITECH PROJECT, 2020
** indie_studio
** File description:
** file
*/

#include "../Engine/StateMachine.hpp"
#include "SplashState.hpp"
#include "MenuState.hpp"

SplashState::SplashState(StateMachine& machine, sf::RenderWindow &window, const bool replace)
: State{ machine, window, replace }
{
	std::cout << "Splash Ctor" << std::endl;
    std::string path = findFolder();
    _machine._client = std::make_shared<Client>();

    if (!_machine._client->_music.openFromFile(path + "/Ressources/Music/music.ogg")) {
        std::cout << "Can't load music!\n";
        // erreur...
    }
    _machine._client->_music.setVolume(20);
    _machine._client->_music.play();
    //_progressdisplay = std::make_shared<ProgressDisplay>(window);
}

SplashState::~SplashState()
{
    std::cout << "Splash Dtor" << std::endl;
}

void SplashState::pause()
{
	std::cout << "Options Pause" << std::endl;
}

void SplashState::resume()
{
    std::cout << "Options Resume" << std::endl;
}

void SplashState::pollEvents(sf::Event event)
{
}

void SplashState::update()
{
    _next = StateMachine::build<MenuState>(_machine, _display, true);
}

void SplashState::draw()
{
}
