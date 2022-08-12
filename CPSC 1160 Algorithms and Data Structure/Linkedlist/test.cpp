#include <iostream>
#include "LinkedList.h"
#include <climits>
using namespace std;

int main(){
    
    LinkedList ll;
    // Add four elements to the linked list
    ll.AddLast(123);
    ll.AddLast(4);
    ll.AddLast(56);
    ll.AddLast(789);
    // Print the linked list
    ll.Show();

    // Reverse the linked list
    ll.Reverse();
    cout << "The linked list after reversing: ";
    ll.Show();
    
    // e) find Node at a given index
    Node *a = ll.Find(2);
    // Print Node
    cout << "The value of a is: " << a->value << endl;;
    cout << "The address of the next Node is: " << a->next << endl;; 
    // f) Insert a Node after a given index
    ll.InsertAfter(0, 12);
    ll.Show();
    ll.InsertAfter(1, 100);
    ll.Show();

}

