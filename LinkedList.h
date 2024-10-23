#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
template <typename T>
class LinkedList {
   private:
    Node<T> *head;

   public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        borraLista();
    }

    // O(1)
    bool insertarInicio(T newData) {
        Node<T> *newNode = nullptr;
        newNode = new (std::nothrow) Node(newData);

        if (newNode == nullptr)
            return false;

        newNode->data = newData;
        newNode->next = head;
        head = newNode;
        return true;
    }

    // O(n)
    bool insertarFinal(T newData) {
        Node<T> *newNode = nullptr;
        newNode = new (std::nothrow) Node(newData);

        if (newNode == nullptr)
            return false;

        if (head == nullptr) {
            head = newNode;
            return true;
        }

        Node<T> *temp = head;
        while (temp->next) {
            temp = temp->next;
        }

        temp->next = newNode;
        return true;
    }

    // O(n)
    void imprimirLista() {
        Node<T> *temp = head;

        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }

        std::cout << "\n";
    }
    // O(n)
    bool eliminaDato(T target) {
        if (!head) {
            return false;
        }

        Node<T> *previus;
        Node<T> *current = head;

        if (head->data == target) {
            head = current->next;
            delete current;
            return true;
        }

        while (current->next != nullptr) {
            if (current->data == target) {
                if (previus) {
                    previus->next = current->next;
                    delete current;
                    return true;
                }
            }
            previus = current;
            current = current->next;
        }
        return false;
    }

    // O(n)
    void borraLista() {
        while (head) {
            Node<T> *temp = head->next;
            delete head;
            head = temp;
        }
    }
};

#endif
