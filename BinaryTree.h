#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>

#include "NodeBT.h"
template <typename T>

class BinaryTree {
   private:
    bool insertarRecursivo(NodeBT<T> *&nodo, T dato) {
        if (nodo == nullptr) {
            nodo = new (std::nothrow) NodeBT<T>(dato);
            if (!nodo)
                return false;
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

   public:
    NodeBT<T> *root;
    BinaryTree() {
        root = nullptr;
    }
    bool insertar(T dato) {
        return insertarRecursivo(root, dato);
    }
    bool buscar(T dato) {
        return buscarRecursivo(root, dato);
    }
    void imprimir(const std::string &prefix, const NodeBT<T> *node, bool isLeft) {
        if (node != nullptr) {
            std::cout << prefix;

            std::cout << (isLeft ? "├──" : "└──");

            // print the value of the node
            std::cout << node->dato << std::endl;

            // enter the next tree level - left and right branch
            imprimir(prefix + (isLeft ? "│   " : "    "), node->left, true);
            imprimir(prefix + (isLeft ? "│   " : "    "), node->right, false);
        }
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
        }
        return true;
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
};

#endif