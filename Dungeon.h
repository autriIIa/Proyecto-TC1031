#ifndef DUNGEON_H
#define DUNGEON_H

#include "Cuarto.h"
#include "DoubleLinkedList.h"

class Dungeon {
   private:
    DoubleLinkedList<Cuarto> roomList;

   public:
    void imprimeCuartos();
    bool createRoom(Monster copiaMonstruo);

   private:
};

#endif
