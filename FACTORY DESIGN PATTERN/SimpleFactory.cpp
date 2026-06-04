#include<bits/stdc++.h>
using namespace std;

class Burger{
    public:
    virtual void prepare()=0;
    virtual ~Burger(){};
};

class BasicBurger : public Burger{
    public:
    void prepare(){
        cout<<"PREPARING BASIC BURGER WITH BUN, PATTY AND KETCHUP"<<endl;
    }
};

class StandardBurger : public Burger{
    public:
    void prepare(){
        cout<<"PREPARING STANDARD BURGER WITH BUN, PATTY, CHEESE AND LETTUSE."<<endl;
    }
};

class PremiumBurger : public Burger{
    public:
    void prepare(){
        cout<<"PREPARING PREMIUM BURGER WITH GOURMET BUN, PREMIUM PATTY , CHEESE, LETTUCE AND SECRET SAUCE."<<endl;
    }
};

class BurgerFactory{
    public:
    Burger* createBurger(string type){
        if(type=="basic")return new BasicBurger();
        else if(type=="standard")return new StandardBurger();
        else if(type=="premium")return new PremiumBurger();
        else{
            cout<<"invalid type"<<endl;
            return NULL;
        }
    }
};

int main(){
    string type="standard";
    BurgerFactory *One=new BurgerFactory();
    Burger *burger=One->createBurger(type);
    burger->prepare();
    return 0;
}