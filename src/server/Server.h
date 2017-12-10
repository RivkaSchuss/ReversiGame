//
// Created by yarin on 06/12/17.
//

#ifndef REVERSIGAME_SERVER_H
#define REVERSIGAME_SERVER_H


class Server {
public:
    Server(int portNum);
    ~Server();
    void start();
    void stop();
    void handleClient(int clientSocket);
private:
    int sock;
    int portNum;
    int client_sock1;
    int client_sock2;
    bool exit;

};


#endif //REVERSIGAME_SERVER_H