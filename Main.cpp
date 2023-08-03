#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<iomanip>
#include<ctime>

using namespace std;

#include "Tribes.h"
#include "Character.h"
#include "Inventory.h"
#include "Creature.h"

void adventureMenu();
void shopMenu();
void playerInfoMenu();
int inventoryMenu();
int battleFight(int enemyRandom);
void loadingScreen(int timeLoading, string textLoading);
void statsUpdate();

bool winFight;

Character Chara;
Inventory invent;

extern Tribes Class[4];
extern Armor Armory[4];
extern Weapon Weaponary[][4];
extern Skill Hero[][4];
extern Creature Monster[];

int main(){
    
    srand(time(0));

    system("cls");

    string usernameInput;
    int classInput, menuChoose;

    cout<<"USERNAME >> ";
    cin>>usernameInput;
    Chara.userName = usernameInput;

    loadingScreen(300, "Creating Character");

    cout<<"1. Warrior"<<endl<<"2. Mage"<<endl<<"3. Archer"<<endl<<"4. Lancer"<<endl;
    cout<<"CHOOSE YOUR CLASS >> ";
    cin>>classInput;
    Chara.classIndex = classInput - 1;

    loadingScreen(300, "Creating Charater");

    cout<< " Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua";
    cout<<endl<<endl<<"Press Anything To Continue... ";
    getch();

    invent.addItem(invent.checkInventorySlot(), Weaponary[Chara.classIndex][0].weaponName);
    invent.addItem(invent.checkInventorySlot(), Armory[0].armorName);

    statsUpdate();

    Chara.hpCurrent = Chara.hpMax;
    Chara.manaCurrent = Chara.manaMax;

    while(true){

        statsUpdate();

        loadingScreen(200, "Loading");

        cout<<"Welcome, Adventurer!"<<endl<<"1. Adventure"<<endl<<"2. Shop"<<endl<<"3. Player Info"<<endl<<"4. Inventory ";

        cout<<endl<<">> ";
        cin>>menuChoose;

        if(menuChoose == 1)
            adventureMenu();
        else if(menuChoose == 2)
            shopMenu();
        else if(menuChoose == 3)
            playerInfoMenu();
        else if(menuChoose == 4)
            inventoryMenu();
    }
}


