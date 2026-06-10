#include<bits/stdc++.h>
using namespace std;

class Cloneable{
    public:
    virtual Cloneable *clone() const=0;
    virtual ~Cloneable(){}
};

class NPC : public Cloneable{
    public:
    string name;
    int health;
    int attack;
    int defence;

    NPC(const string &name,int health,int attack,int defence){
        this->name=name;
        this->health=health;
        this->attack=attack;
        this->defence=defence;
        cout<<"SETTING UP TEMPLATE NPC "<<name<<endl;
    }

    NPC(const NPC& o){
        name=o.name;
        health=o.health;
        attack=o.attack;
        defence=o.defence;
        cout<<"Cloning NPC "<<name<<endl;
    }
    Cloneable *clone() const override{
        return new NPC(*this);
    }

    void describe(){
        cout << "NPC " << name  << " [HP=" << health  << " ATK=" << attack 
        << " DEF=" << defence << "]\n";
    }

    void setName(const string &n){
        name=n;
    }
    void setHealth(int h){
        health=h;
    }
    void setAttack(int a){
        attack=a;
    }
    void setDefence(int d){
        defence=d;
    }
};

int main(){
    NPC* a=new NPC("Alien",30,5,2);
    NPC* copyA=dynamic_cast<NPC*>(a->clone());
    copyA->describe();

    NPC* copy2=dynamic_cast<NPC*>(a->clone());
    copy2->describe();
    
    cout<<"CHANING THE PARAMETERS"<<endl;
    copy2->setName("HAAPY");
    copy2->setHealth(50);
    copy2->describe();
}