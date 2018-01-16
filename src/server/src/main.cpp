#include <iostream>



#include "../include/Server.h"
#include "../include/ThreadPool.h"
#include <unistd.h>
#include <fstream>
#include <pthread.h>

#define THREADS_NUM 5
#define TASKS_NUM 5

using namespace std;

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
    server.start();
    if (!server.getFlag()) {
        server.closeProcesses();
    }
    return 0;
}