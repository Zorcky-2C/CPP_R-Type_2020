/*
** EPITECH PROJECT, 2020
** B-CPP-501-BDX-5-1-rtype
** File description:
** main
*/

#include <iostream>
#include <memory>
#include "Server.hpp"

int main(int argc, char **argv)
{
    int port = 4242;
    std::shared_ptr<Server> server;

    if (argc >= 2) {
        port = std::atoi(argv[1]);
    }
    server = std::make_shared<Server>(port);
    try {
        server->Start();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}