#include<bits/stdc++.h>
using namespace std;

struct PaymentRequest{
    string sender;
    string reciever;
    double amount;
    string currency;

    PaymentRequest(const string &s,const string r,int a,const string &curr){
        this->sender=s;
        this->reciever=r;
        this->amount=a;
        this->currency=curr;
    }
};

class BankingSystem{
    public:
    virtual bool processPayment(double amount)=0;
    virtual ~BankingSystem(){}
};

class PaytmBankingSystem :  public BankingSystem{
    public:
    PaytmBankingSystem(){}
    bool processPayment(double amount) override{
        int r=rand()%100;
        return r<80;
    }
};

class RazorPayBankingSystem : public BankingSystem{
    public:
    RazorPayBankingSystem(){}
    bool processPayment(double amount) override{
        cout<<"[BANKINGSYSTEM - RAZORPAY] PROCESSING PAYMENT OF "<<amount<<"----\n";
        int r=rand()%100;
        return r<90 ;
    }
};

class PaymentGateway{
    protected:
    BankingSystem *bankingSystem;
    public:
    PaymentGateway(){
        bankingSystem=NULL;
    }
    virtual ~PaymentGateway(){
        delete bankingSystem;
    }
    virtual bool processPayment(PaymentRequest* request){
        if(!validatePayment(request)){
            cout<<"[PAYMENTGATEWAY] VALIDATION FAILED FOR"<<request->sender<<endl;
            return false;
        }
        if(!initiatePayment(request)){
            cout<<"[PAYMENTGATEWAY] INITIATION FAILED FOR "<<request->sender<<endl;
            return false;
        }
        if(!confirmPayment(request)){
            cout<<"[PAYMENTGATEWAY] CONFIRMATION FAILED FOR "<<request->sender<<endl;
            return false;
        }
        return true;
    }


    virtual bool validatePayment(PaymentRequest *request)=0;
    virtual bool initiatePayment(PaymentRequest *request)=0;
    virtual bool confirmPayment(PaymentRequest* request)=0;
};

class PaytmGateway : public PaymentGateway{
    public:
    PaytmGateway(){
        bankingSystem=new PaytmBankingSystem();
    }
    bool validatePayment(PaymentRequest* request) override{
        cout<<"[PAYTM] VALIDATION PAYMENT FOR "<<request->sender<<endl;
        if(request->amount <=0 || request->currency!="INR")return false;
        return true;
    }
    bool initiatePayment(PaymentRequest* request) override{
        cout<<"PAYTM INITIATING PAYMENT OF "<<request->sender<<endl;
        return bankingSystem->processPayment(request->amount);
    }
    bool confirmPayment(PaymentRequest * request) override{
        cout<<"[PAYTM] CONFIRMING PAYMENT FOR"<<request->sender<<endl;
        return true;
    }
};

class RazorpayGateway : public PaymentGateway {
public:
    RazorpayGateway() {
        bankingSystem = new RazorPayBankingSystem();
    }
    bool validatePayment(PaymentRequest* request) override {
        cout << "[Razorpay] Validating payment for " << request->sender << ".\n";

        if (request->amount <= 0) {
            return false;
        }
        return true;
    }
    bool initiatePayment(PaymentRequest* request) override {
        cout << "[Razorpay] Initiating payment of " << request->amount 
                  << " " << request->currency << " for " << request->sender << ".\n";

        return bankingSystem->processPayment(request->amount);
       
    }
    bool confirmPayment(PaymentRequest* request) override {
        cout << "[Razorpay] Confirming payment for " << request->sender << ".\n";

        // Confirmation always succeeds in this simulation
        return true;
    }
};

