#include "Dungeon.h"

bool Dungeon::createRoom(Monster copiaMonstruo) {
    Cuarto nuevoCuarto(copiaMonstruo);
    roomList.insertarInicio(nuevoCuarto);
    return true;
}

void Dungeon::imprimeCuartos() {
    roomList.imprime();
}
