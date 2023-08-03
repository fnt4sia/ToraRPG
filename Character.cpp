#include <iostream>
#include <string>
#include <ctime>

using namespace std;

#include "Character.h"
#include "Tribes.h"

extern Tribes Class[];
extern Character Chara;

int Character::checkPowerTotal(){
    return Class[Chara.classIndex].powerBase + Chara.weaponUsedStat;
}

int Character::checkDefenseTotal(){
    return Class[Chara.classIndex].defBase + Chara.armorUsedStat;
}

int Character::checkHpMax(){
    return Class[Chara.classIndex].hpBase;
}

int Character::checkManaMax(){
    return Class[Chara.classIndex].manaBase;
}

int Character::checkCcTotal(){
    return Class[Chara.classIndex].ccBase;
}

int Character::checkCdTotal(){
    return Class[Chara.classIndex].cdBase;
}

void Character::levelUpCheck(){
    int levelUpNeed = Chara.level * 50;

    if(Chara.exp > levelUpNeed){
        Chara.level++;
        Chara.exp = Chara.exp - levelUpNeed;
    }    
}

void Character::characterDies(){

    srand(time(0));

    int goldLost = rand()%30 + 1;
    cout<<endl<<"You Lost The Fight And Lost "<<goldLost<<" Coin";
    Chara.gold -= goldLost;
    if(Chara.level < 1)
        Chara.level++;
    Chara.hpCurrent = Chara.hpMax;
}

