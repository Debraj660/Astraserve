#include "socket.h"
#include <arpa/inet.h>
#include<bits/stdc++.h>

int Socket::createServer(int port) {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 100);

    return server_fd;
}
