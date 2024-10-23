#include <BinaryTree.h>

#include <Monster>
#ifndef JUGADOR_H
#define JUGADOR_H
class Jugador {
   private:
    float               vida;
    float               ataque;
    BinaryTree<Monster> monstruosDerrotados;

   public:
    Jugador();
};

#endif
