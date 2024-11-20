#include <iostream>

#include "Catalogo.h"
#include "Dungeon.h"
#include "Monster.h"

#define NUM_CUARTOS 20

using namespace std;

int main() {
    Dungeon miDungeon;
    Catalogo miCatalogo;

    srand((unsigned int)time(0));

    if (!miCatalogo.loadFromCSV("monsters.csv")) {
        cout << "No se pudo crear el catalogo" << "\n";
        return 0;
    }

    if (!miDungeon.createDungeon("dungeon.txt")) {
        cout << "No se pudo crear el Dungeon" << "\n";
        return 0;
    }

    for (int i = 0; i < miDungeon.getSize(); i++) {
        if (!miDungeon.createRoom(i, miCatalogo.getRandomMonster())) {
            cout << "No se pudo crear un cuarto" << "\n";
            return 0;
        }
    }

    miDungeon.imprimeCuartos();

    return 1;
};
