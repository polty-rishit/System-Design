#include<bits/stdc++.h>
using namespace std;

class SportsCar{

    public:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    string tyreCompany;

    public:
    SportsCar(string b, string m) {
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 1000;
        currentGear = 0;
        tyreCompany = "MRF";
    }

    int getSpeed() {
        return currentSpeed;
    }

    string getTyreCompany() {
        return tyreCompany;
    }

    void setTyreCompany(string tyreCompany) {
        this->tyreCompany = tyreCompany;
    }

    void startEngine() {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine starts with a roar!" << endl;
    }

    void shiftGear(int gear) {
        if (!isEngineOn) {
            cout << brand << " " << model << " : Engine is off! Cannot Shift Gear." << endl;
            return;
        }
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << currentGear << endl;
    }

    void accelerate() {
        if (!isEngineOn) {
            cout << brand << " " << model << " : Engine is off! Cannot accelerate." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h" << endl;
    }

    void brake() {
        currentSpeed -= 20;
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/h" << endl;
    }

    void stopEngine() {
        isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
        cout << brand << " " << model << " : Engine turned off." << endl;
    }

    ~SportsCar() {}
};

int main(){
   SportsCar myCar("Ford","Mustang");
    myCar.startEngine();
    myCar.shiftGear(1);
    myCar.accelerate();
    myCar.shiftGear(2);
    myCar.accelerate();
    myCar.brake();
    myCar.stopEngine();

    // myCar.currentSpeed=500;

    cout<<"Current speed of My Sports Car is :"<<myCar.getSpeed()<<endl;
    return 0;
}