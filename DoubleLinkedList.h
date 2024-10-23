#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "NodeDL.h"

template <typename T>
class DoubleLinkedList {
   private:
    NodeDL<T> *head;

   public:
    DoubleLinkedList() {
        head = nullptr;
    }
    ~DoubleLinkedList() {
        eliminarLista();
    }

    bool insertarInicio(T value) {
        NodeDL<T> *newnode = nullptr;
        newnode = new (std::nothrow) NodeDL<T>(value);
        if (!newnode)
            return false;

        if (head) {
            newnode->prev = nullptr;
            newnode->next = head;
            head->prev = newnode;
        }
        head = newnode;
        return true;
    }

    bool insertarFinal(T value) {
        NodeDL<T> *newNode = nullptr;
        newNode = new (std::nothrow) NodeDL<T>;

        if (!newNode)
            return false;

        newNode->data = value;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
            return true;
        }

        NodeDL<T> *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp->prev->next;

        return true;
    }

    bool eliminarDato(T value) {
        NodeDL<T> *temp = head;

        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp)
            return false;

        if (temp->next)
            temp->next->prev = temp->prev;
        if (temp->prev)
            temp->prev->next = temp->next;
        if (temp == head)
            head = temp->next;

        delete temp;
        return true;
    }

    bool eliminarLista() {
        if (head) {
            while (head) {
                NodeDL<T> *temp = head->next;
                delete head;
                head = temp;
            }
            head = nullptr;
        }
        return true;
    }

    void imprime() {
        NodeDL<T> *temp = head;

        while (temp) {
            std::cout << temp->data << " \n";
            temp = temp->next;
        }
        std::cout << "\n";
    }
};

#endif
