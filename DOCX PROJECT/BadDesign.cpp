#include<bits/stdc++.h>
using namespace std;

class DocumentEditor{
    private:
    vector<string>documentElement;
    string Document;

    public:
    void addText(string text){
        documentElement.push_back(text);
    }

    void addImage(string imagePath){
        documentElement.push_back(imagePath);
    }

    string renderDocument(){
        if(Document.empty()){
            string res;
            for(auto i:documentElement){
                if(i.size()>4 && (i.substr(i.size()-4)==".jpg" || i.substr(i.size()-4)==".png"))res+="[Image: "+i+"]"+"\n";
                else res+=i+"\n";
            }
            Document=res;
        }
        return Document;
    }

    void saveToFile(){
        ofstream file("document.txt");
        if(file.is_open()){
            file<<renderDocument();
            file.close();
            cout<<"Document saved to document.txt"<<endl;
        }else{
            cout<<"Error :Unable to open file for Writing."<<endl;
        }
    }
};

int main(){
    DocumentEditor one;
    one.addText("Hello World!");
    one.addImage("Picture.png");
    one.addText("This is a document editor.");
    cout<<one.renderDocument()<<endl;
    one.saveToFile();
    return 0;
}