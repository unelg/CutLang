#!/bin/bash

start_vnc() {
    echo "Starting VNC server..."
    nvnc=$((`vncserver -list | wc -l`-4))
    vncdisplay=":$(($nvnc+1))"
    vncport=":$(($nvnc+5901))"
    Xtigervnc $vncdisplay -depth 24 -geometry $GEOMETRY -br -rfbport=$vncport -PasswordFile=$HOME/.vnc/passwd > $HOME/.vnc/Xtigervnc.log 2>&1 &
    export ORIGINAL_DISPLAY=$DISPLAY
    export DISPLAY=$vncdisplay
    sleep 2
    xsetroot -solid grey
    vncconfig -iconic &
    fluxbox  > $HOME/.vnc/fluxbox.log 2>&1 &
    /usr/local/novnc/utils/novnc_proxy --vnc localhost:5901 > $HOME/.vnc/novnc_proxy.log 2>&1 &
    echo -e "VNC connection points:"
    echo -e "\tVNC viewer address: 127.0.0.1:$vncport"
    echo -e "\tHTTP access: http://127.0.0.1:6080/vnc.html"
}

stop_vnc() {
    nvnc=$((`vncserver -list | wc -l`-4))
    for i in $(seq 1 $nvnc); do
        vncserver -kill :${i}
    done
    export DISPLAY=$ORIGINAL_DISPLAY
}

clean_vnc() {
    stop_vnc
}