#include "Node.h"
#include <iostream>

using namespace std;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
template<typename T>
class LinkedList{
public:
    Node<T>* head;
    Node<T>* tail;

    LinkedList(){
        // empty list
        head = nullptr;
        tail = nullptr;
    }

    LinkedList(int n){
        head = tail = nullptr;
        for(int i = 0; i < n; i++){
            AddNodeLast(i + 1);
        }
    }

    ~LinkedList(){

        Node<T>* temp;
        Node<T>* nextNode = nullptr;

        for(temp = head; temp != tail; temp = nextNode){
            
            if(temp != nullptr){
                nextNode = temp->next;
                delete temp;
            }
        }

        delete tail;
        head = tail = nullptr;
    }

    bool IsEmpty(){
        return tail == nullptr;
    }

    int Size() const{
        int count = 0;
        Node<T> *temp = tail;

        while(temp != nullptr){
            count++;
            temp = temp->prev;
        }

        return count;
    }

    void AddNodeLast(T value){
        // add a new node to the end to the end of the list
        if(IsEmpty()){
            head = new Node<T>(value);
            tail = head;
        }else{
            Node<T> *temp = new Node<T>(value);

            tail->next = temp;
            temp->prev = tail;

            tail = temp;
        }    
    }

    // void ShowReverse(){
    //     Node* temp = tail;

    //     while(temp != nullptr){
    //         cout << temp->element << " - ";
    //         temp = temp->prev;
    //     }  
    //     cout << endl;      
    // }

    void ShowForward(){
        Node<T> *temp = head;
        while(temp != nullptr){
            cout << temp->element << " - ";
            temp = temp->next;
        }  
        cout << endl;   
    }

    void AddNodeFirst(T value){
        // add a new node at the beginning of the list i.e. new node will become the new head
        if(IsEmpty()){
            head = new Node<T>(value);
            tail = head;
        }
        else{
            head->prev = new Node<T>(value);
            head->prev->next = head;
            head = head->prev;
        }
    }
    
    // void AddNode(int index, T nodeValue){
    //     // add a new node at position index containing nodeValue
    //     int sz = Size();
    //     if(index == 0){
    //         AddNodeFirst(nodeValue);
    //     }
    //     else if(index == sz - 1){
    //         AddNodeLast(nodeValue);
    //     }
    //     else if(index < sz && !(index < 0)){
    //         // find the item currently at index first
    //         Node* temp = head;
    //         for(int i = 0; i < index; i++){
    //             temp = temp->next;
    //         }

    //         //cout << temp->element << endl;
    //         Node* oldPrev = temp->prev;
    //         Node* newNode = new Node(nodeValue);
    //         temp->prev->next = newNode;
    //         temp->prev = newNode;
    //         newNode->next = temp;
    //         newNode->prev = oldPrev;
    //     }
    //     else{
    //         cout << "Index out of bounds" << endl;
    //     }
    // }
    int Length(){
        int count = 0;
        Node<T> *current = head;
        while(current != nullptr){
            count++;
            current = current->next;
        }
        return count;
    }
    T Get(int index){
        int len = Length();

        if(IsEmpty() || index < 0 || index >= Length()){
            cout << "Invalid index or empty list. Returning 0 as an arbitrary value\n";
            return 0;
        }

        int i = 0;
        Node<T> *temp = head;
        while(i < index){
            temp = temp->next;
            i++;
        }
        return temp->element;
    }


    // removes the first node in the linked list
    // and returns the value inside that node
    T RemoveFirst(){
        if(IsEmpty()){
            cout << "nothing to remove returning 0 as a dummy value\n";
            return 0;
        }
        else{
            if(head == tail && head != nullptr){
                T val = head->element;
                delete head;
                head = tail = nullptr;
                return val;
            }
            else{
                Node<T> *toRemove = head;
                T val = toRemove->element;
                head = head->next;
                toRemove->next = nullptr;
                delete toRemove;
                return val;
            }
        }
    }

    // removes the last node in the linked list and returns its value
    // T RemoveLast(){
    //     if(IsEmpty()){
    //         cout << "nothing to remove returning 0 as a dummy value\n";
    //         return 0;
    //     }
    //     else{
    //         if(head == tail && head != nullptr){
    //             T val = head->element;
    //             delete head;
    //             head = tail = nullptr;
    //             return val;
    //         }
    //         else{
    //             Node* beforeTail = head;
    //             while(beforeTail->next != tail){
    //                 beforeTail = beforeTail->next;
    //             }

    //             beforeTail->next = nullptr;
    //             T val = tail->element;
    //             delete tail;
    //             tail = beforeTail;
    //             return val;
    //         }
    //     }
    // }

    // int Remove(int index){
    //     // // remove node at given index and return the value removed
    // }

    // void Swap(int index1, int index2){
    //     // validate indices first
    //     // swap nodes at indices index1 and index2
    //     // Rewire connections (prev and next links) to swap
    //     // do NOT use a temporary variable to swap
    // }

    // void QuickSort(){

    // }

    // void MergeSort(){

    // }

    // int FirstIndexOf(int item){
    //     // returns first index of item in list
    // }

    // int LastIndexOf(int item){
    //     // returns last index of item in list
    // }
};

#endif