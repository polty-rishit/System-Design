#include<bits/stdc++.h>
using namespace std;

class TwoDimensionalShape{
    public:
    virtual double area()=0;
};

class ThreeDimensionalShape{
    public:
    virtual double area()=0;
    virtual double volume()=0;
};

class Square : public TwoDimensionalShape{
    private:
    double side;
    public:
    Square(double side){
        this->side=side;
    }
    double area(){
        return side * side;
    }
};

class Rectangle : public TwoDimensionalShape{
    private:
    double length;
    double width;
    public:
    Rectangle(double length,double width){
        this->length=length;
        this->width=width;
    }
    double area(){
        return length*width;
    }
};

class Cube : public ThreeDimensionalShape{
    private:
    double side;
    public:
    Cube(double side){
        this->side=side;
    }
    double area(){
        return 6*side*side;
    }
    double volume(){
        return side*side*side;
    }
};

int main(){
    TwoDimensionalShape * square=new Square(5);
    TwoDimensionalShape * rectangle =new Rectangle(4,6);
    ThreeDimensionalShape *cube=new Cube(3);

    cout<<"Square area: "<<square->area()<<endl;
    cout<<"Rectangle area: "<<rectangle->area()<<endl;
    cout<<"Cube Area: "<<cube->area()<<endl;
    cout<<"Cube Volume: "<<cube->volume()<<endl;
}