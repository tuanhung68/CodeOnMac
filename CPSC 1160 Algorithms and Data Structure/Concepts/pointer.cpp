#include <iostream>
using namespace std;
int main(){
    int a = 100;
    int *b = &a;
    // Pointers are the variables whose value are the address of the pointing variable

    // Value of B is the address of a
    cout << "Address is " << b << endl;
    // Toan tu lay gia tri. 
    cout << "Value is " << *b << endl;
    return 0;
}