// ----------------------------
// Proxy class that wraps a PaymentGateway to add retries (Proxy Pattern)
// ----------------------------
class PaymentGatewayProxy : public PaymentGateway {
    PaymentGateway* realGateway;
    int retries;
public:
    PaymentGatewayProxy(PaymentGateway* gateway, int maxRetries) {
        realGateway = gateway;
        retries = maxRetries;
    }
    ~PaymentGatewayProxy() {
        delete realGateway;
    }
    bool processPayment(PaymentRequest* request) override {
        bool result = false;
        for (int attempt = 0; attempt < retries; ++attempt) {
            if (attempt > 0) {
                cout << "[Proxy] Retrying payment (attempt " << (attempt+1)
                          << ") for " << request->sender << ".\n";
            }
            result = realGateway->processPayment(request);
            if (result) break;
        }
        if (!result) {
            cout << "[Proxy] Payment failed after " << (retries)
                      << " attempts for " << request->sender << ".\n";
        }
        return result;
    }
    bool validatePayment(PaymentRequest* request) override {
        return realGateway->validatePayment(request);
    }
    bool initiatePayment(PaymentRequest* request) override {
        return realGateway->initiatePayment(request);
    }
    bool confirmPayment(PaymentRequest* request) override {
        return realGateway->confirmPayment(request);
    }
};

// ----------------------------
// Gateway Factory for creating gateway (Singleton)
// ----------------------------
enum class GatewayType { 
    PAYTM, 
    RAZORPAY
};

class GatewayFactory {
private:
    static GatewayFactory instance;
    // Private constructor and delete copy/assignment to ensure no one can clone or reassign your singleton.
    GatewayFactory() {}
    GatewayFactory(const GatewayFactory&) = delete;
    GatewayFactory& operator=(const GatewayFactory&) = delete;
    
public:
    static GatewayFactory& getInstance() {
        return instance;
    }
    PaymentGateway* getGateway(GatewayType type) {
        if (type == GatewayType::PAYTM) {
            PaymentGateway* paymentGateway = new PaytmGateway();
            return new PaymentGatewayProxy(paymentGateway, 3);
        } else {
            PaymentGateway* paymentGateway = new RazorpayGateway();
            return new PaymentGatewayProxy(paymentGateway, 1);
        }
    }
};

// define static instance
GatewayFactory GatewayFactory::instance;

// ----------------------------
// Unified API service (Singleton)
// ----------------------------
class PaymentService {
private:
    static PaymentService instance;
    PaymentGateway* gateway;

    PaymentService() { 
        gateway = nullptr; 
    }
    ~PaymentService() { 
        delete gateway; 
    }

    // Private constructor and delete copy/assignment to ensure no one can clone or reassign your singleton.
    PaymentService(const PaymentService&) = delete;
    PaymentService& operator=(const PaymentService&) = delete;

public:
    static PaymentService& getInstance() {
        return instance;
    }
    void setGateway(PaymentGateway* g) {
        if (gateway) delete gateway;
        gateway = g;
    }
    bool processPayment(PaymentRequest* request) {
        if (!gateway) {
            cout << "[PaymentService] No payment gateway selected.\n";
            return false;
        }
        return gateway->processPayment(request);
    }
};

PaymentService PaymentService::instance;

// ----------------------------
// Controller class for all client requests (Singleton)
// ----------------------------
class PaymentController {
private:
    static PaymentController instance;
    PaymentController() {}
    PaymentController(const PaymentController&) = delete;
    PaymentController& operator=(const PaymentController&) = delete;
public:
    static PaymentController& getInstance() {
        return instance;
    }
    bool handlePayment(GatewayType type, PaymentRequest* req) {
        PaymentGateway* paymentGateway = GatewayFactory::getInstance().getGateway(type);
        PaymentService::getInstance().setGateway(paymentGateway);
        return PaymentService::getInstance().processPayment(req);
    }
};

PaymentController PaymentController::instance;

// ----------------------------
// Main: Client code now goes through controller
// ----------------------------
int main() {

    srand(static_cast<unsigned>(time(nullptr)));

    PaymentRequest* req1 = new PaymentRequest("Aditya", "Shubham", 1000.0, "INR");

    cout << "Processing via Paytm\n";
    cout << "------------------------------\n";
    bool res1 = PaymentController::getInstance().handlePayment(GatewayType::PAYTM, req1);
    cout << "Result: " << (res1 ? "SUCCESS" : "FAIL") << "\n";
    cout << "------------------------------\n\n";

    PaymentRequest* req2 = new PaymentRequest("Shubham", "Aditya", 500.0, "USD");

    cout << "Processing via Razorpay\n";
    cout << "------------------------------\n";
    bool res2 = PaymentController::getInstance().handlePayment(GatewayType::RAZORPAY, req2);
    cout << "Result: " << (res2 ? "SUCCESS" : "FAIL") << "\n";
    cout << "------------------------------\n";

    return 0;
}