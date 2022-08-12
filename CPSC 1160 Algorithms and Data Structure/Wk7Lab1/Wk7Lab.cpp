#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main(){
    DynamicArray v = DynamicArray(3);
    DynamicArray* k = new DynamicArray(5);
    DynamicArray *p = new DynamicArray(5, 1, 10);
    v.Show();

    k->Show();
    p->Show();


    return 0;
}