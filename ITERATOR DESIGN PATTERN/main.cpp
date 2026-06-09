#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Iterator{
    public:
    virtual bool hasNext()=0;
    virtual T next()=0;
};

template<typename T>
class Iterable{
    public:
    virtual Iterator<T>*getIterator()=0;
};

class LinkedList : public Iterable<int>{
    public:
    int data;
    LinkedList *next;
    LinkedList(int value){
        this->data=value;
        next=NULL;
    }
    Iterator<int>* getIterator() override;
};

class BinaryTree : public Iterable<int>{
    public:
    int data;
    BinaryTree* left;
    BinaryTree *right;
    BinaryTree(int value){
        this->data=value;
        left=NULL;
        right=NULL;
    }
    Iterator<int>*getIterator() override;
};

class Song{
    public:
    string title;
    string artist;
    Song(const string &t,const string &a){
        this->title=t;
        this->artist=a;
    }
};

class Playlist : public Iterable<Song>{
    public:
    vector<Song>songs;
    void addSong(const Song&s){
        songs.push_back(s);
    }
    Iterator<Song>*getIterator() override;
};

class LinkedListIterator : public Iterator<int>{
    private:
    LinkedList *curr;
    public:
    LinkedListIterator(LinkedList *head){
        this->curr=head;
    }
    bool hasNext() override{
        return curr!=NULL;
    }
    int next() override{
        int val=curr->data;
        curr=curr->next;
        return val;
    }
};

class BinaryTreeInorderIterator : public Iterator<int>{
    private:
    stack<BinaryTree*>stk;
    BinaryTree* curr;
    void pushLeft(BinaryTree* node){
        while(node){
            stk.push(node);
            node=node->left;
        }
    }
    public:
    BinaryTreeInorderIterator(BinaryTree* root){
        curr=root;
        pushLeft(curr);
    }
    bool hasNext()override{
        return !stk.empty();
    }
    int next() override{
        BinaryTree* node=stk.top();
        stk.pop();
        int val=node->data;
        if(node->right)pushLeft(node->right);
        return val;
    }
};

class PLayListIterator : public Iterator<Song>{
    private:
    vector<Song>vec;
    size_t index;
    public:
    PLayListIterator(vector<Song>v){
        this->vec=v;
        index=0;
    }
    bool hasNext() override{
        return index<vec.size();
    }
    Song next() override{
        return vec[index++];
    }
};

Iterator<int>* LinkedList::getIterator(){
    return new LinkedListIterator(this);
}
Iterator<int>* BinaryTree::getIterator(){
    return new BinaryTreeInorderIterator(this);
}
Iterator<Song>*Playlist::getIterator(){
    return new PLayListIterator(songs);
}

int main(){
    LinkedList *list=new LinkedList(1);
    list->next=new LinkedList(2);
    list->next->next=new LinkedList(3);

    Iterator<int>* iterator1=list->getIterator();

    cout<<"Linked List Contents: ";
    while(iterator1->hasNext()){
        cout<<iterator1->next()<<" ";
    }
    cout<<endl;

    BinaryTree* root=new BinaryTree(2);
    root->left=new BinaryTree(1);
    root->right=new BinaryTree(3);
    Iterator<int>* iterator2=root->getIterator();
    cout<<"BinaryTree inorder : ";
    while(iterator2->hasNext()){
        cout<<iterator2->next()<<" ";
    }
    cout<<endl;

    Playlist playlist;
    playlist.addSong(Song("one","polty"));
    playlist.addSong(Song("two","polty1"));

    Iterator<Song>*iterator3=playlist.getIterator();
    cout<<"Playlist songs: "<<endl;
    while(iterator3->hasNext()){
        Song a=iterator3->next();
        cout<<" "<<a.title<<" by "<<a.artist<<endl;
    }

    delete list->next->next;
    delete list->next;
    delete list;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}