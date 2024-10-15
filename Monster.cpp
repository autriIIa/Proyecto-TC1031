#include "Monster.h"

Monster::Monster(std::string name, float cr, std::string type, std::string size, int ac, int hp,
                 std::string align) {
    this->name = name;
    this->cr = cr;
    this->type = type;
    this->size = size;
    this->ac = ac;
    this->hp = hp;
    this->align = align;
}
