#include "Monster.h"

Monster::Monster() {
}

void Monster::setName(const std::string &newName) {
    name = newName;
}
void Monster::setCR(float newCR) {
    cr = newCR;
}
void Monster::setType(const std::string &newType) {
    type = newType;
}
void Monster::setSize(const std::string &newSize) {
    size = newSize;
}
void Monster::setAC(int newAC) {
    ac = newAC;
}
void Monster::setHP(int newHP) {
    hp = newHP;
}
void Monster::setAlign(const std::string &newAlign) {
    align = newAlign;
}
