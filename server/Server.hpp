/*
** EPITECH PROJECT, 2020
** B-CPP-501-BDX-5-1-rtype
** File description:
** main
*/

#ifndef B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_SERVER_HPP
#define B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_SERVER_HPP

#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <queue>
#include "Game.hpp"
#include "TcpServer.hpp"
#include "Room.hpp"
#include <boost/algorithm/string.hpp>

class Server
{
    public:
        Server(int port);
        ~Server();
        int Start();
        Room *addRoom(std::string name);
        Room *getRoom(std::string name);
        void ExecuteCommand(std::string command, TcpServer::con_handle_t con_handle);

        void addCmd(std::vector<std::string> results, TcpServer::con_handle_t con_handle);
        void joinRoom(std::vector<std::string> results, TcpServer::con_handle_t con_handle);
        void leaveRoom(std::vector<std::string> results, TcpServer::con_handle_t con_handle);
        void setName(std::vector<std::string> results, TcpServer::con_handle_t con_handle);
        void setReady(std::vector<std::string> results, TcpServer::con_handle_t con_handle);
        void listPlayer(std::vector<std::string> results, TcpServer::con_handle_t con_handle);
        void listRoom(std::vector<std::string> results, TcpServer::con_handle_t con_handle);
    private:
        int _port;
        std::shared_ptr<TcpServer> _server;
        std::list<Room> _rooms;
        //std::set<std::shared_ptr<Player>> _players;
};

#endif //B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_SERVER_HPP
