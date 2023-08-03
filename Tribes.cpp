#include<string>
#include"Tribes.h"
#include"Character.h"
using namespace std;

extern Character Chara;

Armor Armory[4] = {Armor("Rusted Armor", 100, 10), Armor("Iron Armor", 110, 200), Armor("Diamond Armor", 120, 400), Armor("Emerald Armor", 135, 500)};
Tribes Class[4] = { Tribes("Warrior", 100, 100, 200, 100, 25, 120), Tribes("Mage", 170, 30, 100, 200, 5, 190), Tribes("Archer", 130, 60, 150, 150, 40, 110), Tribes("Lancer", 120, 80, 200, 100, 20, 140)};
Weapon Weaponary[][4] = { {Weapon("Rusted Sword", 70, 0), Weapon("Iron Sword", 85, 200), Weapon("Diamond Sword", 95, 400), Weapon("Emerald Sword", 110, 500)},
                          {Weapon("Wooden Staff", 80, 0), Weapon("Teak Staff", 90, 200), Weapon("Orc Leather Staff", 105, 400), Weapon("Ogre Leather Staff", 120, 500)},
                          {Weapon("Wooden Bow", 60, 0), Weapon("Teak Bow", 70, 200), Weapon("Orc Leather Bow", 75, 400), Weapon("Ogre Leather Bow", 90, 500)},
                          {Weapon("Rusted Spear", 55, 0), Weapon("Iron Spear", 65, 200), Weapon("Diamond Spear", 75, 400), Weapon("Emerald Spear", 90, 500)}   
                        };
Skill Hero[][4] = { {Skill("Heavy Slash", 50, 50, 1), Skill("ab", 1, 1, 10), Skill("ba", 2, 2, 20), Skill("ca", 3, 3, 30)}, 
                    {Skill("FireBall", 50, 50, 1), Skill("aq", 1, 1, 10), Skill("be", 2, 2, 20), Skill("cd", 3, 3, 30)}, 
                    {Skill("QuickShot", 50, 50, 1), Skill("aw", 1, 1, 10), Skill("bd", 2, 2, 20), Skill("ca", 3, 3, 30)}, 
                    {Skill("Piercing Spear", 50, 50, 1), Skill("ad", 1, 1, 10), Skill("bf", 2, 2, 20), Skill("cs", 3, 3, 30)}
                  };

Tribes::Tribes(string tribesName, int powerBase, int defBase, int hpBase, int manaBase, int ccBase, int cdBase){
    this->tribesName = tribesName;
    this->powerBase = powerBase;
    this->defBase = defBase;
    this->hpBase = hpBase;
    this->manaBase = manaBase;
    this->ccBase = ccBase;
    this->cdBase = cdBase;
};

Skill::Skill(string inputName, int inputSkill, int inputCost, int levelRequire){
    this->skillName = inputName;
    this->damageSkill = inputSkill;
    this->manaCost = inputCost;
    this->levelRequire = levelRequire;
};

void Skill::cooldownDecrease(){
    for(int i = 0;i < 4;i++){
        Hero[Chara.classIndex][i].cooldownCurrent--;
        if(Hero[Chara.classIndex][i].cooldownCurrent < 0){
            Hero[Chara.classIndex][i].cooldownCurrent = 0;
        }
    }
}

void Skill::cooldownReset(){
    for(int i = 0;i < 4;i++)
        Hero[Chara.classIndex][i].cooldownCurrent = 0;
}

Weapon::Weapon(string inputName, int inputPWR, int inputPrice){
    this->weaponName = inputName;
    this->weaponPWR = inputPWR;
    this->price = inputPrice;
};

Armor::Armor(string armorName, int armorDef, int price){
    this->armorName = armorName;
    this->armorDEF = armorDef;
    this->price = price;
}

        
