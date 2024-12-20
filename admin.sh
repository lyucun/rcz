#!/bin/bash
function DEBUG(){
    echo "Debugging server..."
    if [ ! -d "./debugbuild" ];then
        mkdir ./debugbuild
    fi
    cd ./debugbuild && cmake .. && make -j4
}

function DELETE(){
    echo "Deleting server..."
    rm -rf ./debugbuild
}

function START(){
    echo "Starting server..."
    cd ./debugbuild && ./src/mzone/zoneexe
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
        echo "Stopping server..."
        ;;
    restart)
        echo "Restarting server..."
        $0 stop
        $0 start
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
        echo "Usage: $0 {start|stop|restart}"
        exit 1
        ;;
esac