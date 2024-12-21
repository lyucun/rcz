#include <iostream>
#include <filesystem> // C++17 起需要包含这个头文件
#include "TCPServer.h"
#include "UDPServer.h"
#include <thread>
#include "TCPConfigLoader.h"

using namespace std;

int main()
{
    // 输出当前的工作路径
    // cout << "Current working directory: " << filesystem::current_path() << endl;

    CTCPConfigLoader configLoader("../config/mzone/config.json"); // 实例化并加载配置
    // 检查配置是否成功加载
    if (configLoader.isConfigLoaded())
    {
        cout << "Configuration loaded successfully." << endl;
        cout << configLoader.getServerIP() << endl;
    }
    else
    {
        std::cerr << "Configuration was not loaded, so cannot perform actions." << std::endl;
    }

    // 创建TCP和UDP服务器对象（根据需要可以取消注释）
    /*
    TCPServer tcpServer(12345);
    UDPServer udpServer(12346);

    // 使用线程启动TCP和UDP服务器
    std::thread tcpThread([&tcpServer]() { tcpServer.start(); });
    std::thread udpThread([&udpServer]() { udpServer.start(); });

    // 等待线程结束
    tcpThread.join();
    udpThread.join();
    */

    return 0;
}
