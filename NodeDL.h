#ifndef NODEDL_H
#define NODEDL_H

template <typename T>
class NodeDL {
   public:
    T       data;
    NodeDL *next;
    NodeDL *prev;
    NodeDL(T value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

#endif
