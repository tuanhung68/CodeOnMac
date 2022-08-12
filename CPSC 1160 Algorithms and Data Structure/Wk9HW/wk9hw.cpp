#include <iostream>
#include <string>
#include <ctype.h>
#include <cmath>
using namespace std;

struct Product{
public:
    string name;
    double price;
    int quantity;
    
    string ValidName(){
        do {
            cout << "Enter product name: ";
            getline(cin, name);
        }
        // if it is an empty string, ask again
        while(name == "");
        return name;
    }
    double ValidPrice(){
        do {
            cout << "Enter product price: ";
            cin >> price;
            price = round(price * 100.0)/100.0;

        }
        while(price < 0);
        return price;
    }
    int ValidQuantity(){
        do {
            cout << "Enter product quantity: ";
            cin >> quantity;
        }
        while(quantity < 0);
        return quantity;
    }


};
class Store{
private:
    int n;
    Product *products;
public:
    Store(){
        n = 0;
        products = nullptr;
    }
    Store(int p){
        if(p < 0){
            n = 0;
            products = nullptr;
        }
        n = p;
        products = new Product[n];
        for(int i = 0; i < n; i++){
            products[i].name = products[i].ValidName();
            products[i].price = products[i].ValidPrice();
            products[i].quantity = products[i].ValidQuantity();
        }
    }
    // add a copy constructor that creates a deep copy of the store
    Store(const Store& copyFrom){
        // allocate new products array so that they have different memory addresses
        products = new Product[n];
        for(int i = 0; i < n; i++){
            products[i].name = copyFrom.products[i].name;
            products[i].price = copyFrom.products[i].price;
            products[i].quantity = copyFrom.products[i].quantity;
        }
    }
    ~Store(){
        cout << "Destructor called" << endl;
        if(products){
            delete[] products;
            products = nullptr;
        }
    }
    /**
     * @brief Set the Products object
     * 
     * @param index : int the index of the product to set
     * @param p : Product the product to set
     */
    void SetProducts(int index, Product p){
        if(index < 0 || index >= n){
            cout << "Invalid index" << endl;
            return;
        }
        cout << "Setting product " << index << endl;
        p.name = p.ValidName();
        p.price = p.ValidPrice();
        p.quantity = p.ValidQuantity();
        products[index] = p;
    }
    /**
     * @brief Get the Product object
     * 
     * @param i : int the index of the product to get
     * @return Product 
     */
    Product getProduct(int i){
        return products[i];
    }
    /**
     * @brief overload the = operator
     * 
     * @param right : const Store& the right hand side of the operator
     * @return Store& 
     */
    Store& operator = (const Store& right){ 
        n = right.n;
        products = new Product[n];
        for(int i = 0; i < n; i++){
            products[i].name = right.products[i].name;
            products[i].price = right.products[i].price;
            products[i].quantity = right.products[i].quantity;
        
        }
        return *this;
    }
    
