#ifndef CUARTO_H
#define CUARTO_H

#include "Monster.h"

class Cuarto {
   private:
    Monster monstruo;

   public:
    Cuarto(Monster nuevoMonstruo) {
        monstruo = nuevoMonstruo;
    }

    Cuarto() {
        monstruo = Monster();
    }

    friend std::ostream& operator<<(std::ostream& os, const Cuarto& cuarto) {
        // Aquí puedes definir cómo quieres que se imprima un Cuarto.
        // Por ejemplo, si quieres imprimir información del Monster en el Cuarto:
        os << "Cuarto con el monstruo: " << cuarto.monstruo;
        return os;
    }
};

#endif
