/*
** EPITECH PROJECT, 2023
** B_CPP_501_BDX_5_1_rtype_philippe_jacques_tatel
** File description:
** Created by valentinbreiz,
*/

#ifndef B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_UDPSERVER_HPP
#define B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_UDPSERVER_HPP

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/array.hpp>

class Game;
typedef std::vector<std::pair<std::string, boost::asio::ip::udp::endpoint>> ClientList;

class UdpServer
{
    public:
        UdpServer(boost::asio::io_service& io_service, Game *game);
        void startReceive();
        void handleReceive(const boost::system::error_code& error, std::size_t);
        void handleSend(boost::shared_ptr<std::string>, const boost::system::error_code&, std::size_t);
        void send(std::string str, boost::asio::ip::udp::endpoint endpoint);
        void addClient(boost::asio::ip::udp::endpoint endpoint);
        bool clientExists(boost::asio::ip::udp::endpoint endpoint);
        void sendToAll(std::string data);
    private:
        boost::asio::ip::udp::socket _socket;
        boost::asio::ip::udp::endpoint _remote_endpoint;
        enum { _max_length = 1024 };
        char _data[_max_length];
        Game *_game;
        ClientList _clients;
};

#endif //B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_UDPSERVER_HPP
