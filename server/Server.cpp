/*
** EPITECH PROJECT, 2020
** B-CPP-501-BDX-5-1-rtype
** File description:
** main
*/

#include "Server.hpp"

Server::Server(int port) : _port(port)
{
    std::cout << "[INFO] Starting server at port " << _port << "..." << std::endl;
    _server = std::make_shared<TcpServer>(_port, this);
    _server->Listen();
}

Server::~Server()
{
    std::cout << "[INFO] Server closed" << std::endl;
}

int Server::Start()
{
    try {
        _server->Run();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}

Room *Server::addRoom(std::string name)
{
    _rooms.emplace_back(name);
    return (getRoom(name));
}

Room *Server::getRoom(std::string name)
{
    for (auto &i : this->_rooms) {
        if (i.getName() == name) {
            return (&i);
        }
    }
    return (NULL);
}

void Server::addCmd(std::vector<std::string> results, TcpServer::con_handle_t con_handle)
{
    Room *room = getRoom(results[1]);
    if (room == nullptr) {
        addRoom(results[1]);
        _server->Send(con_handle, "[INFO] ADD_ROOM " + results[1] + " [OK]\n");
    }
}

void Server::joinRoom(std::vector<std::string> results, TcpServer::con_handle_t con_handle)
{
    Room *room = getRoom(results[1]);
    if (room == nullptr) {
        std::cout << "[INFO] Room does not exist." << std::endl;
        _server->Send(con_handle, "[INFO] Room does not exist.\n");
    } else {
        room->Join(con_handle->player);
        _server->Send(con_handle, "[INFO] JOIN_ROOM " + results[1] + " [OK]\n");
    }
}

void Server::leaveRoom(std::vector<std::string> results, TcpServer::con_handle_t con_handle)
{
    Room *room = con_handle->player->getCurrentRoom();
    if (room == nullptr) {
        std::cout << "[INFO] Room does not exist." << std::endl;
        _server->Send(con_handle, "[INFO] Room does not exist.");
    } else {
        room->Leave(con_handle->player);
    }
}

void Server::setName(std::vector<std::string> results, TcpServer::con_handle_t con_handle)
{
    con_handle->player->setName(results[1]);
    _server->Send(con_handle, "[INFO] SET_NAME " + results[1] + " [OK]\n");
}

void Server::setReady(std::vector<std::string> results, TcpServer::con_handle_t con_handle)
{
    if (results[1] == "true") {
        con_handle->player->setReady(true);
        if (con_handle->player->getCurrentRoom()->isAllPlayerReady()) {
            std::thread t1([this, con_handle] {
                std::shared_ptr<Game> game = std::make_shared<Game>(con_handle->player->getCurrentRoom());
                game->Start();
            });
            t1.detach();
        } else
            _server->Send(con_handle, "NO GAMESTART\n");
    } else
        con_handle->player->setReady(false);
}

void Server::listPlayer(std::vector<std::string> results, TcpServer::con_handle_t con_handle)
{
    Room *room = getRoom(results[1]);
    if (room == nullptr) {
        std::cout << "[INFO] Room does not exist." << std::endl;
        _server->Send(con_handle, "[INFO] Room does not exist.");
    } else {
        _server->Send(con_handle, "[INFO] Players in room " + results[1] + ":\n");
        for (auto &i : room->getPlayers()) {
            _server->Send(con_handle, "-" + i->getName() + " " + (i->getReady() ? "true" : "false") + "\n");
        }
    }
}

void Server::listRoom(std::vector<std::string> results, TcpServer::con_handle_t con_handle)
{
    if (_rooms.empty() == true) {
        _server->Send(con_handle, "NO_ROOM\n");
    } else {
        std::string str = "";
        for (auto &i : this->_rooms) {
            str.append(i.getName() + ":");
        }
        _server->Send(con_handle, str + "\n");
    }
}

void Server::ExecuteCommand(std::string command, TcpServer::con_handle_t con_handle)
{
    std::vector<std::string> results;
    int i = 0;
    boost::algorithm::split(results, command, boost::is_any_of(" "));
    void (Server::*cmd[7])(std::vector<std::string>, TcpServer::con_handle_t) = 
        {&Server::addCmd, &Server::joinRoom, &Server::leaveRoom, &Server::setName, &Server::setReady, 
        &Server::listPlayer, &Server::listRoom};

    std::vector<std::string> cmdName = {"ADD_ROOM", "JOIN_ROOM", "LEAVE_ROOM", "SET_NAME", "SET_READY",
                                    "LIST_PLAYER", "LIST_ROOM"};

    for (auto it = cmdName.begin() ; it != cmdName.end(); ++it) {
        if (*it == results[0])
            (this->*cmd[i])(results, con_handle);
        else if (it == cmdName.end()+1) {
            std::cout << "[INFO] Unknown command." << std::endl;
            _server->Send(con_handle, "[INFO] Unknown command.\n");        
        }
        i++;
    }
}