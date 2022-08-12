#include <iostream>
#include "LinkedList.h"
#include <climits>
using namespace std;

int main(){

    // LinkedList ll;
    // ll.AddLast(123);
    // ll.AddLast(4);
    // ll.AddLast(56);
    // ll.AddLast(789);
    // ll.Show();
    // cout << ll.Get(1) << endl;

    // LinkedList ll2(ll);
    // ll2.Show();
    // ll2.RemoveFirst();
    // ll.Show();
    // ll2.Show();
    // LinkedList ll3;
    // ll3 = ll2;
    // ll3.Show();
    // ll3.RemoveFirst();
    // ll3.Show();
    // ll2.Show();
    // ll2.Reverse();
    // ll2.Show();



    // Node* m = ll.FindMax();
    // if(m == nullptr){
    //     cout << "no maximum exists as list is empty\n";
    // }
    // else{
    //     cout << m->value << endl;
    // }

    // cout << ll.IsEmpty() << endl;


    // Node a(100);
    // Node b(200);
    // a.next = &b;
    // //int arr[2] = {100, 200};

    // // display contents of the linked list
    // Node* temp = &a;
    // //int i = 0;
    // while(temp != nullptr /*i != 2*/){
    //     cout << temp->value << endl;
    //     //cout << arr[i] << endl;
    //     temp = temp->next;
    //     //i++;
    // }
    // create a "2d array" using linkedlist class
    LinkedList *ll2D = new LinkedList[2];
    for(int i = 0; i < 2; i++){ 
        ll2D[i].AddLast(123);
        ll2D[i].AddLast(4);
        ll2D[i].AddLast(56);
    }
    for(int i = 0; i < 2; i++){
        ll2D[i].Show();
    }
    // free the memory 
    delete[] ll2D;
    ll2D = nullptr; 
    return 0;
    // create a 3x2x1 3D array using the LinkedList class
    // write a function that fills the array up with random integers between 0 and 9
    // compute columns sums, row sums
}

