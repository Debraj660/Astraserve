#pragma once
#include<bits/stdc++.h>
using namespace std;

class ThreadPool {
    vector<thread> workers;
    queue<function<void()>> tasks;
    mutex mtx;
    condition_variable cv;
    bool stop = false;

public:
    ThreadPool(int n);
    void enqueue(function<void()> task);
};
