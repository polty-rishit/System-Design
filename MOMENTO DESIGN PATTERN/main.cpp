#include<bits/stdc++.h>
using namespace std;

class DatabaseMomento{
    private:
    map<string,string>hsh;
    public:
    DatabaseMomento(const map<string,string>&db){
        this->hsh=db;
    }
    map<string,string> getState()const {
        return hsh;
    }
};

class DataBase{
    private:
    map<string,string>records;
    public:
    void insert(const string &key,const string &value){
        records[key]=value;
        cout<<"INSERTED : "<<key<<" = "<<value<<endl;
    }

    void update(const string &key,const string &value){
        if(records.find(key)!=records.end()){
            records[key]=value;
            cout<<"UPDATED : "<<key<<" = "<<value<<endl;
        }else{
            cout<<"KEY NOT FOUND FOR UPDATE"<<endl;
        }
    }

    void remove(const string&key){
        auto it=records.find(key);
        if(it!=records.end()){
            records.erase(it);
            cout<<"Deleted: "<<key<<endl;
        }else cout<<"KEY NOT FOUND FOR DELETION."<<endl;
    }

    DatabaseMomento *createMomento(){
        cout<<"CREATING DATABASE BACKUP"<<endl;
        return new DatabaseMomento(records);
    }

    void restoreFromMomento(const DatabaseMomento &momento){
        records=momento.getState();
        cout<<"DATABASE RESTORED FROM BACKUP!"<<endl;
    }

    void disPlayrecords(){
        cout<<endl<<"--- CURRENT DATABASE STATE ---"<<endl;
        if(records.empty())cout<<"DATABASE IS EMPTY."<<endl;
        else{
            for(const auto &r:records){
                cout<<r.first<<" = "<<r.second<<endl;
            }
        }
        cout<<"-----------------------------------------\n"<<endl;
    }
};

class TransactionManager{
    private:
    DatabaseMomento* backup;
    public:
    TransactionManager():backup(NULL){}
    ~TransactionManager(){
        if(backup)delete backup;
    }

    void beginTransaction(DataBase& db){
        cout<<"=== BEGIN TRANSACTION ==="<<endl;
        if(backup)delete backup;
        backup=db.createMomento();
    }

    void commitTransaction(){
        cout<<"=== COMMIT TRANSACTION ==="<<endl;
        if(backup){
            delete backup;
            backup=NULL;
        }
        cout<<"TRANSACTION COMMITED SUCCESSFULLY!"<<endl;
    }

    void rollBack(DataBase &db){
        cout<<"=== ROLLING BACK TRANSACTION ==="<<endl;
        if(backup){
            db.restoreFromMomento(*backup);
            delete backup;
            backup=NULL;
            cout<<"TRANSACTIOM ROLLED BACK"<<endl;
        }
        else cout<<"NO BACKUP AVAILABLE FOR ROLLBACK"<<endl;
    }
};

int main(){
    DataBase db;
    TransactionManager tm;
    
    tm.beginTransaction(db);
    db.insert("user1","Aditya");
    db.insert("user2","Rohit");
    tm.commitTransaction();

    db.disPlayrecords();

    tm.beginTransaction(db);
    db.insert("user3","Rishit");
    db.insert("user4","Polty");

    db.disPlayrecords();
    cout<<"Error: SOMETHING WENT WRONG DURING TRANSACTION"<<endl;
    tm.rollBack(db);
    db.disPlayrecords();
    return 0;
}