//
// Created by Rivka Schuss on 05/12/2017.
//

#ifndef REVERSIGAME_CLIENT_H
#define REVERSIGAME_CLIENT_H


class Client {
public:
    Client(const char *serverIP, int serverPort);
    ~Client();
    void connectToServer();
    void sendMove(int row, int col);
private:
    const char* serverIP;
    int serverPort;
    int clientSocket;
};


#endif //REVERSIGAME_CLIENT_H
