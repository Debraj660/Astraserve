#include "http_request.h"
#include <sstream>

HttpRequest parseRequest(const string& req) {
    istringstream stream(req);
    HttpRequest r;
    stream >> r.method >> r.path;
    return r;
}
