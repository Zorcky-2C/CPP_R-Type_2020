/*
** EPITECH PROJECT, 2020
** B_CPP_501_BDX_5_1_rtype_philippe_jacques_tatel
** File description:
** TODO: add description
*/

#ifndef B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_TCPSERVER_HPP
#define B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_TCPSERVER_HPP

#include <boost/array.hpp>
#include <boost/bind/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/thread.hpp>
#include <iostream>
#include <cstdint>
#include <iostream>
#include <list>
#include <memory>
#include "Player.hpp"
#include "Clock.hpp"
#include "Game.hpp"
#include "include.hpp"

class Server;

class TcpServer {
    public:
        TcpServer(int port, Server *server);
        using con_handle_t = std::list<Connection>::iterator;
        void HandleRead(con_handle_t con_handle, boost::system::error_code const & err, size_t bytes_transfered);
        void DoAsyncRead(con_handle_t con_handle);
        void HandleWrite(con_handle_t con_handle, std::shared_ptr<std::string> msg_buffer,
        boost::system::error_code const &err);
        void HandleAccept(con_handle_t con_handle, boost::system::error_code const &err);
        void StartAccept();
        void Listen();
        void Run();
        void Send(con_handle_t con_handle, std::string str);
    private:
        int _port;
        boost::asio::io_service _io_service;
        boost::asio::ip::tcp::acceptor _acceptor;
        std::list<Connection> _connections;
        Server *_server;
};

#endif //B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_TCPSERVER_HPP
