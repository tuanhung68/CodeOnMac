// create a header file named DynamicArra.h
#include <cstdlib>
#include <ctime>
#include <iostream>

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAd_H

using namespace std;

class DynamicArray{
public:
    int size;
private:
    int *array;
    
public:
    // constructor
    // default constructor, no parameter
    DynamicArray(){
        size = 0;
        array = nullptr;
        // nullptr is 0 for addresses
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
        // allocate memory for array wit size elements
        size = n;
        
    }
    void Show(){
        // Display the contents of the array on a line
        for(int i = 0; i < size; i++){
            cout << array[i] << " ";
        } 
        cout << endl;
    }

};

#endif

