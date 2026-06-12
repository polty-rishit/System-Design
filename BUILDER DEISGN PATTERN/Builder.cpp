#include<bits/stdc++.h>
using namespace std;

class HttpRequest{
    private:
    string url;
    string method;
    map<string,string>headers;
    map<string,string>query;
    string body;
    int timeout;

    HttpRequest(){};

    public:
    friend class HttpRequestBuilder;

    void execute(){
        cout<<"EXECUTING "<<method<<" request to "<<url<<endl;
        if(!query.empty()){
            cout<<"QUERY PARAMETERS: "<<endl;
            for(const auto &p:query){
                cout<<" "<<p.first<<" = "<<p.second<<endl;
            }
        }
        cout<<"HEADERES: "<<endl;
        for(const auto &h:headers){
            cout<<" "<<h.first<<" : "<<h.second<<endl;
        }
        if(!body.empty())cout<<"BODY: "<<body<<endl;
        cout<<"TIMEOUT: "<<timeout<<" seconds "<<endl;
        cout<<"REQUEST EXCEUTED SUCCESSFULLY "<<endl;
    }
};

class HttpRequestBuilder{
    private:
    HttpRequest req;
    public:
    HttpRequestBuilder& withUrl(const string &u){
        req.url=u;
        return *this;
    }

    HttpRequestBuilder &wtihMethod(string method){
        req.method=method;
        return *this;
    }

    HttpRequestBuilder& withHeader(const string&key,const string &value){
        req.headers[key]=value;
        return *this;
    }

    HttpRequestBuilder& withQuery(const string&key,const string& value){
        req.query[key]=value;
        return *this;
    }

    HttpRequestBuilder& withBody(const string& body){
        req.body=body;
        return *this;
    }

    HttpRequestBuilder& withTimeOut(int t){
        req.timeout=t;
        return *this;
    }

    HttpRequest build(){
        if(req.url.empty())throw runtime_error("URL CANNOT BE EMPTY");
        return req;
    }
};

int main(){
    HttpRequest req=HttpRequestBuilder()
    .withUrl("https://rishitraj.in")
    .wtihMethod("POST")
    .withHeader("Content-Type","applicatio/json")
    .withHeader("Accept","applicaiton/json")
    .withQuery("key","12345")
    .withBody("{\"name\":\"Aditya\"}")
    .withTimeOut(60)
    .build();
    req.execute();
}