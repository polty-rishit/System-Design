#include<bits/stdc++.h>
using namespace std;

class Character{
    public:
    virtual string getAbilities() const=0;
    virtual ~Character(){};
};

class Mario : public Character{
    public:
    string getAbilities() const override{
        return "Mario";
    }
};

class CharacterDecorator : public Character{
    protected:
    Character *charecter;
    public:
    CharacterDecorator(Character *c){
        this->charecter=c;
    }
};
class HeightUp : public CharacterDecorator{
    public:
    HeightUp(Character *c):CharacterDecorator(c){}
    string getAbilities()const override{
        return charecter->getAbilities()+"with HeightUp";
    }
};

class GunPower : public CharacterDecorator{
    public:
    GunPower (Character *c):CharacterDecorator(c){}
    string getAbilities()const override{
        return charecter->getAbilities()+" with Gun";
    }
};

class StarPower : public CharacterDecorator{
    public:
    StarPower(Character *c):CharacterDecorator(c){}
    string getAbilities()const override{
        return charecter->getAbilities()+"with Star Power (Limited Time)";
    }
    ~StarPower(){
        cout<<"DESTROYING STARPOWER DECORATOR"<<endl;
    }
};

int main(){
    Character *mario=new Mario();
    cout<<"BASIC CHARECTER : "<<mario->getAbilities()<<endl;

    mario=new HeightUp(mario);
    cout<<"AFTER HEIGHT UP: "<<mario->getAbilities()<<endl;

    mario=new GunPower(mario);
    cout<<"AFTER GEUNPOWER"<<mario->getAbilities()<<endl;

    mario=new StarPower(mario);
    cout<<"AFTER STAR POWER: "<<mario->getAbilities()<<endl;

    delete mario;
    return 0;
}
