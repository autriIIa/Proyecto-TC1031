#ifndef CUARTO_H
#define CUARTO_H

#include "Monster.h"

class Cuarto {
   public:
    Monster monstruo;
    Cuarto(Monster nuevoMonstruo) {
        monstruo = nuevoMonstruo;
    }
};

#endif
