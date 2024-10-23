#include <fstream>
#include <iostream>
#include <sstream>

#include "BinaryTree.h"
#include "Monster.h"

class Catalogo {
   public:
    BinaryTree<Monster> catalogoMonstruos;
    bool                loadFromCSV(const std::string &filename);
    Monster             getRandomMonster();
};
