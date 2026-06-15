#include<bits/stdc++.h>
using namespace std;

class Power{
    public:
    void providePower(){
        cout<<"POWER SUPPLY : PROVIDING POWER ...."<<endl;
    }
};

class CollingSystem{
    public:
    void startFan(){
        cout<<"COOLING SYSTEM : FANS STARTED..."<<endl;
    }
};

class CPU{
    public:
    void initialize(){
        cout<<"CPU: INITIALIZATION STARTED...."<<endl;
    }
};

class Memory{
    public:
    void selfTest(){
        cout<<"MEMORY: SELF-TEST PAASED..."<<endl;
    }
};

class HardDrive{
    public:
    void signUp(){
        cout<<"HARD DRIVE: SPINNING UP..."<<endl;
    }
};

class BIOS {
public:
    void boot(CPU& cpu, Memory& memory) {
        cout << "BIOS: Booting CPU and Memory checks..." << endl;
        cpu.initialize();
        memory.selfTest();
    }
};

class OperatingSystem {
public:
    void load() {
        cout << "Operating System: Loading into memory..." << endl;
    }
};

class ComupterFacade{
    private:
    Power powerSupply;
    CollingSystem coolingSystem;
    CPU cpu;
    Memory memory;
    HardDrive hardDrive;
    BIOS bios;
    OperatingSystem os;

    public:
    void startComputer(){
        cout<<"---Starting computer---"<<endl;
        powerSupply.providePower();
        coolingSystem.startFan();
        bios.boot(cpu, memory);
        hardDrive.signUp();
        os.load();
        cout << "Computer Booted Successfully!" << endl;
    }
};

int main(){
    ComupterFacade *computer=new ComupterFacade();
    computer->startComputer();
}
