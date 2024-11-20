#ifndef STACK_H
#define STACK_H

#include "NodeStack.h"
class Stack {
   private:
    NodeStack *top;

   public:
    Stack();
    bool push(int newData);
    bool pop();
    int *getTop();
    bool isEmpty();
    void printList();
};

#endif
