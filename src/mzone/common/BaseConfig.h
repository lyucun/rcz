#ifndef BASE_CONFIG_
#define BASE_CONFIG_

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>  // 引入 JSON 解析器
#include <string>
#include <iostream>

class BaseConfig {
public:
    virtual ~BaseConfig() = default;

protected:
    bool loadConfig(const std::string& filename) {
        // 尝试读取 JSON 文件，并返回操作结果
        if (access(filename.c_str(), R_OK) != 0) { // 检查文件是否存在以及可读
            std::cerr << "Config file does not exist or is not readable: " << filename << std::endl;
            return false; // 文件不存在或不可读
        }

        try {
            boost::property_tree::read_json(filename, config);  // 读取 JSON 配置
            return true; // 成功加载配置
        } catch (const std::exception& e) {
            std::cerr << "Error reading config file: " << e.what() << std::endl;
            return false; // 加载失败
        }
    }

    boost::property_tree::ptree config;  // 存储配置数据
};

#endif
