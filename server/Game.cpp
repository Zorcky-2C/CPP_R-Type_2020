/*
** EPITECH PROJECT, 2020
** B_CPP_501_BDX_5_1_rtype_philippe_jacques_tatel
** File description:
** TODO: add description
*/

#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include "Game.hpp"
#include "Player.hpp"

Game::Game(Room *room) : _room(room)
{
    for (auto &i : this->_room->getPlayers()) {
        i->Send("GAMESTART\n");
    }
    std::thread t1([this] {
        try {
            boost::asio::io_service io_service;
            _server = std::make_shared<UdpServer>(io_service, this);
            io_service.run();
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    });
    t1.detach();
}

Game::~Game()
{
}

void Game::Start()
{
    std::cout << "Starting game for room " <<  _room->getName() << "..." << std::endl;

    while (true) {
        _clock.Start();



        _clock.End();
        _clock.Wait();
    }
}

void Game::handleReceive(std::string data, boost::asio::ip::udp::endpoint endpoint)
{
    std::vector<std::string> results;
    boost::algorithm::split(results, data, boost::is_any_of(" "));

    std::cout << "Received UDP Paquet: '" << data << "'" << std::endl;
    if (results[0] == "POS") {
        _server->sendToAll(data);
    }
}
