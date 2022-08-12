#include <iostream>
#include "Node.h"
#include <climits>
using namespace std;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class LinkedList{
public:
    Node* head; // points to the first node. Allocates memory for the first node.
    Node* tail; // points to the last node. Allocates memory for the last node.

    LinkedList(){
        // empty linked list 
        cout << "constructor called\n";
        head = tail = nullptr;
    }
   
    

    bool IsEmpty(){
        // returns true if linked list is empty
        // false otherwise.
        return (head == nullptr);
    }

    void AddLast(int item){
        // adds a new node containing item
        // to the end of the linked list
        // create a pointer to the new node
        // newNode = an address of a new Node object
        Node* newNode = new Node(item);

        if(IsEmpty()){
            // adding the head node
            head = tail = newNode;
        }
        else{
            // add new node after the tail node
            tail->next = newNode;
            tail = newNode;
        }
    }

    void Show(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Length: returns number of nodes in a linked list
    int Length(){
        int count = 0;
        Node* current = head;
        while(current != nullptr){
            count++;
            current = current->next;
        }
        return count;
    }

    // FindMax: returns node containing the maximum value
    Node* FindMaxNode(){
        Node* current = head;
        Node* maxNode = head;
        while(current != nullptr){
            if(maxNode->value < current->value){
                maxNode = current;
            }
            current = current->next;
        }
        return maxNode;
    }
    int FindMax(){
        int maximum = INT_MIN;
        Node* current = head;
        while(current != nullptr){
            if(maximum < current->value){
                maximum = current->value;
            }
            current = current->next;
        }
        return maximum;
    }

    int FindMin(){
        int mini = INT_MAX;
        Node* current = head;
        while(current != nullptr){
            if(mini > current->value){
                mini = current->value;
            }
            current = current->next;
        }
        return mini;
    }

    // AddFirst(int x): adds a new node containing x
    // to the beginning of the  linked list
    void AddFirst(int item){
        Node* newNode = new Node(item);
        if(IsEmpty()){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    // return the number of nodes containing odd values
    int CountOdd(){
        int count = 0;
        Node* current = head;
        while(current != nullptr){
            if(current->value % 2 != 0){
                count++;
            }
            current = current->next;
        }
        return count;
    }

    // return the difference between the highest and lowest values
    int MaxDiff(){
        return FindMax() - FindMin();
    }

    // removes the first node in the linked list
    // and returns the value inside that node
    int RemoveFirst(){
        if(IsEmpty()){
            cout << "nothing to remove returning 0 as a dummy value\n";
            return 0;
        }
        else{
            if(head == tail && head != nullptr){
                int val = head->value;
                delete head;
                head = tail = nullptr;
                return val;
            }
            else{
                Node* toRemove = head;
                int val = toRemove->value;
                head = head->next;
                toRemove->next = nullptr;
                delete toRemove;
                return val;
            }
        }
    }

    // removes the last node in the linked list and returns its value
    int RemoveLast(){
        if(IsEmpty()){
            cout << "nothing to remove returning 0 as a dummy value\n";
            return 0;
        }
        else{
            if(head == tail && head != nullptr){
                int val = head->value;
                delete head;
                head = tail = nullptr;
                return val;
            }
            else{
                Node* beforeTail = head;
                while(beforeTail->next != tail){
                    beforeTail = beforeTail->next;
                }

                beforeTail->next = nullptr;
                int val = tail->value;
                delete tail;
                tail = beforeTail;
                return val;
            }
        }
    }

     // destructor for linked list, removes all nodes from the linked list.
    ~LinkedList(){
        cout << "destructor called\n";
        Node *current = head;
        Node *next = nullptr;
        while(current != nullptr){
            next = current->next;
            delete current;
            current = next;
        }
    }
    // create a deep copy of the linked list.
    LinkedList (const LinkedList& copyFrom){
        cout << "copy constructor called\n";
        head = tail = nullptr;
        Node* current = copyFrom.head;
        while(current != nullptr){
            AddLast(current->value);
            current = current->next;
        }
    }
    void operator = (const LinkedList& right){
        cout << "assignment operator called\n";
        Node *current = right.head;
        while(current != nullptr){
            AddLast(current->value);
            current = current->next;
        }
    }
    // reverses the linked list.
    void Reverse(){
        Node* current = head;
        Node* previous = nullptr;
        Node* next = nullptr;
        while(current != nullptr){
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        head = previous;
    }
    //
    int Get(int index){
        int len = Length();

        if(IsEmpty() || index < 0 || index >= Length()){
            cout << "Invalid index or empty list. Returning 0 as an arbitrary value\n";
            return 0;
        }

        int i = 0;
        Node* temp = head;
        while(i < index){
            temp = temp->next;
            i++;
        }
        return temp->value;
    }




};

#endif
