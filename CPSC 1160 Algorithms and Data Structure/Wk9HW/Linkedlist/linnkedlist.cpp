#include <iostream>
#include "Node.h"
using namespace std;

class LinkedList{
public:
    Node *head;// address of the first node
    LinkedList(){
        head = nullptr;
    }
    bool IsEmpty(){
        return head == nullptr;
    }

    void AddLast(int itemValue){
        // add an ew node to the end of the linked list
        // containing the value itemValue
        Node *newNode = new Node(itemValue);
        if(IsEmpty()){
            head = newNode;
        }
        else{
            Node *temp = head;
            while(temp->next != nullptr){
                cout << temp->value << endl;
                temp = temp->next;
            }
        }
    }
    void Show(){
        Node *temp = head;
        while(temp != nullptr){
            cout << temp->value << " ";
            temp = temp->next;
        }
    }
    
};

int main()
{
    Node a; // default constructor, head node in an linkedl ist
    Node b;
    Node c;
    a.next = &b; // a.next points to b
    b.next = &c; // b.next points to c
    Node *temp =&a; // temp is a pointer to a Node object

    while(temp != nullptr){
        temp->value += 10;
        temp = temp->next;
    }
    temp = &a;
    while(temp != nullptr){
        cout << temp->value << endl;
        temp = temp->next;
    }
    
     

     

    return 0;
}