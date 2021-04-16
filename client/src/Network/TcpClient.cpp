/*
** EPITECH PROJECT, 2023
** B-CPP-501-BDX-5-1-rtype-philippe-jacques.tatel
** File description:
** Created by valentinbreiz,
*/

#include "TcpClient.hpp"

TcpClient::TcpClient(boost::asio::io_service& io_service) : stopped_(false), socket_(io_service), _connected(false)
{
    this->_str_return = "";
}

void TcpClient::start(tcp::resolver::iterator endpoint_iter)
{
    startConnect(endpoint_iter);
}

void TcpClient::stop()
{
    stopped_ = true;
    boost::system::error_code ignored_ec;
    socket_.close(ignored_ec);
}

void TcpClient::startConnect(tcp::resolver::iterator endpoint_iter)
{
    if (endpoint_iter != tcp::resolver::iterator()) {
        std::cout << "Trying " << endpoint_iter->endpoint() << "...\n";
        socket_.async_connect(endpoint_iter->endpoint(),boost::bind(&TcpClient::handleConnect,this, _1, endpoint_iter));
    }
    else {
        stop();
    }
}

void TcpClient::handleConnect(const boost::system::error_code &ec, tcp::resolver::iterator endpoint_iter)
{
    if (stopped_)
        return;
    if (!socket_.is_open()) {
        std::cout << "Connect timed out\n";
        startConnect(++endpoint_iter);
    }
    else if (ec) {
        std::cout << "Connect error: " << ec.message() << "\n";
        socket_.close();
        startConnect(++endpoint_iter);
    }
    else {
        std::cout << "Connected to " << endpoint_iter->endpoint() << "\n";
        startRead();
        _connected = true;
    }
}

void TcpClient::startRead()
{
    boost::asio::async_read_until(socket_, input_buffer_, '\n',boost::bind(&TcpClient::HandleRead, this, _1));
}

void TcpClient::HandleRead(const boost::system::error_code &ec)
{
    if (stopped_)
        return;
    if (!ec) {
        std::string line;
        std::istream is(&input_buffer_);
        std::getline(is, line);
        if (!line.empty()) {
            _str_return = line;
        }
        startRead();
    }
    else {
        std::cout << "Error on receive: " << ec.message() << "\n";
    }
}

void TcpClient::startWrite(std::string str)
{
    if (stopped_)
        return;
    this->_str_return = "";
    auto buff = std::make_shared<std::string>(str);
    boost::asio::async_write(socket_, boost::asio::buffer(*buff),
                             boost::bind(&TcpClient::handleWrite, this, _1));
}

void TcpClient::handleWrite(const boost::system::error_code &ec)
{
    if (stopped_)
        return;
    if (!ec) {

    }
    else {
        std::cout << "Error on heartbeat: " << ec.message() << "\n";
        stop();
    }
}

std::string TcpClient::waitForResponse()
{
    std::string to_return = "";

    while (_str_return == "");
    to_return = _str_return;
    _str_return.clear();
    return (to_return);
}