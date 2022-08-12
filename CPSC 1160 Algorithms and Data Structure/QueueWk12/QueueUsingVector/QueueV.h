#include <iostream>
#include <vector>
#include <climits>
using namespace std;

template<typename T>
class QueueV{
private:
    vector<T> items; 
    int capacity;
    T *removedItem;
public:
    // constructor
    QueueV(){
        capacity = 5; 
        *removedItem = 0;
    }
    // size of the items
    int size(){
        return items.size();
    }
    
    /**
     * @brief remove the first element of the queue
     */
    void Dequeue(){
        *removedItem = *items.begin();
        items.erase(items.begin());
    }
    /**
     * @brief enqueue a new item from back of the queue
     * 
     * @param item : int the value of the item
     */
    void Enqueue(T item){
        if(size() < capacity){
            items.push_back(item);
        }
        else{
            T smallest = numeric_limits<T>::max();
            int indexSmallest = 0;
            for(int i = 0; i < capacity; i++){
               if(items[i] < smallest){
                  smallest = items[i];
                  indexSmallest = i;
              }
            }
            for(int i = 0; i < indexSmallest; i++){
                Dequeue();
                items.push_back(*removedItem);
            }
            Dequeue();
            for(int i = 0; i < size() - indexSmallest; i++){
                Dequeue();
                items.push_back(*removedItem);
            }
            items.push_back(item);
        }
    }    
    /**
     * @brief check the the queue is empty or not
     * 
     * @return true : if there are no items
     * @return false : if there are items 
     */
    bool IsEmpty(){
        if(size() == 0)
            return true;
        return false;
    }   
    /**
     * @brief show all the items of the queue from front to rear
     */
    void Display(){
        for(int i = 0; i < size(); i++){
            cout << items[i] << " ";
        }
        cout << endl;
    }
    



};
