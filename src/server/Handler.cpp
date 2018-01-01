//
// Created by Rivka Schuss on 27/12/2017.
//

#include "Handler.h"

/**
 * handles the client, parses the command received and builds the arguments.
 * @param manager the client manager.
 * @param clientSock the client socket.
 */
void Handler::handleClient(CommandsManager* manager, int clientSock) {
    //initializing the flag.
    char buffer[4096] = "flag";
    int expected_data_len = sizeof(buffer);
    //checking that the flag received is still in place.
    while (strcmp(buffer,"flag") == 0) {
        //reading from the client.
        int read_bytes = read(clientSock, buffer, expected_data_len);
        if (read_bytes < 0) {
            cout << "Error reading from the socket." << endl;
            exit(-1);
        }
        if (read_bytes == 0) {
            cout << "Connection is closed." << endl;
            exit(0);
        }
        //creating the vector of commands.
        vector<string> commands;
        string input(buffer);
        size_t spaceIndex = input.find(" ");
        //splitting the command.
        string command = input.substr(0, spaceIndex);
        string name = input.substr(spaceIndex + 1, input.length() - 1);
        //creating the vector of args
        vector<string> args;
        args.push_back(name);
        string sSock = intToString(clientSock);
        args.push_back(sSock);
        manager->executeCommand(command, args);
        //reading
        read_bytes = read(clientSock, buffer, expected_data_len);
        if (read_bytes == 0) {
            cout << "Connection is closed." << endl;
            exit(0);
        }
        if (read_bytes < 0) {
            cout << "Error reading from the server." << endl;
            return;
        }
        
    }
}

/**
 * changes an int to a string.
 * @param num the number to change.
 * @return the number in string form.
 */
string Handler::intToString(int num) {
    if (num == 0) {
        return "0";
    }
    else if (num == 1) {
        return "1";
    }
    else if (num == 2) {
        return "2";
    }
    else if (num == 3) {
        return "3";
    }
    else if (num == 4) {
        return "4";
    }
    else if (num == 5) {
        return "5";
    }
    else if (num == 6) {
        return "6";
    }
    else if (num == 7) {
        return "7";
    }
    else if (num == 8) {
        return "8";
    }
    else if (num == 9) {
        return "9";
    }
}
