#include<bits/stdc++.h>
using namespace std;

class ModelTrainer{
    public:
    void trainModel(const string &path){
        loadData(path);
        preprocessData();
        train();
        evaluate();
        save();
    }
    protected:
    void loadData(const string&path){
        cout<<"[Common] Loading dataset from " << path << "\n";
    }
    virtual void preprocessData(){
        cout << "[Common] Splitting into train/test and normalizing\n";
    }
    virtual void train()=0;
    virtual void evaluate()=0;
    virtual void save(){
        cout<<"[Common] Saving model to disk as default format\n";
    }
};

class NeuralNetworkTrainer : public ModelTrainer{
    protected:
    void train()override{
        cout << "[NeuralNet] Training Neural Network for 100 epochs\n";
    }

    void evaluate() override{
        cout << "[NeuralNet] Evaluating accuracy and loss on validation set\n";
    }
    void save() override{
        cout << "[NeuralNet] Serializing network weights to .h5 file\n";
    }
};

class DecisionTreeTrainer : public ModelTrainer{
    protected:
    void train() override{
        cout << "[DecisionTree] Building decision tree with max_depth=5\n";
    }
    void evaluate() override{
        cout << "[DecisionTree] Computing classification report (precision/recall)\n";
    }
};

int main(){
    cout<<"---NEURAL NETWORK TRAINING---"<<endl;
    ModelTrainer *nn=new NeuralNetworkTrainer();
    nn->trainModel("one.csv");
    cout<<endl<<"---DECISION TREE TRAINING---"<<endl;
    ModelTrainer *dt=new DecisionTreeTrainer();
    dt->trainModel("two.csv");
}