#include<string>
using namespace std;

class Creature{
    public :
        string name;
        int hpMax;
        int hpCurrent;
        int basePower;
        int baseDef;
        int criticalChance;
        int criticalDamage;
        int goldReward;
        int baseExp;
        int level;

        int enemyPower;
        int enemyDef;
        int enemyExp;
        
        Creature(string name, int basePower, int baseDef, int goldReward, int baseExp, int criticalChance, int criticalDamage, int hpMax);
        void defineStat(int index);
};