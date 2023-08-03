#include<string>
using namespace std;

class Skill{
    public :
        string skillName;
        int damageSkill;
        int manaCost;
        int levelRequire;
        int cooldownCurrent = 0;
        int cooldownTurn;

        Skill(string skillName, int damageSkill, int manaCost, int levelRequire);
        void cooldownDecrease();
        void cooldownReset();
};

class Weapon{
    public :
        string weaponName;
        int weaponPWR;
        int price;

        Weapon(string weaponName, int weaponPWR, int price);
};

class Armor{
    public : 
        string armorName;
        int armorDEF;
        int price;

        Armor(string armorName, int armorDEF, int price);
}; 

class Tribes{
    public:
        string tribesName;
        int powerBase;
        int defBase;
        int hpBase;
        int manaBase;
        int ccBase;
        int cdBase;

        Tribes(string tribesName, int powerBase, int defBase, int hpBase, int manaBase, int ccBase, int cdBase);
};