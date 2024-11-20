#pragma once

#include "Node.h"
template <typename T>
class LinkedList {
   protected:
   public:
    Node<T> *head;
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

    bool imprimirLista(std::ofstream &file) {
        if (!file)
            return false;

        Node<T> *temp = head;

        while (temp) {
            file << temp->data << " ";
            temp = temp->next;
        }
        return true;
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

    // O(n)
    int cuentaValor(T target) {
        int count = 0;

        if (!head)
            return -1;

        Node<T> *temp = head;

        while (temp) {
            if (temp->data == target)
                count++;
            temp = temp->next;
        }

        return count;
    }

    bool findData(T target) {
        Node<T> *temp = head;

        while (temp) {
            if (temp->data == target)
                return true;
            temp = temp->next;
        }

        return false;
    }
};

// template <typename T>
// class iterator {
//    private:
//     Node<T> *current;

//    public:
//     iterator(Node<T> *node) : current(node) {
//     }

//     T &operator*() {
//         return current->data;
//     }

//     iterator &operator++() {
//         if (current)
//             current = current->next;
//         return *this;
//     }

//     bool operator==(const iterator &other) const {
//         return current == other.current;
//     }

//     bool operator!=(const iterator &other) const {
//         return current != other.current;
//     }
// };

// iterator begin() {
//     return iterator(head);
// }

// iterator end() {
//     return iterator(nullptr);
// }
