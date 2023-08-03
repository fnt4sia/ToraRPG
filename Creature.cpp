#include <ctime>
#include <string>
#include "Creature.h"
#include "Character.h"
using namespace std;

extern Creature Monster[];
extern Character Chara;

Creature::Creature(string name, int basePower, int baseDef, int goldReward, int baseExp, int criticalChance, int criticalDamage, int hpMax){
    this->name = name;
    this->basePower = basePower;
    this->baseDef = baseDef;
    this->goldReward = goldReward;
    this->baseExp = baseExp;
    this->criticalChance = criticalChance;
    this->criticalDamage = criticalDamage;
    this->hpMax = hpMax;
}

void Creature::defineStat(int index){

    srand(time(0));

    Monster[index].level = rand() %(index + 4) + ((index * 4 ) + 1);
    
    Monster[index].enemyPower = Monster[index].basePower + ((Monster[index].level * Monster[index].basePower) * 0.05);
    Monster[index].enemyDef = Monster[index].baseDef + ((Monster[index].level * Monster[index].baseDef) * 0.05);
    Monster[index].enemyExp = Monster[index].baseExp + ((Monster[index].level - Chara.level) * 5);

    if(Monster[index].enemyExp <= 0)
            Monster[index].enemyExp = 1;

}

Creature Monster[] = { Creature("Slime", 30, 30, 10, 10, 5, 120, 50), Creature("Goblin", 50, 50, 20, 30, 10, 120, 100), Creature("Orc", 40, 100, 30, 40, 15, 130, 150), Creature("Giant Spider", 80, 60, 40, 40, 20, 130, 170),Creature("Imps", 20, 200, 30, 50, 25, 130, 250),Creature("Ogre", 100, 100, 50, 50, 30, 140, 300), Creature("Wyvern", 150, 100, 70, 80, 30, 150, 350), Creature("Dragon", 300, 200, 100, 100, 40, 160, 400), Creature("Hydra", 150, 400, 100, 100, 50, 145, 400)};
