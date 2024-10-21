#ifndef DUNGEON_H
#define DUNGEON_H

#include "Cuarto.h"
#include "DoubleLinkedList.h"

class Dungeon {
   public:
    void                     imprimeCuartos();
    bool                     createRoom(Monster &copiaMonstruo);
    DoubleLinkedList<Cuarto> roomList;

   private:
};

#endif
