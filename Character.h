#include <string>
using namespace std;

class Character{
    public : 
        string userName;
        string weaponUsedName;
        string armorUsedName;
        int classIndex;
        int armorUsedStat;
        int weaponUsedStat;
        int hpMax;
        int manaMax;
        int hpCurrent;
        int manaCurrent;
        int powerTotal;
        int defenseTotal;
        int ccTotal;
        int cdTotal;
        int level = 1;
        int exp = 0;
        int gold = 300;

        void levelUpCheck();
        void characterDies();
        int checkPowerTotal();
        int checkDefenseTotal();
        int checkHpMax();
        int checkManaMax();
        int checkCcTotal();
        int checkCdTotal();
        
};