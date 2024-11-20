#include <fstream>
#include <iostream>
#include <sstream>

#include "BinaryTree.h"
#include "Monster.h"

class Catalogo {
   private:
    BinaryTree<Monster> catalogoMonstruos;

   public:
    bool loadFromCSV(const std::string& filename);
    Monster getRandomMonster();
};
