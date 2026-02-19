#include "http_response.h"
#include <fstream>
#include <sstream>

string HttpResponse::serveFile(const string& path) {
    ifstream file("static" + path);

    if (!file.is_open())
        return "HTTP/1.1 404 Not Found\r\n\r\n";

    stringstream buffer;
    buffer << file.rdbuf();

    string body = buffer.str();

    return "HTTP/1.1 200 OK\r\nContent-Length: " +
           to_string(body.size()) +
           "\r\n\r\n" + body;
}
