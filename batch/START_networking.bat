@echo off
cd ../src/server
echo starting server files
echo YOU NEED IDE OPEN ALREADY OR START THIS SCRIPT TWICE
server.c
server.h
networking_server_win.cpp
networking_server_win.h
cd ../client
networking_client_win.cpp
networking_client_win.h
net_client.cpp
net_client.h
chidraqul6.cpp
chidraqul6.h

cd ../../
start MinGW_chidraqul6.bat