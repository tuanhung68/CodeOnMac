#include <cstdlib>
#include <ctime>
#include <iostream>

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
        srand(time(0));
        // set n to size
        // allocate memory for array with size elements
        // each element is a random integer between min and max
        size = n;
        array = new int [size];
        for(int i = 0; i < size; i++){
            array[i] = rand() % (max - min + 1) + min;
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

};

#endif

