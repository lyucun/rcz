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


case $1 in
    start)
        echo "Starting server..."
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
    *)
        echo "Usage: $0 {start|stop|restart}"
        exit 1
        ;;
esac