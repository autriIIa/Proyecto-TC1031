#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>

class Monster {
   private:
    std::string name;
    float       cr;
    std::string type;
    std::string size;
    int         ac;
    int         hp;
    std::string align;

   public:
    friend std::ostream &operator<<(std::ostream &os, const Monster &monster) {
        os << "Name: " << monster.name;
        return os;
    };

    Monster(std::string name, float cr, std::string type, std::string size, int ac, int hp,
            std::string align);
};

#endif
