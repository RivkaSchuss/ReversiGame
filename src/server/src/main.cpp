#include <iostream>

using namespace std;

#include "../include/Server.h"
#include <fstream>

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
    //server.closeProcesses();
    return 0;
}