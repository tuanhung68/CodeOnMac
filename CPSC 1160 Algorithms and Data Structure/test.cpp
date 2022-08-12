#include <iostream>
using namespace std;
int main(){
    // int x = 123;
    // int *p = &x;
    // cout << p << endl;// address
    // // 0x hexidecimal
    // cout << x << endl;
    // cout << *p << endl; // dereferencing a pointer

    int *p = new int;// like creating a point to an int type variable

    cout << p << endl;
    cout << &p << endl;
    cout << *p << endl;    
    delete p;
     p = nullptr;

    int size = 5;
    bool *a = new bool[size];

    cout << sizeof(int*) << endl;
    cout << sizeof(double*) << endl;
    cout << sizeof(a) << endl;
    cout << sizeof(a[0]) << endl;
    
    // int size = 5;
    // int *arr = new int[size];
    
    // int *backup = arr; 

    // cout << arr << endl;// address of arr[0]
    // cout << &arr[0] << endl;
    // // &x means address of x, assume x is some variables
    // for(int i = 0; i < size; i++){

    //     arr[i] = i;
    //     cout << "address: " << &arr[i] << " contains " << arr[i] << endl;
    
    // }
    // cout << "displaying contents:\n";
    // for(int i = 0; i < size; i++){
    //     //cout << arr[i] << endl;
    //     cout << "address: " << arr + i << "contains " << *(arr+i) << endl;
    //     // arr address
    //     // *arr dereference
    // }
    // cout << "Displaying contents by moving the starting adress:\n";
    // for(int i = 0; i < size; i++){
    //     //cout << arr[i] << endl;
    //     cout << "address: " << arr << "contains " << *arr << endl;
    //     arr++;// move to the next address
    // }
    // // delete[] arr;
    // // arr = nullptr;
    // delete[] backup;
    // backup = nullptr;
    // arr = nullptr;
    return 0;
}