#include<bits/stdc++.h>
using namespace std;

class Singleton{
    static Singleton* instance;
    Singleton(){
        cout<<"SINGLETON CONSTRUCTOR CALLED"<<endl;
    }
    public:
    static Singleton* getInstance(){
        return instance;
    }
};

Singleton* Singleton::instance=new Singleton();

int main(){
    Singleton *s1=Singleton::getInstance();
    Singleton *s2=Singleton::getInstance();
    cout<<(s1==s2)<<endl;
}