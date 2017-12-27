//
// Created by Rivka Schuss on 27/12/2017.
//

#ifndef REVERSIGAME_THREADLIST_H
#define REVERSIGAME_THREADLIST_H

#include <pthread.h>
#include <iostream>
#include <vector>

using namespace std;
class ThreadList {
public:
    static ThreadList *getInstance();
    void add(int thread);
    vector<int> *getList();
private:
    ThreadList() {};
    static ThreadList *instance;
    vector<int> *list;
};


#endif //REVERSIGAME_THREADLIST_H
