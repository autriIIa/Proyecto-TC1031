#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <ctime>
#include <iostream>
#include <string>

#include "NodeBT.h"
template <typename T>

class BinaryTree {
   private:
    NodeBT<T> *root;
    int size;
    bool insertarRecursivo(NodeBT<T> *&nodo, T dato) {
        if (nodo == nullptr) {
            nodo = new (std::nothrow) NodeBT<T>(dato);
            if (!nodo)
                return false;
            size++;
            return true;
        }

        if (dato < nodo->dato)
            return insertarRecursivo(nodo->left, dato);
        if (dato > nodo->dato)
            return insertarRecursivo(nodo->right, dato);

        return false;
    }

    bool buscarRecursivo(NodeBT<T> *&nodo, T dato) {
        if (nodo == nullptr)
            return false;

        if (dato > nodo->dato)
            return buscarRecursivo(nodo->left, dato);
        if (dato < nodo->dato)
            return buscarRecursivo(nodo->right, dato);
        return true;
    }

    NodeBT<T> *getRandomNodeRecursivo(NodeBT<T> *node, int index, int &count) {
        if (node == nullptr)
            return nullptr;

        NodeBT<T> *leftResult = getRandomNodeRecursivo(node->left, index, count);
        if (leftResult != nullptr)
            return leftResult;

        if (count == index)
            return node;
        count++;

        return getRandomNodeRecursivo(node->right, index, count);
    }

    NodeBT<T> *reemplazaLeft(NodeBT<T> *nodo) {
        NodeBT<T> *rightMostFromleft = nullptr, *parent = nullptr;

        parent = nodo;
        rightMostFromleft = nodo->left;

        while (rightMostFromleft->right) {
            parent = rightMostFromleft;
            rightMostFromleft = rightMostFromleft->right;
        }

        nodo->dato = rightMostFromleft->dato;

        if (parent == nodo)
            parent->left = rightMostFromleft->left;
        else
            parent->right = rightMostFromleft->left;

        return rightMostFromleft;
    }

    void eliminarArbol(NodeBT<T> *node) {
        if (!node)
            return;
        eliminarArbol(node->left);
        eliminarArbol(node->right);
        delete node;
    }

   public:
       BinaryTree() {
        root = nullptr;
        size = 0;
    }

    ~BinaryTree() {
        eliminarArbol(root);
    }

    bool insertar(T dato) {
        return insertarRecursivo(root, dato);
    }
    bool buscar(T dato) {
        return buscarRecursivo(root, dato);
    }

    bool eliminarDatoRecursivo(NodeBT<T> *&actual, T dato) {
        if (actual == nullptr)
            return false;

        if (dato < actual)
            return (eliminarDatoRecursivo(actual->left, dato));
        else if (dato > actual->dato)
            return (eliminarDatoRecursivo(actual->right, dato));
        else {
            NodeBT<T> *borrar = nullptr;
            borrar = actual;
            if (!actual->left)
                actual = actual->right;
            else if (!actual->right)
                actual = actual->left;
            else
                borrar = reemplazaLeft(actual);
            delete borrar;
            size--;
            return true;
        }
    }

    NodeBT<T> *getRandomNode() {
        if (root == nullptr || size == 0)
            return nullptr;

        int randomIndex = rand() % size;
        int count = 0;

        return getRandomNodeRecursivo(root, randomIndex, count);
    }
};

#endif
