#include<bits/stdc++.h>
using namespace std;

class Collegue;

class IMediator{
    public:
    virtual ~IMediator(){}
    virtual void registerCollegue(Collegue *c)=0;
    virtual void send(const string &from,const string &msg)=0;
    virtual void sendPrivate(const string& from , const string &to,const string& msg)=0;
};

class Collegue{
    protected:
    IMediator *mediator;
    public:
    Collegue(IMediator *m){
        this->mediator=m;
        mediator->registerCollegue(this); 
    }
    virtual ~Collegue(){}
    virtual string getName()=0;
    virtual void send(const string &msg)=0;
    virtual void sendPrivate(const string &to,const string &msg)=0;
    virtual void receive(const string &from,const string &msg)=0;
};

class ChatMedaitor : public IMediator{
    private:
    vector<Collegue*>collegues;
    vector<pair<string,string>>mutes;
    public:
    void registerCollegue(Collegue *c) override{
        collegues.push_back(c);
    }
    void mute(const string& who,const string &whom){
        mutes.push_back({who,whom});
    }
    void send(const string &from,const string& msg) override{
        cout<<"["<<from<<" brodcast]: "<<msg<<endl;
        for(Collegue *c:collegues){
            if(c->getName()==from)continue;
            bool isMuted=0;
            for(auto &p:mutes){
                if(from==p.second && c->getName()==p.first){
                    isMuted=1;
                    break;
                }
            }
            if(!isMuted)c->receive(from,msg);
        }
    }

    void sendPrivate(const string&from,const string &to,const string &msg) override{
        cout<<"["<<from<<"->"<<to<<"]: "<<msg<<endl;
        for(Collegue *c:collegues){
            if(c->getName()==to){
                for(auto &p:mutes){
                    if(from==p.second && to==p.first){
                        cout<<"\n[MESSAGE IS MUTED]"<<endl;
                        return ;
                    }
                }
                c->receive(from,msg);
                return ;
            }
        }
        cout<<"[MEDIATOR] USER \""<<to<<"\" not found]\n";
    }
};

class User : public Collegue{
    private:
    string name;
    public:
    User(const string &n,IMediator* m) :Collegue(m){
            this->name=n;
        }
    string getName() override{
        return name;
    }
    void send(const string &msg) override{
        mediator->send(name,msg);
    }
    void sendPrivate(const string &to,const string &msg) override{
        mediator->sendPrivate(name,to,msg);
    }
    void receive(const string &from,const string &msg) override{
        cout<<"     "<<name<<" got from "<<from<<": "<<msg<<endl; 
    }
};


int main(){
    ChatMedaitor* chatRoom=new ChatMedaitor();
    User *user1=new User("Rohan",chatRoom);
    User *user2=new User("Neha",chatRoom);
    User* user3=new User("Mohan",chatRoom);
    chatRoom->mute("Rohan","Mohan");
    user1->send("Hello EveryOne");
    user3->sendPrivate("Neha","Hey Neha!");

    delete user1,user2,user3,chatRoom;
    return 0;
}