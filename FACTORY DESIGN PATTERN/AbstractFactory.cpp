#include<bits/stdc++.h>
using namespace std;

class Burger{
    public:
    virtual void prepare()=0;
    virtual ~Burger(){};
};

class BasicBurger: public Burger{
    
};

class StandardBurger: public Burger{
    public:
    void prepare() override{
        cout << "Preparing Standard Burger with bun, patty, cheese, and lettuce!" << endl;
    }
};

class