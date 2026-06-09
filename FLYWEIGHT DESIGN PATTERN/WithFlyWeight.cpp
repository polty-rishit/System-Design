#include<bits/stdc++.h>
using namespace std;

class AsteroidFlywight{
    private:
    int length;
    int width;
    int weight;
    string color;
    string texture;
    string material;

    public:
    AsteroidFlywight(int l,int w,int wt,string col,string tex,string mat){
        this->length=l;
        this->width=w;
        this->weight=wt;
        this->color=col;
        this->texture=tex;
        this->material=mat;
    }
    void render(int posx,int posy,int velocityX,int velocityY){
        cout << "Rendering " << color <<", " << texture << ", " << material 
            <<" asteroid at (" << posx << "," << posy 
            << ") Size: " << length << "x" << width
            << " Velocity: (" << velocityX << ", " 
            << velocityY << ")" << endl;
    }
    static size_t getMemory(){
        return sizeof(int)*3+sizeof(string)*3+32*3;
    }
};

class AsteroidFactory{
    private:
    static unordered_map<string,AsteroidFlywight*>hsh;
    public:
    static AsteroidFlywight* getAsteroid(int length,int width,int weight,string color,string texture,string material){
        string key = to_string(length) + "_" + to_string(width) + "_" + to_string(weight) + 
                    "_" + color + "_" + texture + "_" + material;
                    if(hsh.find(key)==hsh.end()){
        hsh[key]=new AsteroidFlywight(length,width,weight,color,texture,material);
    }
    return hsh[key];
    }
    static int getFlyweightCount(){
        return hsh.size();
    }
    static size_t getTotalMemory(){
        return hsh.size()*AsteroidFlywight::getMemory();
    }
    static void cleanup(){
        hsh.clear();
    }
};

unordered_map<string,AsteroidFlywight*>AsteroidFactory::hsh;

class AsteroidContext{
    private:
    AsteroidFlywight *flyweight;
    int posx,posy;
    int velx,vely;
    public:
    AsteroidContext(AsteroidFlywight* fw,int posx,int posy,int velx,int vely){
        this->flyweight=fw;
        this->posx=posx;
        this->posy=posy;
        this->velx=velx;
        this->vely=vely;
    }
    void render(){
        flyweight->render(posx,posy,velx,vely);
    }
    static size_t getMemory(){
        return sizeof(AsteroidFlywight*)+sizeof(int)*4;
    }
};

class SpaceGame{
    private:
    vector<AsteroidContext*>as;
    public:
    void spawn(int count){
        vector<string>col={"Red", "Blue", "Gray"};
        vector<string> textures = {"Rocky", "Metallic", "Icy"};
        vector<string> materials = {"Iron", "Stone", "Ice"};
        int sizes[]={25,35,45};
        for(int i=0;i<count;i++){
            int type=i%3;
            AsteroidFlywight*flyweight=AsteroidFactory::getAsteroid(
                sizes[type],sizes[type],sizes[type]*10,
                col[type],textures[type],materials[type]
            );
            as.push_back(new AsteroidContext(
                flyweight,100+i*50,200+i*30,1,2
            ));
        }
        cout << "Created " << as.size() << " asteroid contexts" << endl;
        cout << "Total flyweight objects: " << AsteroidFactory::getFlyweightCount() << endl;
    }
    void renderAll() {
        cout << "\n--- Rendering first 5 asteroids ---" << endl;
        for (int i = 0; i < min(5, (int)as.size()); i++) {
            as[i]->render();
        }
    }
    size_t calculateMemoryUsage() {
        size_t contextMemory = as.size() * AsteroidContext::getMemory();
        size_t flyweightMemory = AsteroidFactory::getTotalMemory();
        return contextMemory + flyweightMemory;
    }
    
    int getAsteroidCount() { 
        return as.size();
    }
};

int main(){
    const int ASTEROID_COUNT=1000000;
    cout << "\nTESTING WITH FLYWEIGHT PATTERN" << endl;
    SpaceGame* game = new SpaceGame();

    game->spawn(ASTEROID_COUNT);

    // Show first 5 asteroids to see the pattern
    game->renderAll();

    // Calculate and display memory usage
    size_t totalMemory = game->calculateMemoryUsage();

    cout << "\n=== MEMORY USAGE ===" << endl;
    cout << "Total asteroids: " << ASTEROID_COUNT << endl;                           
    cout << "Memory per asteroid: " << AsteroidContext::getMemory() << " bytes" << endl; 
    cout << "Total memory used: " << totalMemory << " bytes" << endl;           
    cout << "Memory in MB: " << totalMemory / (1024.0 * 1024.0) << " MB" << endl;     
    
    return 0;
}