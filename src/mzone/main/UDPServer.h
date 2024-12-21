#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <boost/asio.hpp>
#include <string>

class UDPServer {
public:
    UDPServer(unsigned short port);
    void start();

private:
    void receive();

    boost::asio::io_context io_context;
    boost::asio::ip::udp::socket socket;
    boost::asio::ip::udp::endpoint remote_endpoint;
};

#endif // UDPSERVER_H
