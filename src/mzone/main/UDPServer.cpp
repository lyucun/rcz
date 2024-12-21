#include "UDPServer.h"
#include <iostream>

UDPServer::UDPServer(unsigned short port)
    : socket(io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port)) {}

void UDPServer::start() {
    receive();
    io_context.run();
}

void UDPServer::receive() {
    char buffer[1024];
    
    // 接收数据
    socket.async_receive_from(boost::asio::buffer(buffer), remote_endpoint,
        [this, buffer](const boost::system::error_code& error, std::size_t bytes_transferred) {
            if (!error) {
                std::cout << "Received UDP message: " << std::string(buffer, bytes_transferred) << std::endl;
                
                // 发送确认消息回客户端
                std::string reply = "Hello from UDP server!\n";
                socket.send_to(boost::asio::buffer(reply), remote_endpoint);
            }
            receive(); // 继续接收新的数据
        });
}
