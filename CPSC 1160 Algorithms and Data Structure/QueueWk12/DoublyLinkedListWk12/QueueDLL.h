#include "LinkedList.h"
#include <iostream>

using namespace std;

#ifndef QUEUEDLL_H
#define QUEUEDLL_H
template<typename T>
class QueueDLL{
private:
    LinkedList<T> items;
    int capacity;
    T *removedItem;
public:
    // constructor
    QueueDLL(){
        capacity = 5;
        *removedItem = 0;
    }
    /**
     * @brief remove the first item of the queue
     */
    void Dequeue(){
        *removedItem = items.RemoveFirst();
    }
    /**
     * @brief enqueue a new item from back of the queue
     * 
     * @param value : int the value of the item
     */
    void Enqueue(T value){
        int len = items.Length();
        if(len < capacity){
            items.AddNodeLast(value);
        }
        else{
            // find the smallest value in the queue and its index
            T smallest = numeric_limits<T>::max();
            // cout << "The smallest value: " << smallest << endl;
            int indexSmallest = 0;
            for(int i = 0; i < capacity; i++){
               if(items.Get(i) < smallest){
                  smallest = items.Get(i);
                  indexSmallest = i;
              }
            }
            // cout << "The smallest value is " << smallest << " at index " << indexSmallest << endl;
            // cout << "The items are removed: ";
            for(int i = 0; i < indexSmallest; i++){
                Dequeue();
                // cout << *removedItem << "-";
                items.AddNodeLast(*removedItem);
            }
            Dequeue();
            for(int i = 0; i < len - indexSmallest - 1; i++){
                Dequeue();
                items.AddNodeLast(*removedItem);
            }
            items.AddNodeLast(value);
        }
    }
    /**
     * @brief check if the queue is empty or not
     * 
     * @return true : if the queue is empty
     * @return false : if the queue is not empty
     */
    bool IsEmpty(){
        if(items.Length() == 0)
            return true;
        return false;
    }
    /**
     * @brief Show all values that exist in the queue
     */
    void Display(){
        items.ShowForward();
    }
};

#endif
