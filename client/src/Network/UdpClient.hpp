/*
** EPITECH PROJECT, 2023
** B_CPP_501_BDX_5_1_rtype_philippe_jacques_tatel
** File description:
** Created by valentinbreiz,
*/

#ifndef B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_UDPCLIENT_HPP
#define B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_UDPCLIENT_HPP

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/array.hpp>

class GameState;

class UdpClient
{
    public:
        UdpClient(boost::asio::io_service &io_service, GameState *state);
        ~UdpClient();
        void startReceive();
        void handleReceive(const boost::system::error_code& error, std::size_t);
        void handleSend(boost::shared_ptr<std::string>, const boost::system::error_code&, std::size_t);
        void send(std::string str);
    private:
        boost::asio::ip::udp::socket *_socket;
        boost::asio::ip::udp::endpoint *_remote_endpoint;
        enum { _max_length = 1024 };
        char _data[_max_length];
        std::thread *_thread;
        GameState *_state;
};

#endif //B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_UDPCLIENT_HPP
