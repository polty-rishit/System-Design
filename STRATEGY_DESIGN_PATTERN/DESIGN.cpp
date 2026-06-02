#include<bits/stdc++.h>
using namespace std;

class WalkableRobot{
   public:
   virtual void walk()=0;
   virtual ~WalkableRobot(){};
};
class NormalWalk :public WalkableRobot{
     public:
     void walk(){
        cout<<"WALKING NORMALLY"<<endl;
    }
};
class NoWalk: public WalkableRobot{
     public:
     void walk(){
        cout<<"CANNOT WALK"<<endl;
     }
};

class TalkableRobot{
    public:
    virtual void talk()=0;
    virtual ~TalkableRobot(){};
};

class NormalTalk : public TalkableRobot{
    public:
    void talk(){
        cout<<"TALKING NORAMLLY"<<endl;
    }
};

class NoTalk : public TalkableRobot{
    public:
    void talk(){
        cout<<"CANNOT TALK"<<endl;
    }
};

class Flyable{
    public:
    virtual void fly()=0;
    virtual ~Flyable(){};
};

class NormalFly : public Flyable{
    public:
    void fly(){
        cout<<"FLYING NORMALLY"<<endl;
    }
};

class NoFly : public Flyable{
    public:
    void fly(){
        cout<<"CANNOT FLY"<<endl;
    }
};

class Robot{
    protected:
    WalkableRobot * walkBehaviour;
    TalkableRobot *talkBehaviour;
    Flyable *flyBehaviour;

    public:
    Robot(WalkableRobot *w,TalkableRobot *t,Flyable*f){
        this->walkBehaviour=w;
        this->talkBehaviour=t;
        this->flyBehaviour=f;
    }

    void walk(){
        walkBehaviour->walk();
    }
    void talk(){
        talkBehaviour->talk();
    }
    void fly(){
        flyBehaviour->fly();
    }
    virtual void projection()=0;
};

class CompanionRobot : public Robot{
    public:
    CompanionRobot(WalkableRobot *w, TalkableRobot *t,Flyable *f)
        :Robot(w,t,f){}

    void projection(){
        cout<<"DISPLAYING FRIENDLY COMPANION FEATURES"<<endl;
    }
};
class WorkerRobot :public Robot{
    public:
    WorkerRobot(WalkableRobot *w, TalkableRobot *t,Flyable *f)
    :Robot(w,t,f){}
    void projection(){
        cout<<"DISPLAYING WORKER EFFICIENCY STATS.."<<endl;
    }
};

int main(){
    Robot *robot1=new CompanionRobot(new NormalWalk(),new NormalTalk,new NoFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();

     cout << "--------------------" << endl;

     Robot *robot2=new WorkerRobot(new NoWalk(),new NoTalk(),new NormalFly());
     robot2->walk();
     robot2->talk();
     robot2->fly();
     robot2->projection();
     return 0;
}