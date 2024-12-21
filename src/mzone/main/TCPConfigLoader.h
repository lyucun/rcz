#include "BaseConfig.h"
#include <iostream>
#include <string>
#include "ZoneLog.h"
using namespace std;

class CTCPConfigLoader : public BaseConfig
{
public:
    CTCPConfigLoader(const std::string &FileName) : configLoaded(false)
    {
        if (!loadConfig(FileName))
        { // 使用 if-else 检查加载是否成功
            LOG_ERR( "Failed to load config file: {}", FileName);            
        }
        else
        {
            LOG_DBG("Config file loaded successfully: {}", FileName);
            configLoaded = true; // 成功加载后设置标志
        }
    }

    bool isConfigLoaded() const
    {
        return configLoaded; // 返回加载状态
    }

    string getServerIP() const
    {
        if (config.get_child_optional("IP"))
        {
            return config.get<string>("IP");
        }
        return "";
    }
    string getServerPort() const
    {
        if (config.get_child_optional("Port"))
        {
            return config.get<string>("Port");
        }
        return "";
    }

private:
    bool configLoaded; // 用于记录配置是否成功加载
};
