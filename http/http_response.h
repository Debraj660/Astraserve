#pragma once
#include <string>
using namespace std;

class HttpResponse {
public:
    static string serveFile(const string& path);
};
