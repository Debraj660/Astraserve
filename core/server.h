#pragma once
#include "thread_pool.h"

class WebServer {
    int port;
    ThreadPool pool;

public:
    WebServer(int port, int threads);
    void start();
};
