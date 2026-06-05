//STRATEGY DESIGN PATTERN

#include<bits/stdc++.h>
using namespace std;

class UPI{
    public:
    virtual void payUPI()=0;
    virtual ~UPI(){};
};

class UPIPay : public UPI{
    public:
    void payUPI() override{
        cout<<"PAYING USING THE UPI."<<endl;
    }
};

class NoUPIPay : public UPI{
    public:
    void payUPI() override{
        cout<<"CANNOT PAY USING UPI"<<endl;
    }
};

class Card{
    public:
    virtual void payCard()=0;
    virtual ~Card(){};
};

class YesCardPay : public Card{
    public:
    void payCard() override{
        cout<<"PAYING USING THE CARD"<<endl;
    }
};

class NoCardPay : public Card{
    public:
    void payCard() override{
        cout<<"NOT PAYING USING CARD"<<endl;
    }
};

class Payment{
    protected:
    UPI *upipay;
    Card *cardpay;

    public:
    Payment(UPI *u,Card*c){
        this->upipay=u;
        this->cardpay=c;
    }
    
    void payUpi(){
        upipay->payUPI();
    }
    void payCard(){
        cardpay->payCard();
    }
};

class Customer : public Payment{
    public:
    Customer(UPI* u,Card *c):Payment(u,c){}
};

int main(){
    Payment *First=new Customer(new UPIPay(),new NoCardPay());
    First->payUpi();
    First->payCard();
    return 0;
}

