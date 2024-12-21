#!/bin/bash

function DEBUG(){
    echo "Debugging server..."
    if [ ! -d "./debugbuild" ]; then
        mkdir ./debugbuild
    fi
    cd ./debugbuild && cmake .. && make -j1

#!/bin/bash
# 生成启动脚本
cat <<EOF > start.sh
#!/bin/bash
cd \$(dirname \$0) || exit 1  # 进入脚本目录，如果失败则退出
./src/mzone/zoneexe > server.log 2>&1 &  # 后台运行，并重定向输出到日志
PID=\$!  # 抓取zoneexe的PID
if [ -z "\$PID" ]; then  # 检查PID是否为空
    echo "zoneexe 启动失败" >> server.log
    exit 1
else
    echo \$PID > zone.pid  # 记录zoneexe进程的PID
    echo "zoneexe 启动成功，PID: \$PID" >> server.log
fi
EOF


    cat <<EOF > stop.sh
#!/bin/bash
if [ -f zone.pid ]; then
    PID=\$(cat zone.pid)
    echo "Stopping server with PID \$PID..."
    kill \$PID
    rm -f zone.pid
else
    echo "No PID file found. Server may not be running."
fi
EOF

    # 给予执行权限
    chmod +x start.sh
    chmod +x stop.sh

    echo "启动和停止脚本已生成：debugbuild/start.sh 和 debugbuild/stop.sh"
}

function DELETE(){
    echo "Deleting server..."
    rm -rf ./debugbuild
}

function START(){
    echo "Starting server..."
    # 调用启动脚本
    cd ./debugbuild && ./start.sh
}

function STOP(){
    echo "Stopping server..."
    # 调用停止脚本
    cd ./debugbuild && ./stop.sh
}

function CLEAER(){
    echo "Cleaning server..."
    cd ./debugbuild && make clean
}

case $1 in
    start)
        START
        ;;    
    stop)
        STOP
        ;;    
    restart)
        echo "Restarting server..."
        STOP
        START
        ;;    
    debug)
        DEBUG
        ;;    
    delete)
        DELETE
        ;;    
    clean)
        CLEAER
        ;;
    *)
        echo "Usage: $0 {start|stop|restart|debug|delete|clean}"
        exit 1
        ;;
esac
