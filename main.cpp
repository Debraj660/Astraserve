#include "core/server.h"

int main() {
    WebServer server(8080, 8);
    server.start();
}
