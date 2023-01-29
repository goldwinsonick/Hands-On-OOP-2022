#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Item{
    public:
        string name;
        int weight;
        string type;

        Item(string name, int weight){
            this->name = name;
        };
        virtual string getName(){return name;}
        virtual int getWeight(){return weight;}
        virtual int getDef(){return 0;}
        virtual int getBlock(){return 0;}
        virtual int getDmg(){return 0;}
        virtual int getRange(){return 0;}
        virtual int getCrit(){return 0;}
};
class Armor : public Item{
    public:
        int defense;
        int blockrate;

        Armor(string name, int weight, int defense, int blockrate):Item(name, weight){
            this->type = "armor";
            this->defense = defense;
            this->blockrate= blockrate;
        }
        int getDef() override {
            return defense;
        }
        int getBlock() override {
            return blockrate;
        }
};
class Weapon : public Item{
    public:
        int damage;
        int range;
        int critrate;

        Weapon(string name, int weight, int damage, int range, int critrate):Item(name, weight){
            this->type = "weapon";
            this->damage = damage;
            this->range = range;
            this->critrate = critrate;
        }
        int getDmg() override {
            return damage;
        }
        int getRange() override {
            return range;
        }
        int getCrit() override{
            return critrate;
        }
};
class Player{
    public:
        string name;
        int hp;
        int def = 0;
        int att = 0;
        int crit = 0;
        int block = 0;
        int maxWeight;
        Item armor = Armor("Body", 1, 0, 0);
        Item weapon = Weapon("Hand", 1, 3, 1, 0);
        
        Player(string name, int hp, int att, int maxWeight){
            this->name = name;
            this->hp = hp;
            this->att = att;
        }

        void equip(Item item){
            if(item.type == "armor"){
                if(armor.name == "Body"){
                    armor = item;
                } else {cout<<"Already equipped armor"<<endl;}
            } else if(item.type == "weapon"){
                if(weapon.name == "Hand"){
                    weapon = item;
                } else {cout<<"Already equipped weapon"<<endl;}
            }
            updateStats();
        }
        void unequip(string type){
            if(type == "armor"){
                Item armor = Armor("Body", 1, 0, 0);
            }
            else if(type == "weapon"){
                Item weapon = Weapon("Hand", 1, 3, 1, 0);

            }
            updateStats();
        }
        void updateStats(){
            cout<<weapon.getDmg()<<endl;
            def = 0;
            att = 0;
            crit = 0;
            block = 0;

            def += armor.getDef();
            block += armor.getBlock();
            att  += weapon.getDmg();
            crit += weapon.getCrit();
        }
};
int main(){
    Player p1= Player("Bob", 100, 10, 20); 
    Item w1 = Weapon("sword1", 10, 100, 1, 0.5);
    cout<<p1.att<<endl;
    p1.equip(w1);
    cout<<p1.att<<endl;
}