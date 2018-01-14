//
// Created by Rivka Schuss on 14/01/2018.
//

#ifndef REVERSIGAME_THREADPOOL_H
#define REVERSIGAME_THREADPOOL_H


#include "../include/Task.h"
#include <queue>
#include <iostream>
#include <pthread.h>

using namespace std;

class ThreadPool {
public:
    ThreadPool(int threadsNum);
    void addTask(Task *task);
    void terminate();
    virtual ~ThreadPool();
private:
    queue<Task*> tasksQueue;
    pthread_t* threads;
    void executeTasks();
    bool stopped;
    pthread_mutex_t lock;

    static void* execute(void* arg);
};


#endif //REVERSIGAME_THREADPOOL_H
