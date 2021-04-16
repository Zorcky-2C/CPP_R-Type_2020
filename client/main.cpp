/*
** EPITECH PROJECT, 2020
** B-CPP-501-BDX-5-1-rtype-philippe-jacques.tatel
** File description:
** game
*/

#include "src/Engine/StateMachine.hpp"
#include "src/States/SplashState.hpp"

int main(void)
{
    StateMachine m_machine;
    sf::RenderWindow m_window;
    sf::Event event;

    m_window.create({ 800, 600 }, "R-Type", sf::Style::Titlebar | sf::Style::Close);
    m_window.setFramerateLimit(60);
    m_window.setVerticalSyncEnabled(true);

    // Initialize the engine
    m_machine.run(StateMachine::build<SplashState>(m_machine, m_window, true));

    // Main loop
    while (m_machine.running() && m_window.isOpen()) {
        m_machine.nextState();
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_machine.quit();
            m_machine.pollEvents(event);
        }
        m_machine.update();
        m_machine.draw();
    }
}