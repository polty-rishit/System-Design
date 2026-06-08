#include<bits/stdc++.h>
using namespace std;

class IDocumentReader{
    public:
    virtual void unlockPDF(string filePath,string pass)=0;
    virtual ~IDocumentReader(){}
};

class RealDocumentReader : public IDocumentReader{
    public:
    void unlockPDF(string filePath,string pass) override{
        cout << "[RealDocumentReader] Unlocking PDF at: " << filePath << "\n";
        cout << "[RealDocumentReader] PDF unlocked successfully with password: " << pass << "\n";
        cout << "[RealDocumentReader] Displaying PDF content...\n";
    }
};

class User{
    public:
    string name;
    bool premiumMember;
    User(string n,bool isPremium){
        this->name=n;
        this->premiumMember=isPremium;
    }
};

class DocumentProxy : public IDocumentReader{
    RealDocumentReader *realReader;
    User* user;
    public:
    DocumentProxy(User *user){
        realReader=new RealDocumentReader();
        this->user=user;
    }
    void unlockPDF(string filePath,string pass) override{
        if(!user->premiumMember){
            cout<<"[DOCUMENTPROXY] ACCESS DENIED. ONLY PREMIUUM MEMBERS CAN UNLOCK THE PDF.."<<endl;
            return ;
        }
        realReader->unlockPDF(filePath,pass);
    }
    ~DocumentProxy(){
        delete realReader;
    }
};

int main(){
    User *user1=new User("ROhan",false);
    User* user2=new User("Rashmi",true);
    cout<<"==ROHAN (NON-PREMIUM) TRIE TO UNLOCK PDF=="<<endl;
    IDocumentReader* doc=new DocumentProxy(user1);
    doc->unlockPDF("protected_document.pdf","secret123");
    delete doc;

    cout<<endl<<"=== RASHMI( PREMIUM ) UNLOCKS PDF==="<<endl;
    doc=new DocumentProxy(user2);
    doc->unlockPDF("protected_document.pdf","secret123");
    delete doc;
    return 0;
}