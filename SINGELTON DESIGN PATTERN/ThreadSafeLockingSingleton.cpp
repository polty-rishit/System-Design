#include<bits/stdc++.h>
using namespace std;

class Singleton{
    private:
    static Singleton* instance;
    static mutex mtx;

    Singleton(){
        cout<<"SINGLETON CONSTRUTOR CALLED"<<endl;
    }
    public:
    static Singleton* getInstance(){
        lock_guard<mutex>lock(mtx);
        if(instance==NULL)instance=new Singleton();
        return instance;
    }
};

Singleton *Singleton::instance=NULL;
mutex Singleton::mtx;
int main(){
    Singleton* s1=Singleton::getInstance();
    Singleton*s2=Singleton::getInstance();
    cout<<(s1==s2)<<endl;
}