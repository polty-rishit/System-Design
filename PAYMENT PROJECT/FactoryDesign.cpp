//FACTORY DEISGN PATTERN
#include<bits/stdc++.h>
using namespace std;

class Payment{
    public:
    virtual void pay()=0;
    virtual ~Payment(){};
};

class UPI: public Payment{
    public:
    void pay()override{
        cout<<"PAYING USING UPI"<<endl;
    }
};

class ErrorUPI : public Payment{
    public:
    void pay() override{
        cout<<"ERROR: THE ENTERED PIN FOR UPI IS WRONG"<<endl;
    }
};

class Card : public Payment{
    public:
    void pay() override{
        cout<<"PAYING USING CARD"<<endl;
    }
};

class ErrorCard : public Payment{
    public:
    void pay() override{
        cout<<"ERROR : THE ENETERD CARD PIN IS WRONG"<<endl;
    }
};

class NetBanking : public Payment{
    public:
    void pay() override{
        cout<<"PAYING USING NET BANKING"<<endl;
    }
};

class ErrorNetBanking: public Payment{
    public:
    void pay() override{
        cout<<"ERROR: THE ENTERED PIN FOR NET BANKING IS WRONG"<<endl;
    }
};

class User{
    public:
    virtual Payment* makePayment(string &type)=0;
};

class PaymentByUPI : public User{
    public:
    Payment* makePayment(string &type) override{
        if(type=="OK")return new UPI();
        else return new ErrorUPI();
    }
};

class PaymentByCard : public User{
    public:
    Payment* makePayment(string &type) override{
        if(type=="OK")return new Card();
        else return new ErrorCard();
    }
};

class PaymentByNet : public User{
    public:
    Payment* makePayment(string &type)override{
        if(type=="OK")return new NetBanking();
        else return new ErrorNetBanking();
    }
};

int main(){
    string PIN="ONE";
    User *first=new PaymentByNet();
    Payment *upi=first->makePayment(PIN);
    upi->pay();
    return 0;
}