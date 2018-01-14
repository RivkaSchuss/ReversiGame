#include <iostream>

using namespace std;

#include "../include/Server.h"
#include "ThreadPool.h"
#include <fstream>

#define THREADS_NUM 5
#define TASKS_NUM 3

void* print(void* taskId);
/**
 * the main for the server.
 **/
int main() {
    string sPort, line;
    int port = 0;
    ifstream file;
    file.open("../exe/serverInfo");
    if (file.is_open()) {
        while (getline(file, line)) {
            sPort = line;
        }
        file.close();
    }
    sscanf(sPort.c_str(), "%d", &port);
    Server server(port);
    //server.start();
    if (!server.getFlag()) {
        server.closeProcesses();
    }

    ThreadPool pool(THREADS_NUM);
    Task* tasks[TASKS_NUM];

    for (int i = 0; i < TASKS_NUM; i++) {
        tasks[i] = new Task(print, (void*) i);
        pool.addTask(tasks[i]);
    }
    char ch;
    cout << "Type a char to exit" << endl;
    cin >> ch;
    pool.terminate();
    for (int i = 0; i < TASKS_NUM; i++) {
        delete tasks[i];
    }
    cout << "End of main." << endl;
    return 0;
}

void* print(void* taskId) {
    long id = (long) taskId;
    for (int i = 1; i <= 3; i++) {
        cout << "Task " << id << " prints: " << i << endl;
        sleep(1);
    }
    return NULL;
}