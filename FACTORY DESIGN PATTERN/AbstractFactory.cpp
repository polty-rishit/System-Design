#include<bits/stdc++.h>
using namespace std;

class Burger{
    public:
    virtual void prepare()=0;
    virtual ~Burger(){};
};

class BasicBurger: public Burger{
    public:
    void prepare() override{
        cout << "Preparing Basic Burger with bun, patty, and ketchup!" << endl;
    }
};

class StandardBurger: public Burger{
    public:
    void prepare() override{
        cout << "Preparing Standard Burger with bun, patty, cheese, and lettuce!" << endl;
    }
};

class PremiumBurger : public Burger{
    public:
    void prepare() override{
        cout << "Preparing Premium Burger with gourmet bun, premium patty, cheese, lettuce, and secret sauce!" << endl;
    }
};

class BasicWheatBurger : public Burger{
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

class PremiumWheatBurger : public Burger{
    public:
    void prepare() override{
        cout << "Preparing Premium Wheat Burger with gourmet bun, premium patty, cheese, lettuce, and secret sauce!" << endl;
    }
};

class GarlicBread{
    public:
    virtual void prepare()=0;
    virtual ~GarlicBread(){};
};

class BasicGarlicBread : public GarlicBread{
    public:
    void prepare() override{
        cout<<"PREPARING BASIC GARLIC BREAD WITH BUTTER AND GARLIC"<<endl;
    }
};

class CheeseGarlicBread : public GarlicBread{
    public:
    void prepare()override{
        cout<<"PREPARING CHEESE GARLIC BREAD WITH CHEESE AND BUTTER"<<endl;
    }
};

class BasicWheatBread : public GarlicBread{
    public:
    void prepare()override{
        cout<<"PREPARING BASIC WHEAT GARLIC BREAD WITH BUTTER AND GARLIC"<<endl;
    }
};

class CheeseWeathBread : public GarlicBread{
    public:
    void prepare() override{
        cout<<"PREPARING CHEESE WHEAT GARLIC BREAD WITH EXTRA CHEESE AND BUTTER"<<endl;
    }
};

class Mealfactory{
    public:
    virtual Burger* createBurger(string &type)=0;
    virtual GarlicBread* createGarlicBread(string& type)=0;
};

class SignBurger: public Mealfactory{
    public:
    Burger* createBurger(string &type) override{
        if(type=="basic")return new BasicBurger();
        if(type=="standard")return new StandardBurger();
        if(type=="premium")return new PremiumBurger();
        else{
            cout<<"INVALID BURGER TYPE"<<endl;
            return NULL;
        }
    }

    GarlicBread *createGarlicBread(string &type)override{
        if(type=="basic")return new BasicGarlicBread();
        if(type=="cheese")return new CheeseGarlicBread();
        else{
            cout<<"INVALID GARLIC BREAD TYPE"<<endl;
            return NULL;
        }
    }
};

class KingBurger : public Mealfactory{
    public:
    Burger* createBurger(string &type)override{
        if(type=="basic")return new BasicWheatBurger();
        if(type=="standard")return new StandardWheatBurger();
        if(type=="premium")return new PremiumWheatBurger();
        else{
            cout<<"INVALID BURGER TYPE"<<endl;
            return nullptr;
        }
    }

    GarlicBread* createGarlicBread(string &type)override{
        if(type=="basic")return new BasicWheatBread();
        else if(type=="cheese")return new CheeseWeathBread();
        else{
            cout<<"INVALID BREAD TYPE"<<endl;
            return NULL;
        }
    }
};

int main(){
    string burgerType="basic";
    string garlicBreadType="cheese";
    Mealfactory* One=new KingBurger();
    Burger *burger=One->createBurger(burgerType);
    burger->prepare();
    GarlicBread *garlic=One->createGarlicBread(garlicBreadType);
    garlic->prepare();
    return 0;
}
