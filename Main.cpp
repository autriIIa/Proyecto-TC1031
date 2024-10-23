#include <iostream>

#include "Catalogo.h"
#include "Dungeon.h"
#include "Monster.h"

#define NUM_CUARTOS 20

using namespace std;

int main() {
    Catalogo miCatalogo;
    Dungeon  miDungeon;

    srand((unsigned int)time(0));

    if (!miCatalogo.loadFromCSV("monsters.csv")) {
        cout << "No se pudo crear el catalogo" << endl;
        return 0;
    }

    cout << "Creando Dungeon..." << endl;

    for (int c = 0; c < NUM_CUARTOS; c++) {
        Monster pMonster, copiaMonstruo;

        pMonster = miCatalogo.getRandomMonster();
        miDungeon.createRoom(pMonster);
    }

    miDungeon.imprimeCuartos();

    return 0;
};
