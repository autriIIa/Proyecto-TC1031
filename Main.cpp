#include <iostream>

#include "Catalogo.h"
#include "Monster.h"

using namespace std;

int main() {
    Catalogo myCatalog;
    Monster  myMonster("Crab", 0.0, "beast", "Tiny", 11, 2, "unaligned");

    if (!myCatalog.loadFromCSV("monsters.csv"))
        cout << "No se pudo";

    return 0;
};
