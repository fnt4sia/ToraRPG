#include <string>
using namespace std;

class Inventory{   
    public :
        string inventorySlot[10];

        int checkInventorySlot();
        bool sameItemCheck(string item);
        void addItem(int emptyIndex, string item);
        void removeItem(int index);
        void sortItem();
        void useItem(string item, int classIndex);
};