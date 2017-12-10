#include <iostream>

using namespace std;

#include "Server.h"
#include <fstream>

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
    //while (true) {
    server.start();
    server.stop();
    return 0;
}