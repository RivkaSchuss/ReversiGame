//
// Created by Rivka Schuss on 27/12/2017.
//

#include "ThreadList.h"

ThreadList* ThreadList::instance = NULL;

ThreadList *ThreadList::getInstance() {
    if (instance == NULL) {
        instance = new ThreadList();
        return instance;
    } else {
        return instance;
    }
}

vector<int> *ThreadList::getList() {
    return this->list;
}

void ThreadList::add(int thread) {
    list->push_back(thread);
}
