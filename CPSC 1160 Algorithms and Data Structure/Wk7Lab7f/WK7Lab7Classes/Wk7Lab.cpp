#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main(){
    
    // DynamicArray k(10,0,9);

    // k.Show();
    DynamicArray* k = new DynamicArray(10,0,9);
    int newItemsSize = 5;
    int *newItems;
    cout << "The original array with size " << k->size<< " is: "  << endl;
    k->Show();
    cout << "The index is: ";
    int index;
    cin >> index;
    k->Add(20, index);
    //k->AddFirst(10);
    //k->AddLast(12);
    //k->Add(index, newItems, newItemsSize);
    //k->Remove(index);
    //k->RemoveFirst(); 
    //k->RemoveLast();
    
    // cout << "The second index is: ";
    // int index2;
    // cin >> index2
    // cout << endl;
    
    //k->Remove(index, index2);
    //k->Sort(index, index2);
    cout << "The new array with size " << k->size << " is: " << endl;
    k->Show();
    if(k){
        delete k;
    }
    return 0;
}