#include<bits/stdc++.h>
using namespace std;

class Singleton{
    private:
    static Singleton *instance;

    Singleton(){
        cout<<"SINGLETON CONSTRUCTUR CALLED"<<endl;
    }
    public:
    static Singleton *getInstance(){
        if(instance==NULL)instance=new Singleton();
        return instance;
    }
};

Singleton *Singleton :: instance=NULL;

int main(){
    Singleton *s1=Singleton ::getInstance();
    Singleton *s2=Singleton::getInstance();
    cout<<(s1==s2)<<endl;
}