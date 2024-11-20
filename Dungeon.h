#ifndef DUNGEON_H
#define DUNGEON_H

#include "Cuarto.h"
#include "Graph.h"

class Dungeon {
   private:
    Graph<Cuarto> roomList;

   public:
    int getSize() {
        return roomList.getSize();
    }
    void imprimeCuartos();
    bool createRoom(int position, Monster copiaMonstruo);
    bool createDungeon(const std::string &fileName);

   private:
};

#endif
