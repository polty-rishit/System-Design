#include<bits/stdc++.h>
#include<mutex>
using namespace std;

class Singleton{
    private:
    static Singleton* instance;
    static std::mutex mtx;

    Singleton(){
        cout<<"SINGLETON CONSTRUCTOR CALLED"<<endl;
    }
    public:
    static Singleton* getInstance(){
        if(instance==NULL){
            lock_guard<std::mutex>lock(mtx);
            if(instance==NULL)instance=new Singleton();
        }
        return instance;
    }
    
};

Singleton *Singleton::instance=NULL;
std::mutex Singleton::mtx;

int main()
{
    Singleton* s1=Singleton::getInstance();
    Singleton* s2=Singleton::getInstance();
    cout<<(s1==s2)<<endl;

}