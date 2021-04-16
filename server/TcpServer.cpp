/*
** EPITECH PROJECT, 2020
** B_CPP_501_BDX_5_1_rtype_philippe_jacques_tatel
** File description:
** TODO: add description
*/

#include "TcpServer.hpp"
#include "Server.hpp"

TcpServer::TcpServer(int port, Server *server) : _port(port), _io_service(), _acceptor(_io_service), _connections(),
_server(server)
{
}

void TcpServer::HandleRead(con_handle_t con_handle, boost::system::error_code const &err, size_t bytes_transfered)
{
    if (bytes_transfered > 0) {
        std::istream is(&con_handle->read_buffer);
        std::string line;
        std::getline(is, line);
        _server->ExecuteCommand(line, con_handle);
    }
    if (!err) {
        DoAsyncRead(con_handle);
    } else {
        std::cerr << "Error: " << err.message() << std::endl;
        _connections.erase(con_handle);
    }
}

void TcpServer::DoAsyncRead(con_handle_t con_handle)
{
    auto handler = boost::bind(&TcpServer::HandleRead, this, con_handle,
                                boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred);
    boost::asio::async_read_until(con_handle->socket, con_handle->read_buffer, "\n", handler);
}

void TcpServer::HandleWrite(con_handle_t con_handle, std::shared_ptr<std::string> msg_buffer,
                              boost::system::error_code const &err)
{
    if (!err) {
        if (con_handle->socket.is_open()) {
            // Write completed successfully and connection is open
        }
    } else {
        std::cerr << "Error: " << err.message() << std::endl;
        _connections.erase(con_handle);
    }
}

void TcpServer::HandleAccept(con_handle_t con_handle, boost::system::error_code const &err)
{
    if (!err) {
        std::cout << "Connection from: " << con_handle->socket.remote_endpoint().address().to_string() << std::endl;
        Send(con_handle, "Hello from server!\n");
        con_handle->player = std::make_shared<Player>(con_handle);
        DoAsyncRead(con_handle);
    } else {
        std::cerr << "Error: " << err.message() << std::endl;
        _connections.erase(con_handle);
    }
    StartAccept();
}

void TcpServer::StartAccept()
{
    auto con_handle = _connections.emplace( _connections.begin(), _io_service);
    auto handler = boost::bind(&TcpServer::HandleAccept, this, con_handle, boost::asio::placeholders::error);
    _acceptor.async_accept(con_handle->socket, handler);
}

void TcpServer::Listen()
{
    auto endpoint = boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), _port);
    _acceptor.open(endpoint.protocol());
    _acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
    _acceptor.bind(endpoint);
    _acceptor.listen();
    StartAccept();
}

void TcpServer::Run()
{
    _io_service.run();
}

void TcpServer::Send(con_handle_t con_handle, std::string str)
{
    auto buff = std::make_shared<std::string>(str);
    auto handler = boost::bind(&TcpServer::HandleWrite, this, con_handle, buff, boost::asio::placeholders::error);
    boost::asio::async_write(con_handle->socket, boost::asio::buffer(*buff), handler);
    std::cout << "Sending:" << str << std::endl;
}