#include<bits/stdc++.h>
using namespace std;

class TextFile;
class ImageFile;
class VideoFile;

class FileSystemVisitor{
    public:
    virtual ~FileSystemVisitor() =default;
    virtual void visit(TextFile* file)=0;
    virtual void visit(ImageFile *file)=0;
    virtual void visit(VideoFile* file)=0;
};

class FileSystemIem{
    protected:
    string name;
    public:
    FileSystemIem(const string &name){
        this->name=name;
    }
    virtual ~FileSystemIem()=default;
    string getName() const{return name;}
    virtual void accept(FileSystemVisitor *vis)=0;
};

class TextFile : public FileSystemIem{
    private:
    string content;
    public:
    TextFile(const string &fileName,const string &fileContent):FileSystemIem(fileName){
        this->content=fileContent;
    }
    string getContent() const{
        return content;
    }
    void accept(FileSystemVisitor *visitor) override{
        visitor->visit(this);
    }
};

class ImageFile : public FileSystemIem{
    public:
    ImageFile(string fileName) : FileSystemIem(fileName){}
    void accept(FileSystemVisitor *visitor) override{
        visitor->visit(this);
    }
};

class VideoFile : public FileSystemIem{
    public:
    VideoFile(const string &fileName):FileSystemIem(fileName){}
    void accept(FileSystemVisitor* visitor) override{
        visitor->visit(this);
    }
};

class SizeCalculation : public FileSystemVisitor{
    public:
    void visit(TextFile* file) override{
        cout<<"CALCULATING SIZE FOR TEXT FILE: "<<file->getName()<<endl;
    }
    void visit(ImageFile* file) override{
        cout<<"CALCULATING SIZE FOR IMAGEFILE : "<<file->getName()<<endl;
    }
    void visit(VideoFile* file) override{
        cout<<"CALCULATING SIZE FOR VIDEO FILE: "<<file->getName()<<endl;
    }
};

class CompressionVisitor : public FileSystemVisitor{
    public:
    void visit(TextFile* file) override{
        cout<<"COMPRESSING THE TEXT FILE: "<<file->getName()<<endl;
    }
    void visit(ImageFile* file) override{
        cout<<"COMPRESSING IMAGE FILE: "<<file->getName()<<endl;
    }
    void visit(VideoFile* file) override{
        cout<<"COMPRESSING VIDEO FILE: "<<file->getName()<<endl;
    }
};

class VirusScanner : public FileSystemVisitor{
    public:
    void visit(TextFile* file) override{
        cout<<"SCANNING THE TEXT FILE : "<<file->getName()<<endl;
    }
    void visit(ImageFile* file) override{
        cout<<"SCANNING THE IMAGE FILE: "<<file->getName()<<endl;
    }
    void visit(VideoFile* file) override{
        cout<<"SCANNING THE VIDEO FILE: "<<file->getName() <<endl;
    }
};


int main(){
    FileSystemIem *item=new ImageFile("sample.png");
    item->accept(new SizeCalculation());
    item->accept(new CompressionVisitor());
    item->accept(new VirusScanner());

    FileSystemIem* visit=new VideoFile("test.mp4");
    visit->accept(new CompressionVisitor());
    return 0;
}