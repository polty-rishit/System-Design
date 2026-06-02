#include<bits/stdc++.h>
using namespace std;

class DocumentElement{
    public:
    virtual string render()=0;
};

class TextElement : public DocumentElement{
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

class ImageElement : public DocumentElement{
    public:
    string imagePath;
    public:
    ImageElement(string imagePath){
        this->imagePath=imagePath;
    }
    string render(){
        return "[Image: "+imagePath+"]";
    }
};

class NewLineElement : public DocumentElement{
   public:
   string render(){
    return "\n";
   }
};

class TabSpaceElment : public DocumentElement{
    public:
    string render(){
        return "\t";
    }
};

class Document{
    private:
    vector<DocumentElement*>elements;
    public:
    void addElement(DocumentElement* e){
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

class Persistance{
    public:
    virtual void save(string data)=0;
};

class FileStorage : public Persistance{
   public:
   void save(string data){
    ofstream outFile("document.txt");
    if(outFile){
        outFile<<data;
        outFile.close();
        cout<<"Document saved to Document.txt"<<endl;
    }else{
        cout<<"Error: Unable to open file for Writing."<<endl;
    }
   }
};

class DbStorage : public Persistance{
   public:
   void save(string data){
    cout<<"FILE SAVED TO DB"<<endl;
   }
};

class DocumentEditor{
    private:
   Document* document;
   Persistance * storage;
   string renderDocument;

   public:
   DocumentEditor(Document* document,Persistance *storage){
    this->document=document;
    this->storage=storage;
   }

   void addText(string text){
    document->addElement(new TextElement(text));
   }
   void addImage(string imagePath){
    document->addElement(new ImageElement(imagePath));
   }
   void addNewLine(){
    document->addElement(new NewLineElement());
   }
   void addTabSpace(){
    document->addElement(new TabSpaceElment());
   }
   string renderFinalDocument(){
    if(renderDocument.empty()){
        renderDocument=document->render();
    }
    return renderDocument;
   }
   void saveDocument(){
    storage->save(renderFinalDocument());
   }
};


int main(){
    Document* document = new Document();
    Persistance* persistence = new FileStorage();

    DocumentEditor* editor = new DocumentEditor(document, persistence);

    // Simulate a client using the editor with common text formatting features.
    editor->addText("Hello, world!");
    editor->addNewLine();
    editor->addText("This is a real-world document editor example.");
    editor->addNewLine();
    editor->addTabSpace();
    editor->addText("Indented text after a tab space.");
    editor->addNewLine();
    editor->addImage("picture.jpg");

    // Render and display the final document.
    cout << editor->renderFinalDocument() << endl;

    editor->saveDocument();

    return 0;

}