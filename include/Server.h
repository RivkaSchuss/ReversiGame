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
    void handleClient(int clientSocket);
private:

    int portNum;

};


#endif //REVERSIGAME_SERVER_H
