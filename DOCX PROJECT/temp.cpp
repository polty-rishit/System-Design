#include<bits/stdc++.h>
using namespace std;

class DocumentElement{
    public:
    virtual string render();
};

class TextElement: public DocumentElement{
     private:
     string text;
     public:
     TextElement(string text){
        this->text=text;
     }
     string render(){
        return text;
     }
};

class ImageElement: public DocumentElement{
     private :
     string imagePath;
     public:
     ImageElement(string imagePath){
       this->imagePath=imagePath;
     }
     string render(){
        return "[Image: "+imagePath+"]";
     }
};

class NewLineElement: public DocumentElement{
    public:
    string render(){
        return "\n";
    }
};

class TabSpaceElement:public DocumentElement{
    public :
    string render(){
        return "\t";
    }
};

class Document{
    private:
    vector<DocumentElement*>elements;
    public:
    void addElement(DocumentElement *e){
        elements.push_back(e);
    }
    string render(){
        string res;
        for(auto i:elements){
            res+=i->render();
        }
        return res;
    }
};

class Presistance{
    public:
    virtual void save(string data)=0;
};

class FileStorage : public Presistance{
     public :
     void save(string data){
        ofstream outFile("document.txt");
        if(outFile){
            outFile<<data;
            outFile.close();
            cout<<"Document saved to Document.txt"<<endl;
        }else cout<<"Error : Unable to open file for writitng"<<endl;
     }
};

class DbStorage : public Presistance{
     public:
     void save(string data){
        cout<<"File has been stored to DB";
     }
};

class DocumentEditor{
     private:
     Document *document;
     Presistance *storage;
     string renderDocument;

     public:
     DocumentEditor(Document *document,Presistance *storage){
         this->document=document;
         this->storage=storage;
     }
     void addText(string text){
        document->addElement(new TextElement(text));
     }
     void addImage(string text){
        document->addElement(new ImageElement(text));
     }
     void addNewLine(){
        document->addElement(new NewLineElement());
     }
     void addTabSpace(){
        document->addElement(new TabSpaceElement());
     }
     string renderFinalDocument(){
        if(renderDocument.empty()){
            renderDocument=document->render();
        }return renderDocument;
     }
     void saveDocument(){
        storage->save(renderFinalDocument());
     }
};