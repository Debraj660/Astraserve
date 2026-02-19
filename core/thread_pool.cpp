#include "thread_pool.h"

ThreadPool::ThreadPool(int n) {
    for (int i = 0; i < n; i++) {
        workers.emplace_back([this]() {
            while (true) {
                function<void()> task;
                {
                    unique_lock<mutex> lock(mtx);
                    cv.wait(lock, [&]() { return stop || !tasks.empty(); });

                    if (stop && tasks.empty()) return;

                    task = (tasks.front());
                    tasks.pop();
                }

                task();
            }
        });
    }
}

void ThreadPool::enqueue(function<void()> task) {
    {
        lock_guard<mutex> lock(mtx);
        tasks.push(task);
    }
    cv.notify_one();
}
