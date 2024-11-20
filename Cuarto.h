#ifndef CUARTO_H
#define CUARTO_H

#include "Monster.h"

class Cuarto {
   private:
   public:
    Monster monstruo;
    int numeroCuarto;
    Cuarto(int numero, Monster nuevoMonstruo) {
        monstruo = nuevoMonstruo;
        numeroCuarto = numero;
    }

    Cuarto() {
        numeroCuarto = 0;
        monstruo = Monster();
    }

    friend std::ostream& operator<<(std::ostream& os, const Cuarto& cuarto) {
        os << "Cuarto con el monstruo: " << cuarto.monstruo;
        return os;
    }

    bool operator>(const Cuarto& OtroCuarto) {
        return this->monstruo.getHP() > OtroCuarto.monstruo.getHP();
    }
};

#endif
