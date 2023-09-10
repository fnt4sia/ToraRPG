#include "Inventory.h"
#include "Character.h"
#include "Tribes.h"

#include<algorithm>
#include <string>

extern Inventory invent;
extern Weapon Weaponary[][4];
extern Armor Armory[];
extern Character Chara;

int Inventory::checkInventorySlot(){
    for(int i = 0;i < 10;i++){
        if(inventorySlot[i] == ""){
            return i;
        }
    }
}

void Inventory::addItem(int emptyIndex, string Item){
    inventorySlot[emptyIndex] = Item;
}

void Inventory::removeItem(int index){
    inventorySlot[index] = "";
}

void Inventory::sortItem(){
    for(int i = 0; i < 10;i++){
        for(int j = 0;j < 10;j++){
            if(inventorySlot[i] > inventorySlot[j]){
                swap(inventorySlot[i], inventorySlot[j]);
            }
        }
    }
}

bool Inventory::sameItemCheck(string item){
    for(int i = 0;i < invent.checkInventorySlot();i++)
        if(item == invent.inventorySlot[i])
            return false;
    return true;
}

void Inventory::useItem(string item, int classIndex){
    for(int i = 0;i < 4;i++)
        if(item == Weaponary[classIndex][i].weaponName){
            Chara.weaponUsedName = Weaponary[classIndex][i].weaponName;
            Chara.weaponUsedStat = Weaponary[classIndex][i].weaponPWR;
        }

    for(int i = 0; i < 4;i++)
        if(item == Armory[i].armorName){
            Chara.armorUsedName = Armory[i].armorName;
            Chara.armorUsedStat = Armory[i].armorDEF;
        }
}

