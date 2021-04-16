/*
** EPITECH PROJECT, 2023
** B-CPP-501-BDX-5-1-rtype-philippe-jacques.tatel
** File description:
** Created by valentinbreiz,
*/

#ifndef B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_TCPCLIENT_HPP
#define B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_TCPCLIENT_HPP

#include <boost/asio/deadline_timer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/asio/write.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <string>

using boost::asio::deadline_timer;
using boost::asio::ip::tcp;

class TcpClient
{
    public:
        TcpClient(boost::asio::io_service& io_service);
        void start(tcp::resolver::iterator endpoint_iter);
        void stop();
        void startConnect(tcp::resolver::iterator endpoint_iter);
        void handleConnect(const boost::system::error_code& ec, tcp::resolver::iterator endpoint_iter);
        void startRead();
        void HandleRead(const boost::system::error_code& ec);
        void startWrite(std::string str);
        void handleWrite(const boost::system::error_code& ec);
        void check_deadline();
        std::string getReturn() { return (_str_return); }
        void setConnected(bool status) { _connected = status; }
        bool isConnected() { return (this->_connected); }
        std::string waitForResponse();
    private:
        bool stopped_;
        tcp::socket socket_;
        boost::asio::streambuf input_buffer_;
        std::string _str_return;
        bool _connected;
};

#endif //B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_TCPCLIENT_HPP
