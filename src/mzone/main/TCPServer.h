#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <boost/asio.hpp>
#include <string>

class TCPServer {
public:
    TCPServer(unsigned short port);
    void start();

private:
    void acceptConnection();
    void handleClient(boost::asio::ip::tcp::socket socket);

    boost::asio::io_context io_context;
    boost::asio::ip::tcp::acceptor acceptor;
};

#endif // TCPSERVER_H
