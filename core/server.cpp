#include "server.h"
#include "../network/socket.h"
#include "../utils/logger.h"
#include "../http/http_request.h"
#include "../http/http_response.h"

#include <unistd.h>
#include <sys/socket.h>
#include<bits/stdc++.h>

using namespace std;

HttpRequest parseRequest(const string& req);

WebServer::WebServer(int p, int threads)
    : port(p), pool(threads) {}

void handleClient(int client_fd) {
    char buffer[4096] = {0};
    read(client_fd, buffer, sizeof(buffer));

    HttpRequest req = parseRequest(buffer);

    if (req.path == "/") req.path = "/index.html";

    string response = HttpResponse::serveFile(req.path);

    write(client_fd, response.c_str(), response.size());
    close(client_fd);

    logger.log("Served: " + req.path);
}

void WebServer::start() {
    int server_fd = Socket::createServer(port);

    logger.log("Server started at port " + to_string(port));

    while (true) {
        int client_fd = accept(server_fd, nullptr, nullptr);

        pool.enqueue([=]() {
            handleClient(client_fd);
        });
    }
}
