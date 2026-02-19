#pragma once
#include <bits/stdc++.h>
using namespace std;

class Logger {
    mutex mtx;
public:
    void log(const string& msg);
};

extern Logger logger;
