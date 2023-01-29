#include <iostream>
using namespace std;
class Item{
    protected:
        string name;
    public:
        Item(string name){
        };
};
class Armor : public Item{
    protected:
        int defense;
        int blockrate;
    public:
        Armor(string name, int defense, int blockrate):Item(name){
            this->defense = defense;
            this->blockrate= blockrate;
        }
};
class Weapon : public Item{
    protected:
        int damage;
        int range;
        int critrate;
    public:
        Weapon(string name, int damage, int range, int critrate):Item(name){
            this->damage = damage;
            this->range = range;
            this->critrate = critrate;
        }
};
int main(){

    
}