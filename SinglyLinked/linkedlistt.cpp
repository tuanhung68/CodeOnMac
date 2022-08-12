#include <iostream>
#include "Node.h"
#include <climits>
using namespace std;
class LinkedList{
public:
    Node *head;
    Node *tail;
    LinkedList(){
        // empty linked list
        head = tail = nullptr;
    }
    bool IsEmpty(){
        // returns true if linked list is empty
        // otherwise return false.
        return head == nullptr;
    }
    void AddLast(int itemValue){
        // Add a new node to the end of the linked list
        // create a new node
        Node *newNode = new Node(itemValue);
        if(IsEmpty()){
            head = tail = newNode;
        }
        else{
            Node *lastNode = head;
            // find the last node
            // stop when temp->next is nullptr, which is the last node
            while(lastNode->next != nullptr){
                lastNode = lastNode->next;
            }
            lastNode->next = newNode; 
        }
    }
    void AddLast11(int itemValue){
        Node *newNode = new Node(itemValue);
        if(IsEmpty()){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        }
    }
    void Show(){
        Node *temp = head;
        while(temp != nullptr){
            cout << temp->value << " -> ";
            temp = temp->next;
        }
    }
    int Length(){
        int count = 0;
        Node *current = head;
        while(current != nullptr){
            count++;
            current = current->next;
        }
        return count;
    }
    int FindMax(){
        // set max to INT_MIN
        int max = INT_MIN;
        Node *temp = head;
        while(temp != nullptr){
            if(temp->value > max){
                max = temp->value;
            }
            temp = temp->next;
        
        }
        return max;
    }
    int FindMin(){
        // set max to INT_MIN
        int min = INT_Max;
        Node *temp = head;
        while(temp != nullptr){
            if(temp->value < min){
                min = temp->value;
            }
            temp = temp->next;
        
        }
        return min;
    }

    void AddFirst(int item){
        Node *newNode = new Node(item);
        if(IsEmpty()){
            head = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }
    //return the number of nodes containing odd values
    int CountOdd(){
        int count = 0;
        Node *temp = head;
        while(temp != nullptr){
            if(temp->value % 2 != 0){
                count++;
            }
            temp = temp->next;
        }
        return count;
    }
    // return the difference between the highest and lowest values
    int MaxDiff(){
        return FindMax() - FindMin();
    }
    // removes the first node in the linked list
    // and returns the value inside that Node
    int RemoveFirst(){
        if(IsEmpty()){
            cout << "Nothing to remove returning 0 as a dummy value\n";
            return 0;
        }
        else{
            if(head == tail && head != nullptr){
                int val = head->value;
                delete head;
                head = tail = nullptr;
                return val;
            }

            Node *toRemove = head;
            int val = toRemove->value;
            head = head->next;
            // delete the node by setting its next to nullptr
            toRemove->next = nullptr;
            delete toRemove;
            return val;
        }
    }
    ~LinkedList(){
        delete head;
    }
};

int main(){
    LinkedList ll;
    ll.AddLast(123);
    ll.AddLast(4);
    ll.AddLast(3333);
    ll.Show();
    cout << endl;
    int len = ll.Length();
    cout << "The length of the linked list: " << len << endl;
    int max = ll.FindMax();
    cout << "The maximum value in the linked list: " << max << endl;

}