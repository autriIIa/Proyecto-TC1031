#include <iostream>

#include "Catalogo.h"
#include "Dungeon.h"
#include "Monster.h"

#define NUM_CUARTOS 20

using namespace std;

int main() {
    Catalogo miCatalogo;
    Dungeon  miDungeon;

    if (!miCatalogo.loadFromCSV("monsters.csv")) {
        cout << "No se pudo crear el catalogo" << endl;
        return 0;
    }

    Monster m1 = miCatalogo.getRandomMonster();

    cout << m1 << endl;
    /*
    cout << "Creando Dungeon..." << endl;
    for (int c = 0; c < NUM_CUARTOS; c++) {
        Monster *pMonster = nullptr, copiaMonstruo;

        pMonster = miCatalogo.getRandomMonster();
        if (!pMonster) {
            cout << "No se pudo obtener un monstruo del catalogo" << endl;
            return 0;
        }

        copiaMonstruo = *pMonster;
        if (!miDungeon.createRoom(copiaMonstruo)) {
            cout << "No se pudo insertar cuarto con monstruo al calabozo" << endl;
            return 0;
        }
    }

    miDungeon.imprimeCuartos();
    */
    return 0;
};
