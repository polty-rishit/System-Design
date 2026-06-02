#include<bits/stdc++.h>
using namespace std;

class Product{
   public:
   string name;
   double price;

   Product(string name,double price){
    this->name=name;
    this->price=price;
   }
};

class ShoppingCart{
      private:
      vector<Product*> products;
      public:
      void addProduct(Product *p){
        products.push_back(p);
      }
      const vector<Product*> &getProiducts(){
        return products;
      }

      double calculateTotal(){
        double ans=0;
        for(auto i:products){
            ans+=i->price;
        }
        return ans;
      }

      void printInvoice() {
        cout << "Shopping Cart Invoice:\n";
        for (auto p : products) {
            cout << p->name << " - Rs " << p->price << endl;
        }
        cout << "Total: Rs " << calculateTotal() << endl;
    }

    void saveToDatabase() {
        cout << "Saving shopping cart to database..." << endl;
    }
};

int main()
{
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 2000));

    cart->printInvoice();  
    cart->saveToDatabase();

    return 0;
}