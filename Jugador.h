#include <BinaryTree.h>

#include <Monster>

#include "LinkedList.h"
#ifndef JUGADOR_H
#define JUGADOR_H
class Jugador {
   private:
    float               vida;
    float               ataque;
    LinkedList<Monster> monstruosDerrotados;

   public:
    Jugador();
};

#endif
