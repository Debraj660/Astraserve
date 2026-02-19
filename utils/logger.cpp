#include "logger.h"

Logger logger;

void Logger::log(const string& msg) {
    lock_guard<mutex> lock(mtx);
    cout << msg << endl;
}
