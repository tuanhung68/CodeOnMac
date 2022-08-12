#include <iostream>
using namespace std;

//Pass by value
void passByValue(int x, int y){
    int z = x;
    x = y;
    y = z;
}
// pas by reference
void passByReference(int &x, int &y){// x and y: new names of a and b
    int z = x;
    x = y;
    y = z;
}
// pass by pointer or call by address
void passByPointer(int *x, int *y){
    int z = *x;
    *x = *y;
    *y = z;
}

int main(){
    
    // passing by value
    // they are distinct, two different variables, 
    int a = 5;
    int b = 6;
    cout << "Before swapping " << endl ;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    // call function
    //passByValue(a, b);// a and b are copied in the arguments
    //passByReference(a, b);
    passByPointer(&a, &b);// passing by address
    cout << "After swapping " << endl ;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    return 0;
}