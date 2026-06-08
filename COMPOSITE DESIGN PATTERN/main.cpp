#include<bits/stdc++.h>
using namespace std;

class FileSystemItem{
    public:
    virtual ~FileSystemItem(){}
    virtual void ls(int indent=0)=0;
    virtual void openAll(int indent=0)=0;
    virtual int getSize()=0;
    virtual FileSystemItem* cd(const string &name)=0;
    virtual string getName()=0;
    virtual bool isFolder()=0;
};

class File: public FileSystemItem{
    string name;
    int size;
    public:
    File(const string&n,int s){
        this->name=n;
        this->size=s;
    }
    void ls(int indent=0) override{
        cout<<string(indent,' ')<<name<<endl;
    }
    void openAll(int indent=0)override{
        cout<<string(indent,' ')<<name<<endl;
    }
    int getSize()override{
        return size;
    }
    FileSystemItem *cd(const string&)override{
        return nullptr;
    }
    string getName() override{
        return name;
    }
    bool isFolder() override{
        return false;
    }
};

class Folder : public FileSystemItem{
    public:
    string name;
    vector<FileSystemItem*>child;
    public:
    Folder(const string &n){
        this->name=n;
    }
    ~Folder(){
        for (auto c:child)delete c;
    }

    void add(FileSystemItem *item){
        child.push_back(item);
    }

    void ls(int indent=0) override{
        for(auto c:child){
            if(c->isFolder())cout<<string(indent,' ')<<"+"<<c->getName()<<endl;
            else cout<<string(indent,' ')<<c->getName()<<endl;
        }
    }
    void openAll(int indent=0)override{
        cout<<string(indent,' ')<<"+"<<name<<endl;
        for(auto c:child){
            c->openAll(indent+4);
        }
    }
    int getSize()override{
        int t=0;
        for(auto i:child){
            t+=i->getSize();
        }
        return t;
    }
    FileSystemItem* cd(const string& target)override{
        for(auto i:child){
            if(i->isFolder() && i->getName()==target)return i;
        }
        return NULL;
    }
    string getName() override{
        return name;
    }
    bool isFolder() override{
        return 1;
    }
};

int main(){
    Folder *root=new Folder("root");
    // File *file1=new File("file1.txt",1);
    // File *file2=new File("file2.txt",1);
    // root->add(file1);
    // root->add(file2);
    root->add(new File("file1.txt",1));
    root->add(new File("file2.txt", 1));

    Folder* docs = new Folder("docs");
    docs->add(new File("resume.pdf", 1));
    docs->add(new File("notes.txt", 1));
    root->add(docs);

    Folder* images = new Folder("images");
    images->add(new File("photo.jpg", 1));
    root->add(images);

    // root->ls();

    // docs->ls();

    root->openAll();

    // FileSystemItem* cwd = root->cd("docs");
    // if (cwd != nullptr) {
    //     cwd->ls();
    // } else {
    //     cout << "\n Could not cd into docs \n";
    // }

    //  cout << root->getSize();

    // // Cleanup
    // delete root;
    return 0;
}