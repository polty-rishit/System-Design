//It shows a "has a" relationship.
#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    void method1(){
        cout<<"METHOD 1 CALLED\n";
    }
};

class B{
    public:
    A *a;
    public:
    B(){
        a=new A();
    }
    void method2(){
        cout<<"METHOD 2 CALLED"<<endl;
    }
};

int main(){
    B *b=new B();
    b->method2();
    b->a->method1();
}