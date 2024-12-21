// Singleton.h
#ifndef SINGLETON_H
#define SINGLETON_H

#include <mutex>
#include <iostream>

template<typename T>
class Singleton {
public:
    // 获取单例实例的公共接口
    static T* getInstance() {
        std::call_once(initInstanceFlag, &Singleton::initInstance);
        return instance;
    }

    // 删除复制构造函数和赋值操作符
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

protected:
    Singleton() = default;  // 构造函数私有化
    ~Singleton() = default; // 析构函数私有化

private:
    static void initInstance() {
        instance = new T(); // 动态分配内存
    }

    static T* instance; // 静态指针，用于存储单例实例
    static std::once_flag initInstanceFlag; // 确保初始化只调用一次
};

// 静态成员初始化
template<typename T>
T* Singleton<T>::instance = nullptr;

template<typename T>
std::once_flag Singleton<T>::initInstanceFlag;

#endif // SINGLETON_H
