#include<bits/stdc++.h>
using namespace std;

class IImage{
    public:
    virtual void display()=0;
    virtual ~IImage(){}
};

class RealImage : public IImage{
    string fileName;
    public:
    RealImage(string file){
        this->fileName=file;
        cout<<"[REALIMAGE] LOADING IMAGE FOM DISK: "<<fileName<<endl;
    }
    void display() override{
        cout<<"[REALIMAGE] DISPLAYING "<<fileName<<endl;
    }
};

class ImageProxy : public IImage{
    RealImage *realImage;
    string filename;
    public:
    ImageProxy(string file){
        this->filename=file;
    }
    void display() override{
        if(!realImage)realImage=new RealImage(filename);
        realImage->display();
    }
};

int main(){
    IImage* image1=new ImageProxy("sample.jpeg");
    image1->display();
}