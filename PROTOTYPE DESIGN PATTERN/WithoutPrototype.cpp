#include<bits/stdc++.h>
using namespace std;

class NPC{
    public:
    string name;
    int health;
    int attack;
    int defence;

    NPC(string name,int h,int a,int d){
        this->name=name;
        this->health=h;
        this->attack=a;
        this->defence=d;

        cout << "Creating NPC '" << name << "' [HP:" << health << ", ATK:" 
             << attack << ", DEF:" << defence << "]\n";
    }

    void describe(){
        cout << "  NPC: " << name << " | HP=" << health << " ATK=" << attack
             << " DEF=" << defence << "\n";
    }
};

int main(){
    NPC* one=new NPC("Rishit",1,2,3);
    one->describe();
    NPC* two=new NPC("POlty",1,2,3);
    two->describe();
    delete one,two;
    return 0;
}