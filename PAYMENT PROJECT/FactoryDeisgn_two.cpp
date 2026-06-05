#include<bits/stdc++.h>
using namespace std;

class Payment{
    public:
    virtual void pay()=0;
    virtual ~Payment(){};
};

class UPI : public Payment{
    public:
    void pay() override{
        cout<<"PAYING USING UPI"<<endl;
    }
};

class Card : public Payment{
    public:
    void pay() override{
        cout<<"PAYING USING CARD"<<endl;
    }
};

class NetBanking : public Payment{
    public:
    void pay() override{
        cout<<"PAYING USING NET BANKING"<<endl;
    }
};

class User{
    public:
    Payment *makePayment(string &type){
        if(type=="upi")return new UPI();
        if(type=="card")return new Card();
        if(type=="Net")return new NetBanking();
        else{
            cout<<"SERVER ERROR"<<endl;
            return NULL;
        }
    }
};


int main(){
    string type="upi";
    User *first=new User();
    Payment *upi=first->makePayment(type);
    upi->pay();
    return 0;
}