#ifndef NODEBT_H
#define NODEBT_H

template <typename T>
class NodeBT {
   public:
    T       dato;
    NodeBT *left;
    NodeBT *right;
    NodeBT(T dato) {
        this->dato = dato;
        left = nullptr;
        right = nullptr;
    }
};
#endif
