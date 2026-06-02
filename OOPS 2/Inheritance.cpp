#include<bits/stdc++.h>
using namespace std;

class Car{
   protected:
   string model;
   string brand;
   bool isEngineOn;
   int currSpeed;

   public:
   Car(string a,string b){
    this->brand=a;
    this->model=b;
    isEngineOn=false;
    currSpeed=0;
   }

   void startEngine(){
    isEngineOn=true;
    cout << brand << " " << model << " : Engine started." << endl;
   }

   void stopEngine() {
        isEngineOn = false;
        currSpeed = 0;
        cout << brand << " " << model << " : Engine turned off." << endl;
    }

    void accelerate() { 
        if (!isEngineOn) {
            cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
            return;
        }
        currSpeed += 20;
        cout << brand << " " << model << " : Accelerating to " << currSpeed << " km/h" << endl;
    }

    void brake() { 
        currSpeed -= 20;
        if (currSpeed < 0) currSpeed = 0;
        cout << brand << " " << model << " : Braking! Speed is now " << currSpeed << " km/h" << endl;
    }

    virtual ~Car() {}
};

class ManualCar : public Car{
   private:
   int currGear;

   public:
   ManualCar(string b,string m):Car(b,m){
    currGear=0;
   }
   void gearShift(int gear){
    currGear=gear;
    cout << brand << " " << model << " : Shifted to gear " << currGear << endl;
   }
};

class ElectricCar: public Car{
    private:
    int batteryLvl;
    public:
    ElectricCar(string b, string m) : Car(b, m) {
        batteryLvl = 100;
    }
    void chargeBattery() {  
        batteryLvl = 100;
        cout << brand << " " << model << " : Battery fully charged!" << endl;
    }
};

int main()
{
    ManualCar* myManualCar = new ManualCar("Suzuki", "WagonR");
    myManualCar->startEngine();
    myManualCar->gearShift(1);
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;

    cout << "----------------------" << endl;

    ElectricCar* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->chargeBattery(); //specific to electric car
    myElectricCar->startEngine(); 
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();
    delete myElectricCar; 

    return 0;
}