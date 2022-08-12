#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Sortings.h"

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

using namespace std;

class DynamicArray{
public:
    int size;
private:
    int* array;

public:
    // constructors
    // default constructor
    DynamicArray(){
        size = 0;
        array = nullptr;
    }

    // defined constructor, takes parameters / arguments
    DynamicArray(int n){
        // set n to size
        // allocate memory for n integers and set it to array
        // each element has value 0
        size = n;
        array = new int[size];
        for(int i = 0; i < size; i++){
            array[i] = 0;
        }
    }

    DynamicArray(int n, int min, int max){
        // set n to size
        // allocate memory for array with size elements
        // each element is a random integer between min and max (both inclusive)
        srand(time(0));

        size = n;
        array = new int[size];
        for(int i = 0; i < size; i++){
            array[i] = GenerateRandom(min, max);
        }
    }

    // destructor
    ~DynamicArray(){
        if(array){
            delete[] array;
            array = nullptr; 
        }      
    }

    void Show(){
        // displays contents of array on a line
        for(int i = 0; i < size; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }
public:
//private:
// private methods are for class maintenance purposes (used inside the class' body)
    int GenerateRandom(int min, int max){
        // returns a random integer between min and max (both inclusive)
        int random = rand()%(max-min+1) + min;
        return random;
    }
//  week7's homework
    bool ValidateIndex(int index){
       if(index < 0 || index >= size){
            cout << "This is an invalid index. Exit!" << endl;
            cout << "The random value is " << GenerateRandom(0, 9) << endl; 
            return false;
        }
         //int random = GenerateRandom(0, size - 1);
        return true;
        
    }
    // deallocate memory for used array
    void FreeUpMemory(int *arr){
        if(arr){
            delete[] arr;
        }
    }
    /** 1)
     * @brief add an item at an arbitrary index
     * 
     * @param item: int an random number we want to input 
     * @param index: int an random number we want to put the item in, and the index must be between(0, size - 1).
     * let n be the size of the function
     * let m be the index value
     * f(n) = 1 + n + 1 + 2n + 5n = 8n + 2
     * i do not count the if statement because it is just a constant
     * (i = 0) = 1, i < index = n + 1, i++ = 2n, 5n
     * i do not count the second loop because it is also the same as the first loop, 
     * so we can ignore one.
     * I ignore the rest because they are just assignment statements
     * O(f(n)) = O(n)
     * I ignore 2 because it is a non-dominant term
     * I remove 8 because it is just a constant.
     */
    void Add(int item, int index){
        if(ValidateIndex(index) == false){
            return;
        }
        // allocate a new array with a new size 
        // copy elements from old array
        // free up memory the old array
        // set the new array to the old array
        int *tempArray = new int[size + 1];
        for(int i = 0; i < index; i++){
            tempArray[i] = array[i];
        }
        for(int i = size; i > index; i--){
            tempArray[i] = array[i - 1];
        }
        tempArray[index] = item;
        size += 1;
        FreeUpMemory(array);
        array = tempArray;
        
    }
    /**
     * @brief add a random number at the first index 
     * 
     * @param item: int a random number we want to add
     * 
     * let n be the size of the array 
     * i do not count this int *tempArray = new int[size + 1] because it is not a dominant term.
     * f(n) = 1 + n + 1 + 2n + 6n = 9n + 2
     * (int i = size) = 1, (i >= 1) = n + 1, i-- = 2n, (tempArray[i] = array[i - 1]) = 6n
     * i am not counting the rest because they are just assignment statements
     * O(f(n)) = O(n)
     * I remove 9 because it is just a constant
     * I remove 2 because it is a non-dominant term.
     */
    
    void AddFirst(int item){
        int *tempArray = new int[size + 1];
        for(int i = size; i >= 1; i--){
            tempArray[i] = array[i - 1];
        }
        tempArray[0] = item;
        size += 1;
        FreeUpMemory(array);
        array = tempArray;
    }
    /**
     * @brief add a random number at the last index 
     * 
     * @param item : int a random number that we want to add 
     * let n be the size of the array
     * f(n) = 1 + n + 1 + 2n + 5n = 8n + 2
     * I ignore the first statement because it is just a assignment statement.
     * (int i = 0) = 1,(i < size) = n + 1, i++ = 2n, (tempArray[i] = array[i]) = 5n
     * O(f(n)) = O(n)
     * I ignore 2 because it is a non-dominant term
     * I remove 8 because it is just a constant.
     */
    void AddLast(int item){
        int *tempArray = new int[size + 1];
        for(int i = 0; i < size; i++){
            tempArray[i] = array[i];
        }
        size += 1;
        tempArray[size - 1] = item;
        FreeUpMemory(array);
        array = tempArray;
    }
    /**
     * @brief add elements from a new array to the array, starts at index
     * 
     * @param index : int the starting index, where the first element of the new array comes in
     * @param newItems : int the new array
     * @param newItemsSize : int the size of the new array
     * Let n be the size of the array
     * let m be the size of the new array
     * let a be the value of the index
     * f(n) = 1 + m + 1 + 2m + 1 + n + 1 - a + 2(n - a) + 5(n - a) + m + 1 + 2m + 6m
     *      = 12m + 8n - 8a + 5
     * The first loop i < newItemsSize = m + 1, i++ = 2m, I ignore this one (newItems[i] = GenerateRandom(0, 9)) because it happens m times.
     * THe second loop (i < size - index) = n + 1 - a, i++ = 2(n - a), (tempArray[i] = array[i]) = 5(n - a)
     * The third loop (i < index + newItemsSize) = m + 1, i++ = 2m, (tempArray[i] = newItems[i - index]) = 6m
     * I ignore the fourth loop because it is pretty much them as the other loops.
     * I ignore the rest because they are not important, O(1)
     * O(n + m)
     * I ignore 12 and 8 because they are just constants
     * I ignore -8a + 5 because they are non-dominant terms
     */
    void Add(int index, int *newItems, int newItemsSize){
        if(ValidateIndex(index) == false){
            return;
        }
        newItems = new int[newItemsSize];
        for(int i = 0; i < newItemsSize; i++){
            newItems[i] = GenerateRandom(0, 9);
        }
        // allocate a new array with the size of old array + new array

        int *tempArray = new int[size + newItemsSize];
        for(int i = 0; i < size - index; i++){
            tempArray[i] = array[i];
        }
        for(int i = index; i < index + newItemsSize; i++){
            // i - index = 0, 1, 2, 3, 4, 5 get value from index 0 to 5
            tempArray[i] = newItems[i - index];
            cout << i - index << " "<< newItems[i - index] << endl;
        }
        size += newItemsSize;
        for(int i = index + newItemsSize; i < size; i++){
            tempArray[i] = array[i - newItemsSize];
        }
        FreeUpMemory(array);
        array = tempArray;
    }
    /**
     * @brief remove an item at an specific index 
     * 
     * @param index : int index of an item is removed.
     * @return int : the removed item
     * let n be the size of the array
     * let m be the value of the index
     * f(n) = 1 + n + 1 + 2n + 5n = 8n + 2 
     * I am not counting the if statement and this statement int *tempArray = new int[size - 1] 
     * because they are just assignment statements.
     * I am only counting the first for loop, and i am ignoring the rest because are not important
     * (i < index) = n + 1, i++ = 2n, (tempArray[i] = array[i]) =  5n 
     * O(f(n)) = O(n)
     * I ignore 2 because it is a non-dominant term
     * I remove 8 because it is just a constant.
     */
    int Remove(int index){
        if(ValidateIndex(index) == false){
            return -1;
        }
        int *tempArray = new int[size - 1];
        int removedItem = array[index];
        for(int i = 0; i < index; i++){
            tempArray[i] = array[i];
        }
        
        for(int i = index + 1; i < size; i++){
            tempArray[i - 1] = array[i];
        }
        size -= 1;

        FreeUpMemory(array);
        array = tempArray;
        return removedItem;
    }
    /**
     * @brief remove the first item of an array, which is at index 0
     * 
     * @return int : the removed item
     * 
     * f(n) = 1 + n + 2(n - 1) + 6n = 9n - 1
     * I am only counting the loop because it is the dominant term
     * I am ignoring the rest because they are just assignment statements, which occur O(1)
     * (i < size) = n, i++ = 2(n - 1), (tempArray[i - 1] = array[i]) = 6n
     * O(f(n)) = O(n) 
    * I ignore 1 because it is a non-dominant term
     * I remove 9 because it is just a constant.
     */
    int RemoveFirst(){
        int removedItem = array[0];
        int *tempArray = new int[size - 1];
        for(int i = 1; i < size; i++){
            tempArray[i - 1] = array[i];
        }
        size -= 1;
        FreeUpMemory(array);
        array = tempArray;
        return removedItem;
    }
    /**
     * @brief remove the last item of an array, which is at index (size - 1)
     * 
     * @return int : the item that we want it to be removed
     * let n be the size of the array
     * f(n) = 1 + n + 2(n - 1) + 5(n - 1) = 8n - 6
     * (i = 0) = 1, (i < size - 1) = n , i++ = 2(n - 1), (tempArray[i] = array[i]) = 5(n - 1)
     * I am not counting the rest because they are non-dominant terms
     * O(f(n)) = O(n)
     * I ignore 6 because it is a non-dominant term
     * I remove 8 because it is just a constant.
     */
    int RemoveLast(){
        int *tempArray = new int[size - 1];
        int removedItem = array[size - 1];
        for(int i = 0; i < size - 1; i++){
            tempArray[i] = array[i];
        }
        size -= 1;
        FreeUpMemory(array);
        array = tempArray;
        return removedItem;
    }
    /**
     * @brief remove a range of items in array from index 1 to index2 (both inclusive)
     * 
     * @param index1 the starting index to be removed, it must be less than or equal to index 2
     * @param index2 the last index to be removed
     * let n be the size of the array
     * let a be the value of index1
     * let b be the value of index2
     * f(n) = a + 1 + 2a + 5a + n + 1 - a + 2(n - a) + 8(n - a)
     *      = 11n - 3b + 2
     * The first loop i do not count this one because it is pretty much the same with the other loops.
     * The second loop (i < index1) = a + 1, i++ = 2a, (tempArray[i] = array[i]) = 5a
     * THe third loop (i < size) =  n + 1 - a, i++ = 2(n - a), 
     * (tempArray[i] = array[index2 + 1 + i - index1]) = 8(n - a)
     * I ignore the rest because they are just non-dominant terms.
     * i am not counting the rest because they are not important
     * O(f(n)) = O(n)
     * I ignore 11 because it is just a constant.
     * I ignore -3b + 2 because they are non-dominant terms.
     */
    void Remove(int index1, int index2){
        cout << "The value at index " << index1 << " is " << array[index1] << endl;
        cout << "The value at index " << index2 << " is " << array[index2] << endl;
        if((ValidateIndex(index1) || ValidateIndex(index2)) == false && 
        index1 > index2){
            return;
        }
        int random = GenerateRandom(0, 10);
        cout << "The random value is " << random << endl;
        

        int *tempArray = new int[size -(index2 - index1 + 1)];
        // Removes all items between index1 and index2(both inclusive)
        cout << "Items will be removed are: ";
        for(int i = index1; i <= index2; i++){
            cout << array[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < index1; i++){
            tempArray[i] = array[i];
        }
        size -= (index2 - index1 + 1); 
        for(int i = index1; i < size; i++){
            tempArray[i] = array[index2 + 1 + i - index1];
        }
       FreeUpMemory(array);
        array = tempArray;

    }
    /**
     * @brief sort all items between index1 and index2 (both inclusive) in ascending order in array, keep other items the same positions
     * @param index1 : int the starting index, it must be less than or equal to index 2
     * @param index2 : the ending index
     * let n be the size of the array
     * let a be the value of index1
     * let b be the value of index2
     * f(n) = 1 + (b - a + 2) + 6(b - a + 1) + 4(b - a + 1) + nlog(n)
     *      = 11b -11a + 13 + nlog(n)
     * i am only counting the first for loop of the quick sort
     * (in i = 0) = 1, i < length = (b - a + 2), 
     * (values[i] = array[index1 + i]) = 6(b - a + 1), (cout << values[i] << " ") = 4(b - a + 1)
     * QuickSort(values, length) = nlog(n)
     * I ignore the rest because they are just non-dominant terms
     * O(f(n)) = O(nlog(n))
     * I ignore 11b - 11a + 13 because they are non-dominant terms
     */
    void Sort(int index1, int index2){
        cout << "The value at index " << index1 << " is " << array[index1] << endl;
        cout << "The value at index " << index2 << " is " << array[index2] << endl;
        if((ValidateIndex(index1) || ValidateIndex(index2)) == false && 
            index1 > index2){
            return;
        }
        int random = GenerateRandom(0, 10);
        cout << "The random value is " << random << endl;
        int length = index2 - index1 + 1;
        int *values = new int[length];
        for(int i = 0; i < length; i++){
            values[i] = array[index1 + i];
            cout << values[i] << " ";
        }
        cout << endl;
        // using quicksort to sort the new array from index1 to index2
        QuickSort(values, length);
        for(int i = 0; i < length; i++){
            cout << values[i] << " ";
        }
        cout << endl;
        // After sorting, set those to the array with new position
        for(int i = index1; i <= index2; i++){
            array[i] = values[i - index1];
        }
        FreeUpMemory(values);
        values = nullptr;
        
    }
};

#endif

