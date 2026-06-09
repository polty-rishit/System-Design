#include<bits/stdc++.h>
using namespace std;

class INotification{
    public:
    virtual string getContent() const=0;
    virtual ~INotification(){}
};

class SimpleNotification : public INotification{
    private:
    string text;
    public:
    SimpleNotification(const string &msg){
        this->text=msg;
    }
    string getContent() const override{
        return text;
    }
};

class INotificationDecorator : public INotification{
    protected:
    INotification *notification;
    public:
    INotificationDecorator(INotification *n){
        this->notification=n;
    }
    virtual ~INotificationDecorator(){
        delete notification;
    }
};

class TimeStampDecorator : public INotificationDecorator{
    public:
    TimeStampDecorator(INotification *n):INotificationDecorator(n){}
    string getContent() const override{
        return "[2025-04-13 14:22:00] " + notification->getContent(); 
    }
};

class SignatureDecorator : public INotificationDecorator{
    private:
    string signature;
    public:
    SignatureDecorator(INotification* n, const string &sig):INotificationDecorator(n){
        signature=sig;
    }
    string getContent()const override{
        return notification->getContent() + "\n-- " + signature + "\n\n";
    }
};

class IObserver{
    public:
    virtual void update()=0;
    virtual ~IObserver(){}
};

class IObservable{
    public:
    virtual void addObserver(IObserver *observer)=0;
    virtual void removeObserver(IObserver *observer)=0;
    virtual void notify()=0;
};

class NotificationObservable : public IObservable{
    private:
    vector<IObserver*>observers;
    INotification* currNotification;
    public:
    NotificationObservable(){
        currNotification=NULL;
    }
    void addObserver(IObserver *obs) override{
        observers.push_back(obs);
    }
    void removeObserver(IObserver* obs)override{
        observers.erase(remove(observers.begin(),observers.end(),obs),observers.end());
    }
    void notify() override{
        for(unsigned int i=0;i<observers.size();i++){
            observers[i]->update();
        }
    }
    void setNotification(INotification* notifiaction){
        if(currNotification!=NULL)delete currNotification;
        currNotification=notifiaction;
        notify();
    }
    INotification* getNotification(){
        return currNotification;
    }
    string getNotificationContent(){
        return currNotification->getContent();
    }
    ~NotificationObservable(){
        if(currNotification!=NULL)delete currNotification;
    }
};

class Logger: public IObserver{
    private:
    NotificationObservable* notificationObservable;
    public:
    Logger(NotificationObservable* observable){
        this->notificationObservable=observable;
    }
    void update(){
        cout<<"LOGGING NEW NOTIFICATION :"<<endl<<notificationObservable->getNotificationContent();
    }
};
class INotificationStrategy{
    public:
    virtual void sendNotification(string content)=0;
};

class EmailStrategy : public INotificationStrategy{
    private:
    string emailId;
    public:
    EmailStrategy(string emailId){
        this->emailId=emailId;
    }
    void sendNotification(string content) override{
        cout<<"SENDING EMAIL NOTIFICATION "<<emailId<<endl<<content;
    }
};

class SMSStrategy : public INotificationStrategy{
    private:
    string mobileNumber;
    public:
    SMSStrategy(string number){
        this->mobileNumber=number;
    }
    void sendNotification(string content) override{
        cout<<"SENDING SMS NOTIFICATION TO : "<<mobileNumber<<endl<<content;
    }
};

class PopUpStrategy : public INotificationStrategy{
    public:
    void sendNotification(string content){
        cout<<"SENDING POP UP NOTIFICATIO TO :"<<content<<endl;
    }
};

class NotificationEngine : public IObserver{
    private:
    NotificationObservable* notificationObservable;
    vector<INotificationStrategy*>notificationStrategies;
    public:
    NotificationEngine(NotificationObservable* observable){
        this->notificationObservable=observable;
    }
    void addNotification(INotificationStrategy* ns){
        this->notificationStrategies.push_back(ns);
    }
    void update(){
        string notificationContent=notificationObservable->getNotificationContent();
        for(const auto n:notificationStrategies){
            n->sendNotification(notificationContent);
        }
    }
};

class NotificationService{
    private:
    NotificationObservable* observable;
    static NotificationService* instance;
    vector<INotification*>notifications;
    NotificationService(){
        observable=new NotificationObservable();
    }

    public:
    static NotificationService * getInstance(){
        if(instance==NULL)instance=new NotificationService();
        return instance;
    }
    NotificationObservable* getObservable(){
        return observable;
    }
    void sendNotification(INotification *notification){
        notifications.push_back(notification);
        observable->setNotification(notification);
    }
    ~NotificationService(){
        delete observable;
    }
};

NotificationService * NotificationService::instance=NULL;
int main(){
    NotificationService *notificationService=NotificationService::getInstance();
    NotificationObservable *notificationObservable=notificationService->getObservable();

    Logger * logger=new Logger(notificationObservable);

    NotificationEngine* notificationEngine =new NotificationEngine(notificationObservable);
    notificationEngine->addNotification(new EmailStrategy("one@gmail.com"));
    notificationEngine->addNotification(new SMSStrategy("+91 8936037881"));
    notificationEngine->addNotification(new PopUpStrategy());

    notificationObservable->addObserver(logger);
    notificationObservable->addObserver(notificationEngine);

    INotification *notification =new SimpleNotification("YOUR ORDER HAS BEEN SHIPPED!");
    notification=new TimeStampDecorator(notification);
    notification=new SignatureDecorator(notification,"Customer Care");

    notificationService->sendNotification(notification);

    delete logger;
    delete notificationEngine;
    return 0;
}