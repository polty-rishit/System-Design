#include<bits/stdc++.h>
using namespace std;

class VendingMachine;

class NoCoinState;
class HasCoinState;
class DispenseState;
class SoldOutState;

class VendingState{
    public:
    virtual VendingState* insertCoin(VendingMachine* machine,int coint)=0;
    virtual VendingState* selectItem(VendingMachine* machine)=0;
    virtual VendingState* dispense(VendingMachine* machine)=0;
    virtual VendingState* returnCoin(VendingMachine* machine)=0;
    virtual VendingState* refill(VendingMachine* machine,int q)=0;
    virtual string getState()=0;
};

int main(){

}