    Store& operator + (const Store& right){
        int index = n;
        Store *newStore = new Store;
        newStore->n = n + right.n;
        newStore->products = new Product[newStore->n];
        for(int i = 0; i < n; i++){
            newStore->products[i] = this->products[i];
        }
        for(int i = 0; i < right.n; i++){
            for(int j = 0; j < n; j++){
                if(right.products[i].name ==  this->products[j].name && 
                right.products[i].price == this->products[j].price){
                    newStore->products[j].quantity += right.products[i].quantity;
                    newStore->n -= 1;
                    break;
                }
                else{
                    newStore->products[index] = right.products[i];
                    index += 1;
                }
            }
        }
        
        return *newStore;          
    }
    /**
     * @brief overload the + operator
     * 
     * @param right : int the right hand side of the operator
     * @return Store& the new store
     */
    Store& operator + (int right){
        if(right < 0){
            cout << "Invalid quantity" << endl;
            return *this;
        }
        
        Store *rightStore;
        rightStore->n = right;
        rightStore->products = new Product[right];
        for(int i = 0; i < right; i++){
            rightStore->products[i].name = products[i].ValidName();
            rightStore->products[i].price = products[i].ValidPrice();
            rightStore->products[i].quantity = products[i].ValidQuantity();
        }
        int index = n;
        Store *newStore = new Store;
        newStore->n = n + right;
        newStore->products = new Product[newStore->n];


        for(int i = 0; i < n; i++){
            newStore->products[i] = this->products[i];
        }
        for(int i = 0; i < right; i++){
            newStore->products[index] = this->products[i];
            index += 1;
        }
        return *newStore;
    }
    /**
     * @brief overload the - operator
     * 
     * @param right : const Store& the right hand side of the operator
     * @return Store& the new store
     */
    Store& operator - (const Store& right){
        Store *newStore = new Store;
        newStore->n = n + right.n;
        newStore->products = new Product[newStore->n];
        Store *leftStore = new Store;
        leftStore->n = n;
        leftStore->products = new Product[leftStore->n];
        Store *rightStore = new Store;
        rightStore->n = right.n;
        rightStore->products = new Product[rightStore->n];
        for(int i = 0; i < right.n; i++){
            for(int j = 0; j < n; j++){
                if(right.products[i].name != this->products[j].name || 
                right.products[i].price != this->products[j].price){
                    rightStore->products[i] = right.products[i];
                    leftStore->products[i] = this->products[j];
                }
                else{
                    newStore->n -= 1;
                }
            }
        }
        for(int i = 0; i < n; i++){
            newStore->products[i] = leftStore->products[i];
        }
        for(int i = 0; i < right.n; i++){
            newStore->products[i + n] = rightStore->products[i];
        }
        if(leftStore){
            delete[] leftStore->products;
            leftStore->products = nullptr;
        }
        if(rightStore){
            delete[] rightStore->products;
            rightStore->products = nullptr;
        }
        return *newStore;          
    }

    
    // add an overloaded operator that prints the store
    friend ostream& operator << (ostream& COUT, const Store& store);
    friend void operator >> (istream& CIN, Store& store);
};
/**
 * @brief overload the << operator to print the store
 * 
 * @param COUT : ostream& the output stream
 * @param store : const Store& the store to print
 * @return ostream& 
 */
ostream& operator << (ostream& COUT, const Store& store){
    COUT << "Store contains " << store.n << " products" << endl;
    for(int i = 0; i < store.n; i++){
        COUT << "Name: " << store.products[i].name << endl;
        COUT << "Price: " << store.products[i].price << endl;
        COUT << "Quantity: " << store.products[i].quantity << endl;
        COUT << endl;
    }
    return COUT;
}
/**
 * @brief overload the >> operator to read the store
 * 
 * @param CIN : istream& the input stream
 * @param store : Store& the store to read
 */
void operator >> (istream& CIN, Store& store){
    int k;
    do{
        cout <<  "Please enter a non-zero integer: ";
        CIN >> k;
    }
    while(k <= 0);
    Product *tempProducts = new Product[store.n + k];
    for(int i = 0; i < store.n; i++){
        tempProducts[i].name = store.products[i].name;
        tempProducts[i].price = store.products[i].price;
        tempProducts[i].quantity = store.products[i].quantity;
    }
    for(int i = store.n; i < store.n + k; i++){
        tempProducts[i].name = tempProducts[i].ValidName();
        tempProducts[i].price = tempProducts[i].ValidPrice();
        tempProducts[i].quantity = tempProducts[i].ValidQuantity();
    }
    if(store.products){
        delete[] store.products;
        store.products = nullptr;
    }
    store.products = tempProducts;
    // update n by adding k to it
    store.n += k;

}




int main(){
    cout << "Store1: " << endl;
    Store s1(2);
    

    // Please uncomment to test and comment after testing

    //7a) =
    cout << "Store2: " << endl;
    Store s2;
    s2 = s1;
    cout << s2;
    // // Product p;
    // // s2.SetProducts(0, p);
    // // cout << s2;

    // 7b) <<
    
    // cout << s1;

    // 7c) >>
    // cin >> s1;
    // cout << s1;

    // 7d)e +, -
    // cout << "Store3: " << endl;
    // Store s3(2);
    // cout << "Store4: " << endl;
    // Store s4;
    // //s4 = s1 + s3;
    // int right = 2;
    // s4 = s1 + right;
    // s4 = s1 - s3;
    // s4 = s1 - right;
    // cout << s4; 


    
    

 

   

    return 0;
}