void adventureMenu(){
    loadingScreen(500, "Searching For Monster");

    srand(time(0));
    string fightChoose;
    int enemyRandom, goldLost, indexRandom;
    bool win;

    Chara.manaCurrent = Chara.manaMax;

    indexRandom = rand() % 100+1;
    if(indexRandom <= 20)
        enemyRandom = 0;
    else if(indexRandom <=40 && indexRandom > 20)
        enemyRandom = 1;
    else if(indexRandom <=50 && indexRandom >40)
        enemyRandom = 2;
    else if(indexRandom <=60 && indexRandom >50)
        enemyRandom = 3;
    else if(indexRandom <=70 && indexRandom >60)
        enemyRandom = 4;
    else if(indexRandom <=80 && indexRandom > 70)
        enemyRandom = 5;
    else if(indexRandom <=90 && indexRandom > 80)
        enemyRandom = 6;
    else if(indexRandom <= 95 && indexRandom > 90)
        enemyRandom = 7;
    else 
        enemyRandom = 8; 
        
    Monster[enemyRandom].defineStat(enemyRandom);
    Monster[enemyRandom].hpCurrent = Monster[enemyRandom].hpMax;

    cout<<"You Meet A Lv. "<<Monster[enemyRandom].level<<" "<<Monster[enemyRandom].name<<endl;
    cout<<endl<<"Do You Want To Fight ? (yes / no)"<<endl<<">>";
    cin>>fightChoose;

    if(fightChoose == "yes"){
        battleFight(enemyRandom);
        
        if(winFight){

            cout<<endl<<"You Won The Fight ! You Gain "<<Monster[enemyRandom].enemyExp<<" Exp And "<<Monster[enemyRandom].goldReward<<" Coin";
            Chara.gold += Monster[enemyRandom].goldReward;
            Chara.exp += Monster[enemyRandom].enemyExp;
            Chara.levelUpCheck();

        }else{

            Chara.characterDies();
            
        }
        cout<<endl<<endl<<"Press Anything To Continue..";
        getch();
    }else{
        cout<<endl<<"You Run Away From The Battle."<<endl;
        cout<<"Press Anything To Continue..";
        getch();
    }
}
void shopMenu(){
    loadingScreen(100, "Loading");

    int chooseBuy;
    int shopMenuChoose;

    cout<<"1. Weapon"<<endl<<"2. Armor"<<endl<<"3. Exit"<<endl<<endl<<">> ";
    cin>>shopMenuChoose;
    cout<<endl;

    if(shopMenuChoose == 1){
        for(int i = 1;i < 4;i++){
            cout<<i<<". Weapon : "<<Weaponary[Chara.classIndex][i].weaponName<<endl;
            cout<<"  Damage : "<<Weaponary[Chara.classIndex][i].weaponPWR<<endl;
            cout<<"  Price  : "<<Weaponary[Chara.classIndex][i].price<<endl<<endl;
        }
        cout<<"4. Exit";
        cout<<endl<<endl<<" >>";
        cin>>chooseBuy;
        cout<<endl;
        if(chooseBuy < 4){
            if(invent.sameItemCheck(Weaponary[Chara.classIndex][chooseBuy].weaponName) && Chara.gold > Weaponary[Chara.classIndex][chooseBuy].price){
                invent.addItem(invent.checkInventorySlot(), Weaponary[Chara.classIndex][chooseBuy].weaponName);
                Chara.gold -= Weaponary[Chara.classIndex][chooseBuy].price;
                cout<<endl<<"You Successfully Bought The Item";
            }else{
                cout<<endl<<"You Cant Buy This Item";
            }
        }
    }


    else if(shopMenuChoose == 2){
        for(int i = 1;i < 4;i++){
            cout<<i<<". Armor : "<<Armory[i].armorName<<endl;
            cout<<"Def   : "<<Armory[i].armorDEF<<endl;
            cout<<"Price : "<<Armory[i].price<<endl<<endl;
        }
        cout<<"4. Exit";
        cout<<endl<<endl<<" >>";
        cin>>chooseBuy;
        cout<<endl;
        if(chooseBuy < 4){
            if(invent.sameItemCheck(Armory[chooseBuy].armorName) && Chara.gold > Armory[chooseBuy].price){
                invent.addItem(invent.checkInventorySlot(), Armory[chooseBuy].armorName);
                Chara.gold -= Armory[chooseBuy].price;
                cout<<endl<<"You Successfully Bought The Item";
            }else{
                cout<<endl<<"You Cant Buy This Item";
            }
        }
    }

    cout<<endl<<"Press Anything To Continue..";
    getch();
}
void playerInfoMenu(){
    loadingScreen(100, "Loading");

    cout<<Chara.userName<<"   "<<Chara.exp<<" / "<<Chara.level * 50<<endl;
    cout<<Class[Chara.classIndex].tribesName<<" Lv."<<Chara.level<<endl<<endl;
    cout<<"HP     : "<<Chara.hpMax<<"   "<<"MANA  : "<<Chara.manaMax<<endl;
    cout<<"POW    : "<<Chara.powerTotal<<"   "<<"DEF   : "<<Chara.defenseTotal<<endl;
    cout<<"CD     : "<<Chara.cdTotal<<"%  "<<"CC    : "<<Chara.ccTotal<<"%"<<endl<<endl;
    cout<<"GOLD   : "<<Chara.gold<<endl<<endl;
    cout<<"WEAPON : "<<Chara.weaponUsedName<<endl;
    cout<<"ARMOR  : "<<Chara.armorUsedName<<endl<<endl;

    cout<<"Skill Information"<<endl;
    for(int i = 0;i < 4;i++){
        cout<<"  "<<Hero[Chara.classIndex][i].skillName<<" (Character Lv. "<<Hero[Chara.classIndex][i].levelRequire<<")"<<endl;
    }

    cout<<"\nPress Anything To Continue..";
    getch();
}
int inventoryMenu(){

    loadingScreen(300, "Loading");
    int itemChoose, optionChoose;
    for(int i = 0;i < invent.checkInventorySlot();i++)
        cout<<i + 1<<". "<<invent.inventorySlot[i]<<endl;
    cout<<invent.checkInventorySlot() + 1<<". Exit" << endl << ">> ";

    cin >> itemChoose;
    if(itemChoose >= invent.checkInventorySlot() + 1)
        return 0;

    system("cls");

    cout<<"What Do You Want To Do With The Item"<<endl<<"1. Use"<<endl<<"2. Remove"<<endl<<"3. Cancel"<<endl;
    cout << ">> ";

    cin>>optionChoose;
    if(optionChoose == 1)
        invent.useItem(invent.inventorySlot[itemChoose - 1], Chara.classIndex);
    else if(optionChoose == 2){
        if(invent.inventorySlot[itemChoose - 1] == Chara.armorUsedName){
            Chara.armorUsedName = "";
            Chara.armorUsedStat = 0;
        }
        else if(invent.inventorySlot[itemChoose - 1] == Chara.weaponUsedName){
            Chara.weaponUsedName = "";
            Chara.weaponUsedStat = 0;
        }
        invent.removeItem(itemChoose - 1);
        invent.sortItem();
    }
    else
        return 0;
    cout<<endl<<"Press Anything To Continue..";
    getch();
}
void loadingScreen(int timeLoading, string textLoading){
    system("cls");
    cout<<textLoading;
    Sleep(timeLoading);
    cout<<".";
    Sleep(timeLoading);
    cout<<".";
    Sleep(timeLoading);
    cout<<".";
    Sleep(timeLoading);
    system("cls");
}
int battleFight(int enemyRandom){
    int attackChoose, attackDealt;

    loadingScreen(500, "Preparing");

    Hero[Chara.classIndex][0].cooldownReset();

    while(Chara.hpCurrent > 0 || Monster[enemyRandom].hpCurrent > 0){

        skipJump:

        cout<<left<<setw(15)<<""<<setw(15)<<Chara.userName<<"|"<<right<<setw(15)<<Monster[enemyRandom].name<<endl;
        cout<<left<<setw(15)<<""<<setw(15)<<Chara.level<<"|"<<right<<setw(15)<<Monster[enemyRandom].level<<endl;
        cout<<left<<setw(15)<<""<<setw(5)<<"Hp : "<<setw(10)<<Chara.hpCurrent<<"|"<<right<<setw(11)<<"Hp : "<<setw(4)<<Monster[enemyRandom].hpCurrent<<endl;
        cout<<left<<setw(15)<<""<<setw(7)<<"Mana : "<<setw(8)<<Chara.manaCurrent<<"|"<<right<<setw(15)<<"-"<<endl;

        cout<<endl<<endl<<"1. Basic Attack"<<endl;
        for(int i = 0;i < 4;i++){
            if(Chara.level >= Hero[Chara.classIndex][i].levelRequire)
                cout<<i+2<<". "<<Hero[Chara.classIndex][i].skillName<<endl;
        }
        cout<<endl;

        cout<<"Your Turn To Attack"<<endl<<">>";
        cin>>attackChoose;
        cout<<endl;
        if(attackChoose == 1){
            attackDealt = Chara.powerTotal - (Monster[enemyRandom].enemyDef * 0.5);
        }else if(attackChoose > 1 && attackChoose <= 4){
            if(Hero[Chara.classIndex][attackChoose - 2].levelRequire > Chara.level){
                cout<<"Not Available"<<endl<<endl;
                Sleep(500);
                goto skipJump;
            }else if(Hero[Chara.classIndex][attackChoose - 2].manaCost > Chara.manaCurrent){
                cout<<"You Dont Have Enough Mana"<<endl<<endl;
                Sleep(500);
                goto skipJump;
            }else if(Hero[Chara.classIndex][attackChoose - 2].cooldownCurrent != 0){
                cout<<"Your Skill Is Still On Cooldown"<<endl<<endl;
                Sleep(500);
                goto skipJump;
            }else{
                attackDealt = (Chara.powerTotal + Hero[Chara.classIndex][attackChoose - 2].damageSkill) - (Monster[enemyRandom].enemyDef * 0.5);
                Hero[Chara.classIndex][attackChoose - 2].cooldownCurrent = 2;
                Chara.manaCurrent -= Hero[Chara.classIndex][attackChoose - 2].manaCost;
            }
        }
        if(attackDealt < 1)
            attackDealt = 1;
        cout<<"You Dealt "<<attackDealt<<" Damage"<<endl<<endl;
        Monster[enemyRandom].hpCurrent -= attackDealt;
        Sleep(1000);

        if(Monster[enemyRandom].hpCurrent > 0){
            cout<<Monster[enemyRandom].name<<" Is Attacking"<<endl;
            Sleep(1000);
            attackDealt = Monster[enemyRandom].enemyPower - (Chara.defenseTotal * 0.1);
            if(attackDealt < 1)
                attackDealt = 1;
            cout<<Monster[enemyRandom].name<<" Dealt "<<attackDealt<<" Damage"<<endl<<endl<<endl;
            Chara.hpCurrent -= attackDealt;
            Sleep(1000);
        }

        if(Chara.hpCurrent < 0){
            winFight = false;
            return 0;
        }
        if(Monster[enemyRandom].hpCurrent < 0){
            winFight = true;
            return 0;
        }

        Hero[Chara.classIndex][0].cooldownDecrease();
    }
}
void statsUpdate(){
    Chara.powerTotal = Chara.checkPowerTotal();
    Chara.defenseTotal = Chara.checkDefenseTotal();
    Chara.hpMax = Chara.checkHpMax();
    Chara.manaMax = Chara.checkManaMax();
    Chara.ccTotal = Chara.checkCcTotal();
    Chara.cdTotal = Chara.checkCdTotal();
}  