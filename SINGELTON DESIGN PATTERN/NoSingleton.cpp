#include<bits/stdc++.h>
using namespace std;

class NoSingleton{
    public:
    NoSingleton(){
        cout<<"SINGLETON CONSTRUCTOR CALLED, NEW OBJECT CREATED."<<endl;
    }
};

int main(){
    NoSingleton *s1=new NoSingleton();
    NoSingleton *s2=new NoSingleton();
    cout<<(s1==s2)<<endl;
}