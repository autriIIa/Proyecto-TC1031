#include "Dungeon.h"

bool Dungeon::createRoom(int vertex, Monster copiaMonstruo) {
    Cuarto nuevoCuarto(vertex, copiaMonstruo);
    roomList.insertData(vertex, nuevoCuarto);
    return true;
}

bool Dungeon::createDungeon(const std::string &fileName) {
    if (roomList.loadFile(fileName))
        return true;

    return false;
}

void Dungeon::imprimeCuartos() {
    roomList.print();
}
