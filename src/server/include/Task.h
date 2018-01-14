//
// Created by Rivka Schuss on 14/01/2018.
//

#ifndef REVERSIGAME_TASK_H
#define REVERSIGAME_TASK_H

class Task {
public:
    Task(void* (*func)(void* arg), void* arg) : func(func), arg(arg) {}
    void execute() {
        func(arg);
    }
private:
    void* (*func)(void *arg);
    void* arg;
};
#endif //REVERSIGAME_TASK_H
