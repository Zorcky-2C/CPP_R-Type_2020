/*
** EPITECH PROJECT, 2020
** B_CPP_501_BDX_5_1_rtype_philippe_jacques_tatel
** File description:
** TODO: add description
*/

#ifndef B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_INCLUDE_HPP
#define B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_INCLUDE_HPP

#include <boost/asio.hpp>

class Player;

struct Connection {
    Connection(boost::asio::io_service &io_service) : socket(io_service), read_buffer() { }
    Connection(boost::asio::io_service & io_service, size_t max_buffer_size) : socket(io_service), read_buffer(max_buffer_size) { }
    boost::asio::ip::tcp::socket socket;
    boost::asio::streambuf read_buffer;
    std::shared_ptr<Player> player;
};

#endif //B_CPP_501_BDX_5_1_RTYPE_PHILIPPE_JACQUES_TATEL_INCLUDE_HPP
