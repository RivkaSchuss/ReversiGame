//
// Created by Rivka Schuss on 05/12/2017.
//

#ifndef REVERSIGAME_SERVER_H
#define REVERSIGAME_SERVER_H


class Server {
public:
    Server(int portNum);
    ~Server();
    void start();
    void stop();
    int getPortNum();
    int getClientSock1();
    int getClientSock2();
    void handleClient(int clientSocket);
private:
    int sock;
    int portNum;
    int client_sock1;
    int client_sock2;

};


#endif //REVERSIGAME_SERVER_H
