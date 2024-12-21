#include "TCPServer.h"
#include <iostream>

TCPServer::TCPServer(unsigned short port)
    : acceptor(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)) {}

void TCPServer::start() {
    acceptConnection();
    io_context.run();
}

void TCPServer::acceptConnection() {
    auto socket = boost::asio::ip::tcp::socket(io_context);
    acceptor.accept(socket);
    handleClient(std::move(socket));
}

void TCPServer::handleClient(boost::asio::ip::tcp::socket socket) {
    try {
        std::string message = "Hello from TCP server!\n";
        boost::asio::write(socket, boost::asio::buffer(message));
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    // 继续接受新的连接
    acceptConnection();
}
