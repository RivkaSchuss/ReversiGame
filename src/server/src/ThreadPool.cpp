//
// Created by Rivka Schuss on 14/01/2018.
//

#include "../include/ThreadPool.h"
#include <unistd.h>
#include <pthread.h>

/**
 * constructor. creates the number of threads sent.
 * @param threadsNum the number of threads to create.
 */
ThreadPool::ThreadPool(int threadsNum) : stopped(false) {
    threads = new pthread_t[threadsNum];
    for (int i = 0; i < threadsNum; i++) {
        pthread_create(threads + i, NULL, execute, this);
    }
    pthread_mutex_init(&lock, NULL);
}

/**
 * when a thread is created, the thread calls this function to execute.
 * @param arg the thread pool class we are now found in.
 * @return null.
 */
void* ThreadPool::execute(void *arg) {
    ThreadPool* pool = (ThreadPool*) arg;
    //thread pool executes his tasks.
    pool->executeTasks();
}

/**
 * adds the task to the queue of tasks.
 * @param task the task to add.
 */
void ThreadPool::addTask(Task *task) {
    tasksQueue.push(task);
}

/**
 * executes the tasks found in the queue.
 */
void ThreadPool::executeTasks() {
    //while the boolean is false
    while (!stopped) {
        //locks
        pthread_mutex_lock(&lock);
        //if there are still tasks in the queue, execute the front task
        if (!tasksQueue.empty()) {
            Task* task = tasksQueue.front();
            tasksQueue.pop();
            pthread_mutex_unlock(&lock);
            task->execute();
        } else {
            //if the queue is empty
            pthread_mutex_unlock(&lock);
            sleep(1);
        }
    }
}

void ThreadPool::terminate() {
    //destroys the mutex
    pthread_mutex_destroy(&lock);
    stopped = true;
}

ThreadPool::~ThreadPool() {
    delete[] threads;
}