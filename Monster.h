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

    Monster();

    bool operator>(const Monster &otherMonster) {
        return otherMonster.hp > this->hp;
    }

    bool operator<(const Monster &otherMonster) {
        return otherMonster.hp < this->hp;
    }

    void setName(const std::string &newName);
    void setCR(float newCR);
    void setType(const std::string &newType);
    void setSize(const std::string &newSize);
    void setAC(int newAC);
    void setHP(int newHP);
    void setAlign(const std::string &newAlign);
};

#endif
