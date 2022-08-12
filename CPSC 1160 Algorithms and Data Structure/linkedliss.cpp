#include <iostream>

using namespace std;

class Node{
public:
    int value;
    // a pointer to a next Node;
    Node *next;
    Node(){
        value = 0;
        next = nullptr;
    }
    Node (int value){
        this->value = value;
        this->next = nullptr;
    }
    ~Node(){
        delete next;
    }
};
void PrintList(Node *head){
    Node *temp = head;
    // while temp is not nullptr, print the value of temp
    while(temp != nullptr){
        cout << temp->value << endl;
        temp = temp->next;
    }
}
void InsertAtTheFront(Node**head, int newValue){
    // Prepare a newNode
    // Put it in front of current head
    // Move head of the list to point to the newNode
    Node *newNode = new Node(newValue);
    newNode->next = *head;
    *head = newNode;
    

}
struct N{
    int value;
    N *next;
    N(int value){
        this->value = value;
        this->next = nullptr;
    }
};

int main(){
// {
//     Node *head = new Node();
//     Node *second = new Node();
//     Node *third = new Node();
//     head->value = 1;
//     head->next = second;
//     second->value = 2;
//     second->next = third;
//     third->value = 3;
//     third->next = nullptr;
//     InsertAtTheFront(&head, -1);
//     PrintList(head);
//     cout << head << endl;
//     cout << &head << endl;
    cout << "Object1: " << endl;
    N *head = new N(1);
    N *second = new N(2);
    N *third = second;
    head->next = second;
    cout << "Address of head: " << head << endl;
    cout << "Address of head->next: " << head->next << endl;
    cout << "Value: " << head->value << endl;
    cout << "Object2: " << endl;
    cout << "Address: " << second << endl;
    cout << "Address:: " << second->next << endl;
    second->next = third;
    cout << "Address: " << second->next << endl;
    cout << "Object3: " << endl;
    cout << "Address: " << third << endl;
    cout << "Address:: " << third->next << endl;



      

   
   
    
    return 0;
}