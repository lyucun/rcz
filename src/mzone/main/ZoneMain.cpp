#include <iostream>
#include <unistd.h> // fork 的头文件

int main() {
    pid_t pid = fork(); // 创建新进程

    if (pid < 0) {
        std::cerr << "Fork failed!" << std::endl;
        return 1; // 创建进程失败
    } else if (pid == 0) {
        // 子进程
        std::cout << "This is the child process." << std::endl;
    } else {
        // 父进程
        std::cout << "This is the parent process. Child PID: " << pid << std::endl;
    }

    return 0;
}
