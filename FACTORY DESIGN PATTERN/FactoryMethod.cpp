#include<bits/stdc++.h>
using namespace std;

class Burger{
    public:
    virtual void prepare()=0;
    virtual ~Burger(){}
};

class BasicBurger: public Burger{
    public:
    void prepare() override{
        cout<<"PREPARING BASIC BURGER WITH BUN,PATTY,AND LETTUSE"<<endl;
    }
};

class StandardBurger : public Burger{
    public:
    void prepare() override{
        cout<<"PREPARING STANDARD BURGER WITH BUN, PATTY, CHEESE, AND LETTUSE"<<endl;
    }
};

class PremiumBurger: public Burger{
    public:
    void prepare() override{
        cout<<"PREPARING PREMIUM BURGER WITH GOURMET BUN, PREMIMUM PAATY, CHEESE, LETTUSE AND SECRER SAUCE"<<endl;
    }
};

class BasicWheatBurger: public Burger{
     public:
     void prepare() override{
        cout << "Preparing Basic Wheat Burger with bun, patty, and ketchup!" << endl;
     }
};

class StandardWheatBurger : public Burger{
    public:
    void prepare() override{
        cout << "Preparing Standard Wheat Burger with bun, patty, cheese, and lettuce!" << endl;
    }
};

class PremiumWeatBurger : public Burger{
    public:
    void prepare() override{
        cout << "Preparing Premium Wheat Burger with gourmet bun, premium patty, cheese, lettuce, and secret sauce!" << endl;
    }
};

class BurgerFactory{
    public:
    virtual Burger* createburger(string &type)=0;
};

class SighBurger : public BurgerFactory{
    public:
    Burger* createburger(string &type) override{
        if(type=="basic")return new BasicBurger();
        if(type=="standard")return new StandardBurger();
        if(type=="premium")return new PremiumBurger();
        else{
            cout<<"Invalid burger type"<<endl;
            return NULL;
        }
    }
};

class KingBurger : public BurgerFactory{
    public:
    Burger *createburger(string &type)override{
        if(type=="basic")return new BasicWheatBurger();
        if(type=="standard")return new StandardWheatBurger();
        if(type=="premium")return new PremiumWeatBurger();
        else{
            cout<<"NOT A VALID BURGER TYPE"<<endl;
            return nullptr;
        }
    }
};

int main(){
    string type="basic";
    BurgerFactory *first=new SighBurger();
    Burger * burger=first->createburger(type);
    burger->prepare();
    return 0;
}