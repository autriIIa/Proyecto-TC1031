#include "Stack.h"

#include <iostream>

Stack::Stack() {
    top = nullptr;
}

bool Stack::push(int newData) {
    NodeStack *newNode = nullptr;
    newNode = new (std::nothrow) NodeStack(newData);

    if (newNode == nullptr)
        return false;

    if (!top) {
        top = newNode;
        return true;
    }

    newNode->next = top;
    top = newNode;
    return true;
}

bool Stack::pop() {
    if (isEmpty())
        return false;
    else {
        NodeStack *temp = top->next;
        delete top;
        top = temp;
        return true;
    }
}

bool Stack::isEmpty() {
    if (!top) {
        return true;
    } else {
        return false;
    }
}

int *Stack::getTop() {
    if (!top)
        return nullptr;
    return &top->data;
}

void Stack::printList() {
    NodeStack *temp = top;

    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    std::cout << "\n";
}
