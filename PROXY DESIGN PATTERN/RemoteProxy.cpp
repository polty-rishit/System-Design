#include<bits/stdc++.h>
using namespace std;

class IDataService{
    public:
    virtual string fetchData()=0;
    virtual ~IDataService(){}
};

class RealDataService : public IDataService{
    public:
    RealDataService(){
        cout<<"[REALDATA SEVICE] : INITIALISED (SIMULATING REMOTE SETUP)"<<endl;
    }
    string fetchData() override{
        return "[REALDATASERVICE] Data from server";
    }
};
class DataServiceProxy : public IDataService{
    private:
    RealDataService * realService=NULL;
    public:
    DataServiceProxy(){
        realService=new RealDataService();
    }
    string fetchData() override{
        cout<<"[DATASERVICE] CONNECCTING TO REMOTE SERVER"<<endl;
        return realService->fetchData();
    }
};

int main(){
    IDataService *data=new DataServiceProxy();
    data->fetchData();
}