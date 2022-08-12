#include <cstdlib>
#include <ctime>

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

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
        // create an array with n elements
        // ech element has value 0
    }


};

#endif

