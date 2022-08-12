#include <iostream>
#include "DynamicArray.h"
using namespace std;
int main(){

    DynamicArray v;
    DynamicArray *ptrD = new DynamicArray;
    cout << v.size << endl;
    cout << ptrD->size << endl;// pointer to an object using -> to access data members
    
    
    return 0;
 }