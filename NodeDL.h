#ifndef NODEDL_H
#define NODEDL_H

template <typename T>

class NodeDL {
   public:
    T       data;
    NodeDL *next;
    NodeDL *prev;
    NodeDL() {
        next = nullptr;
        prev = nullptr;
    }
};

#endif
